cmake_minimum_required(VERSION 3.2)
project(
    services 
    VERSION 0.0.0.1
    LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)
aux_source_directory(./crucis SUB_SRCS)
aux_source_directory(./cof_proto_desc SUB_SRCS2)

add_library(${PROJECT_NAME} ${DIR_SRCS} ${SUB_SRCS} ${SUB_SRCS2})

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIR})
