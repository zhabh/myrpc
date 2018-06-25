#ifndef _CRUCIS_TIMER_WORKER_H_
#define _CRUCIS_TIMER_WORKER_H_

#include <common/common.h>

namespace crucis {

class TimerWorker : public std::enable_shared_from_this<TimerWorker>
{
public:
	typedef boost::function<void(const PTime& /* now */)> WorkRoutine;

public:
	TimerWorker(io_context& io_context)
		: io_context_(io_context)
		, is_running_(false)
		, time_duration_(time_duration_seconds(1))
		, work_routine_(NULL)
		, timer_(io_context_)
		, strand_(io_context_)
	{}

	~TimerWorker()
	{
		SOFA_PBRPC_FUNCTION_TRACE;
		stop();
	}

	bool is_running()
	{
		return is_running_;
	}

	void set_time_duration(const TimeDuration& time_duration)
	{
		time_duration_ = time_duration;
	}

	void set_work_routine(const WorkRoutine& work_routine)
	{
		work_routine_ = work_routine;
	}

	void start()
	{
		if (is_running_) return;
		is_running_ = true;

		std::lock_guard<std::mutex> lock(timer_lock_);
		timer_.expires_from_now(time_duration_);
		timer_.async_wait(strand_.wrap(boost::bind(
			&TimerWorker::on_timeout, shared_from_this(), _1)));
	}

	void stop()
	{
		if (!is_running_) return;
		is_running_ = false;

		std::lock_guard<std::mutex> lock(timer_lock_);
		timer_.cancel();
	}

private:
	void on_timeout(const boost::system::error_code& ec)
	{
		if (is_running_)
		{
			PTime now = ptime_now();

			if (ec != boost::asio::error::operation_aborted && _work_routine)
			{
				work_routine_(now);
			}

			std::lock_guard<std::mutex> lock(timer_lock_);
			timer_.expires_at(now + time_duration_);
			timer_.async_wait(strand_.wrap(boost::bind(
				&TimerWorker::on_timeout, shared_from_this(), _1)));
		}
	}

private:
	boost::asio::io_context & io_context_;
	volatile bool is_running_;

	TimeDuration time_duration_;
	WorkRoutine work_routine_;

	boost::asio::deadline_timer timer_;
	std::mutex timer_mutex_;
	boost::asio::io_context::strand strand_;

	CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(TimerWorker);
}; // class TimerWorker

} // namespace crucis


#endif // _CRUCIS_TIMER_WORKER_H_