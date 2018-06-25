#ifndef _CRUCIS_REQUEST_INFO_H_
#define _CRUCIS_REQUEST_INFO_H_

#include <google/protobuf/service.h>
#include <common/common.h>
#include <common/rpc_helper.h>
#include <google/protobuf/message.h>
#include <rpc_server/pb_header.h>

#include <string>

namespace crucis {

	using google::protobuf::Message;

class request_info
{
public:
	request_info():
		service_id_(0),
		method_id_(0),
		msg_type_(0),
		seq_id_(0),
		service_obj_(0)
	{}

	bool Init(unsigned int service_id, int method_id, int msg_type, const Message *request)
	{
		if (service_id < 0 || method_id < 0 || request==NULL)
			return false;

		request->SerializeToString(&content_);

		service_id_ = service_id;
		method_id_ = method_id;
		msg_type_ = msg_type;
		seq_id_ = GenerateSequenceId();
		service_obj_ = 0;
		return true;
	}

	RpcRequestData makeRpcHead(int32_t service,
		int32_t function,
		MessageType type,
		int32_t seqId,
		uint64_t serviceObj,
		std::string * data)
	{
		RpcRequestData head;
		head.set_service_id(service);
		head.set_function(function);
		head.set_type(type);
		head.set_seq_id(seqId);
		head.set_service_object(serviceObj);
		head.set_content(*data);

		return head;
	}

	std::vector<boost::asio::const_buffer> to_buffers(std::string &msg)
	{

		std::vector<boost::asio::const_buffer> buffers;
		std::string *head=new std::string;
		makeRpcHead(service_id_, method_id_, (MessageType)msg_type_, seq_id_, service_obj_, &content_).SerializeToString(head);

		unsigned int tLen = head->size();
		if (tLen < 1) return buffers;

		char* pLen = (char*)&tLen;

		msg.append(pLen, sizeof(tLen));
		msg.append(*head);

		delete head;
		/*buffers.push_back(boost::asio::buffer(pLen, sizeof(tLen)));
		buffers.push_back(boost::asio::buffer(*head));*/

		return buffers;
	}

private:
	unsigned int service_id_;
	int method_id_;
	int msg_type_;
	uint64 seq_id_;
	uint64 service_obj_;
	std::string content_;
};


} // namespace crucis

#endif // _CRUCIS_REQUEST_INFO_H_