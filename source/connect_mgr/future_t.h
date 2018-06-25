#ifndef _CRUCIS_FUTURE_T_H_
#define _CRUCIS_FUTURE_T_H_

#include <string>
#include <boost/fiber/all.hpp>

namespace crucis {

	class PromiseResponse {
	public:
		// called if the operation succeeds
		virtual void success(std::string const& data) {
			promise_.set_value(data);
		}

		// called if the operation fails
		virtual void error(int ec) {
		}

		boost::fibers::future< std::string > get_future() {
			return promise_.get_future();
		}

	private:
		boost::fibers::promise< std::string >   promise_;
	};

} // namespace crucis

#endif // _CRUCIS_FUTURE_T_H_
