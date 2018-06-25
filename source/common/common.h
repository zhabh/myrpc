#ifndef _CRUCIS_RPC_COMMON_H_
#define _CRUCIS_RPC_COMMON_H_
#include <google/protobuf/stubs/common.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "boost/asio.hpp"
#include <common/ptime.h>

namespace crucis {

// RpcEndpoint is a tuple <host:port>.
typedef boost::asio::ip::tcp::endpoint RpcEndpoint;

typedef enum
{
	NORMAL = 0,
	GATE_WAY = 1,
	MQ = 2,
} eServerType;

#define INVALID_SERVICE_ID 0
#define RPC_SVR_PORT 18669 
#define MAX_RPC_CONNECTIONs 1024

#define MAX_RPC_SERVICEs 2048
#define MAX_SERVICE_METHODs 2048

/////////////// types /////////////
typedef ::google::protobuf::uint uint;

typedef ::google::protobuf::int8  int8;
typedef ::google::protobuf::int16 int16;
typedef ::google::protobuf::int32 int32;
typedef ::google::protobuf::int64 int64;

typedef ::google::protobuf::uint8  uint8;
typedef ::google::protobuf::uint16 uint16;
typedef ::google::protobuf::uint32 uint32;
typedef ::google::protobuf::uint64 uint64;

#define CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(TypeName)    \
    TypeName(const TypeName&);                       \
    void operator=(const TypeName&)

// auto console = spdlog::stderr_logger_mt("console");
#define LOG_SPD console

} // namespace crucis

#endif // _CRUCIS_RPC_COMMON_H_