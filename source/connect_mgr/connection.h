#ifndef _CRUCIS_CONNECTION_H_
#define _CRUCIS_CONNECTION_H_

#include <array>
#include <boost/asio.hpp>
#include <boost/fiber/all.hpp>
#include <common/yield.hpp>

namespace crucis {

using boost::asio::ip::tcp;

class connection_manager;
class RpcServiceMgr;
class ReaderBuff {};


/// Represents a single connection from a client.
class connection
  : public std::enable_shared_from_this<connection>
{
public:
  connection(const connection&) = delete;
  connection& operator=(const connection&) = delete;

  /// Construct a connection with the given socket.
  explicit connection(boost::asio::ip::tcp::socket socket,
      connection_manager& manager, RpcServiceMgr& rpc_service_mgr);

  tcp::socket& socket() {
	  return socket_;
  }

  /// Start the first asynchronous operation for the connection.
  void start();

  /// Stop all asynchronous operations associated with the connection.
  void stop();

private:
  /// Perform an asynchronous read operation.
 /* void do_read();*/

  /// Perform an asynchronous write operation.
	void do_write(std::string const& msg);

	void do_work(const char * req, size_t length);

  /// Socket for the connection.
  tcp::socket socket_;

  /// The manager for this connection.
  connection_manager& connection_manager_;

  RpcServiceMgr& rpc_service_mgr_;

  char head_buff_[4];

  /// Buffer for incoming data.
  char buffer_[8192];

  ReaderBuff read_buff_;

};

typedef std::shared_ptr<connection> connection_ptr;

} // namespace crucis

#endif // _CRUCIS_CONNECTION_H_
