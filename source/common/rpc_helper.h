#ifndef _CRUCIS_RPC_HELPER_H_
#define _CRUCIS_RPC_HELPER_H_
#include <common/generator_id.h>

namespace crucis {

	static std::atomic<uint32_t> next_id_ = 1;

	static void init_id_generator(int data_center,int worker_id)
	{
		auto &id_worker = sequence_id_t::Instance();
		id_worker.setDatacenterId(12);
		id_worker.setWorkerId(5);
	}

	static uint32_t GenerateSequenceId()
	{
		next_id_ = next_id_ + 2;
		return COMM_SEQUENCE_BEGIN + next_id_;
	}

	static uint64_t GetnerateServiceObjectID()
	{
		auto &id_worker = sequence_id_t::Instance();
		return id_worker.nextId();
	}


} // namespace crucis


#endif // _CRUCIS_RPC_HELPER_H_