#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"
#include "social_relations_service.grpc.pb.h"
#include <iostream>
#include <queue>
#include <boost/fiber/all.hpp>


using grpc::Channel;
using grpc::ClientReader;
using grpc::ClientWriter;
using grpc::ClientReaderWriter;
using grpc::ClientAsyncReader;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using RespCb = std::function<void(::google::protobuf::Message * msg)>;

static int kk = 1;
static int ge_unique_id()
{
	return kk++;
}


// struct for keeping state and data information
class IAsyncClientCall {
public:
	virtual void call_back() {};
	virtual ~IAsyncClientCall() {};
	// Context for the client. It could be used to convey extra information to
	// the server and/or tweak certain RPC behaviors.

	grpc::ClientContext & GetContext() { return context_; }
	grpc::Status & GetStatus() { return status_; }
	virtual int get_id() { return 0; }
	virtual bool is_sub_mode() { return false; }
	virtual void push_channel(int id) {};
protected:

	ClientContext context_;
	// Storage for the status of the RPC upon completion.
	Status status_;

};


template <class R>
class AsyncClientCall final : public IAsyncClientCall
{
public:
	typedef std::unique_ptr<ClientAsyncResponseReader<R >> read_ptr;
	typedef std::unique_ptr<ClientAsyncReader<R >> stream_read_ptr;

	AsyncClientCall() :IAsyncClientCall(), is_sub_mode_(false)
	{
		id_ = ge_unique_id();
	}

	virtual ~AsyncClientCall() override 
	{
		
	};

	void call_back()
	{
		cb_(&reply_);
	}

	void SetResponseCb(const RespCb& response_cb) {
		cb_ = response_cb;
	}

	google::protobuf::Message& get_response() { return reply_; }

	int get_id()
	{
		return id_;
	}

	void push_channel(int id)
	{
		if (boost::fibers::channel_op_status::success == c.push(id))
		{
			
		}
	}

	bool is_sub_mode()
	{
		return is_sub_mode_;
	}

	void wait_t()
	{
		int v;
		boost::fibers::fiber f(boost::fibers::launch::dispatch, [&]() {
			if (boost::fibers::channel_op_status::success == c.pop(v))
			{
				std::cout << "recv id = " << v << std::endl;
				call_back();
			}
		});

		f.join();
	}

	void set_ptr_finish(read_ptr pRpc)
	{
		response_reader_.swap(pRpc);
		response_reader_->Finish(&reply_, &status_, (void*)this);

		//std::async(std::launch::async, &AsyncClientCall::wait_t, this);
		//boost::fibers::fiber(
		//	std::bind(&AsyncClientCall::wait_t, this)).detach();

		int v;
		boost::fibers::fiber f(boost::fibers::launch::dispatch, [&]() {
			if (boost::fibers::channel_op_status::success == c.pop(v))
			{
				std::cout << "recv id = " << v << std::endl;
				call_back();
			}
		});

		f.join();
	}

	void set_ptr_finish(stream_read_ptr pRpc)
	{
		is_sub_mode_ = true;
		stream_response_reader_.swap(pRpc);
		stream_response_reader_->StartCall((void*)id_);
		stream_response_reader_->Read(&reply_, (void*)id_);
		{
			std::cout << "\n\n";
		}
		stream_response_reader_->Finish(&status_, (void*)id_);
	}
protected:
	boost::fibers::unbuffered_channel< int > c;
private:
	
	bool is_sub_mode_;
	int id_;
	read_ptr response_reader_;
	stream_read_ptr stream_response_reader_;
	R reply_;
	//google::protobuf::Closure * cb_;
	RespCb cb_;
};


class Session 
{
public:
	Session() {}

	inline int AllocCall(IAsyncClientCall* p)
	{
		std::unique_lock< std::mutex > lk(mtx_);
		int id = p->get_id();
		calls_.insert(std::make_pair(id, p));

		if (id) ncalls_++;
		return id;
	}
	
	void FreeCallId(int call_id) 
	{
		std::unique_lock< std::mutex > lk(mtx_);
		
		std::map< int, IAsyncClientCall* >::iterator itor = calls_.find(call_id);
		if (itor != calls_.end() && !itor->second->is_sub_mode())
		{
			delete itor->second;
			calls_.erase(itor);
			ncalls_--;
		}
		
	}

	IAsyncClientCall* GetCallBack(int call_id)
	{
		std::unique_lock< std::mutex > lk(mtx_);

		std::map< int, IAsyncClientCall* >::iterator itor = calls_.find(call_id);
		if (itor != calls_.end())
		{
			return itor->second;
		}
		return NULL;
	}

	inline void InitSession() {
		ncalls_ = 0;
	}

private:
	int ncalls_;

	std::map<int, IAsyncClientCall* > calls_;
	std::mutex mtx_;

};
