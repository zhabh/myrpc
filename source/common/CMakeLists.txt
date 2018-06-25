cmake_minimum_required(VERSION 3.2)
project(
    common 
    VERSION 0.0.0.1
    LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

add_library(${PROJECT_NAME} ${DIR_SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})