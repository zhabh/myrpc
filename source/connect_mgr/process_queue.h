#ifndef _CRUCIS_PROCESS_QUEUE_H_
#define _CRUCIS_PROCESS_QUEUE_H_
#include <service_mgr/service_mgr.h>
#include <boost/asio.hpp>
#include <memory>
#include <rpc_server/pb_header.h>
#include <services/service.h>
#include <string>
#include <queue>
#include <set>
#include <common/yield.hpp>

namespace crucis {

using boost::asio::ip::tcp;

class process_session;
typedef std::shared_ptr< process_session > process_session_ptr;

struct process_item
{
	std::string req_;
};

typedef std::shared_ptr< process_item > process_item_ptr;

class process_queue : public std::enable_shared_from_this< process_queue > {
public:
	
	void push(process_item_ptr const& item)
	{
		items_.push(item);
	}

	void pop()
	{
		items_.pop();
	}
	
	process_item_ptr front()
	{
		if (empty())
		{
			return NULL;
		}

		return items_.front();
	}

	process_item_ptr back()
	{
		if (empty())
		{
			return NULL;
		}

		return items_.back();
	}

	bool empty()
	{
		return items_.empty();
	}


private:
	std::queue<process_item_ptr> items_;
};


//class session_container {
//
//public:
//	~session_container();
//
//	void add(uint32 seq_id,process_session_ptr const& s) {
//		std::unique_lock< boost::fibers::mutex > lk(mtx_);
//		pro_sessions_.insert(std::make_pair(seq_id,s));
//	}
//
//	void del(uint32 seq_id) {
//		std::unique_lock< boost::fibers::mutex > lk(mtx_);
//		pro_sessions_.erase(seq_id);
//	}
//
//	process_session_ptr get_item(uint32 seq_id)
//	{
//		std::unique_lock< boost::fibers::mutex > lk(mtx_);
//
//		std::map< uint32, process_session_ptr >::iterator itor = pro_sessions_.find(seq_id);
//		if (itor != pro_sessions_.end())
//		{
//			return itor->second;
//		}
//		return NULL;
//	}
//
//	//通知session完成
//	void finish(uint32 seq_id, std::string const& msg)
//	{
//		//
//		//
//		process_session_ptr pt = get_item(seq_id);
//		if (pt != NULL)
//		{
//			pt->publish(msg);
//		}
//		
//	}
//
//private:
//	boost::fibers::mutex    mtx_;
//	std::map< uint32, process_session_ptr >  pro_sessions_;
//};

class process_session : public std::enable_shared_from_this< process_session > {
public:
	explicit process_session(std::string& str, tcp::socket& socket, RpcServiceMgr & rpc_service_mgr) :
		req_(str),
		socket_(std::move(socket)),
		rpc_service_mgr_(rpc_service_mgr) {
	}

	tcp::socket& socket() {
		return socket_;
	}

	// this function is executed inside the fiber
	void run() {
		try {
			boost::system::error_code ec;
			
			rpc_service_mgr_.DispathReq(req_.c_str(), req_.length(), [this](std::string const& msg) {
				publish(msg);
			}
			);

			//for (;;) {
			//	
			//	std::unique_lock< boost::fibers::mutex > lk(mtx_);
			//	cond_.wait(lk);
			//	std::string data(data_);
			//	lk.unlock();
			//	// message '<fini>' terminates subscription
			//	if ("<fini>" == data) {
			//		break;
			//	}
			//	

			//	unsigned int tLen = data.size();
			//	//if (tLen < 1) return buffers;
			//	char* pLen = (char*)&tLen;
			//	std::string *pMsg = new std::string();
			//	pMsg->append(pLen, sizeof(tLen));
			//	pMsg->append(data);


			//	boost::asio::async_write(
			//		socket_,
			//		boost::asio::buffer(pMsg->c_str(), pMsg->length()),
			//		yield[ec]);
			//	if (ec == boost::asio::error::eof) {
			//		break; //connection closed cleanly by peer
			//	}
			//	else if (ec) {
			//		throw boost::system::system_error(ec); //some other error
			//	}
			//}

		}
		catch (std::exception const& e) {
			std::cerr << "subscriber failed: " << e.what() << std::endl;
		}
		// close socket
		//socket_.close();
		//reg_.unsubscribe(queue, shared_from_this());
	}

	// called from publisher_session (running in other fiber)
	void publish(std::string const& msg) {
		//std::unique_lock< boost::fibers::mutex > lk(mtx_);
		std::memset(data_, '\0', sizeof(data_));
		std::memcpy(data_, msg.c_str(),  msg.size());
		//cond_.notify_all();

		boost::system::error_code ec;
		thread_local boost::fibers::asio::yield_t yield;

		unsigned int tLen = msg.size();
		//if (tLen < 1) return buffers;
		char* pLen = (char*)&tLen;
		std::string *pMsg = new std::string();
		pMsg->append(pLen, sizeof(tLen));
		pMsg->append(msg);

		boost::asio::async_write(
			socket_,
			boost::asio::buffer(pMsg->c_str(), pMsg->length()),
			yield[ec]);
		if (ec == boost::asio::error::eof) {
			//break; //connection closed cleanly by peer
		}
		else if (ec) {
			//throw boost::system::system_error(ec); //some other error
		}
	}

private:
	tcp::socket                         socket_;
	RpcServiceMgr &					rpc_service_mgr_;
	boost::fibers::mutex                mtx_;
	boost::fibers::condition_variable   cond_;
	// fixed size message
	std::string							req_;
	char                                data_[2048];
};


} // namespace crucis

#endif // _CRUCIS_PROCESS_QUEUE_H_
