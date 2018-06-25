#ifndef _CRUCIS_TASK_IO_H_
#define _CRUCIS_TASK_IO_H_
#include <stack>
#include <boost/coroutine2/all.hpp>
#include <functional>

namespace crucis {

	typedef boost::coroutines2::coroutine< void* > c_rout;

	using namespace std;

	class coroutine_cell
	{
	public:
		coroutine_cell(std::function<void(void*)> cb):c_(cb)
		{
		}
	private:
		void * arg;
		c_rout::pull_type c_;
	};

	struct task_t
	{
		coroutine_cell *co;
		int fd;
	};

	static stack<task_t*> g_readwrite;


} // namespace crucis

#endif // _CRUCIS_TASK_IO_H_
