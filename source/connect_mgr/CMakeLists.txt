cmake_minimum_required(VERSION 3.2)
project(
    connect_mgr 
    VERSION 0.0.0.1
    LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)


aux_source_directory(. DIR_SRCS)

add_library(${PROJECT_NAME} ${DIR_SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

#set(${PROJECT_DEVELOP_NAME}_SERVER_SOURCE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Server/Include" CACHE INTERNAL "${PROJECT_DEVELOP_NAME} Server Source Code Root")
#SET_TARGET_PROPERTIES(${PROJECT_NAME}  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${${PROJECT_DEVELOP_NAME}_SERVER_SOURCE_ROOT}/../Lib")

#set_target_properties(${PROJECT_NAME}  PROPERTIES CMAKE_LIBRARY_OUTPUT_DIRECTORY "E:/crucis_proto.git/.cmake_build_vs/e190ad20-40bf-6333-888e-f31b90ceef0d/build/x64-Debug/lib/Debug")

#set_target_properties(${PROJECT_NAME}  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "E:/crucis_proto.git/.cmake_build_vs/e190ad20-40bf-6333-888e-f31b90ceef0d/build/x64-Debug/lib/Debug")

