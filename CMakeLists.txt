cmake_minimum_required(VERSION 3.2)
project(
    crucis_proto 
    VERSION 0.0.0.1
    LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

########################################################################
# CMake 模块 (递归包含模块, 带颜色输出模块, 平台检测模块)
set (PROJECT_CMAKE_MODULE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/ProjectBuildOption.cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/IncludeDirectoryRecurse.cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/EchoWithColor.cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/modules/FindPlatform.cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/ProjectTools.cmake")



#####################################################################
# 导入编译器和编译选项配置
include("${PROJECT_CMAKE_MODULE_DIR}/CompilerOption.cmake")
include("${PROJECT_CMAKE_MODULE_DIR}/TargetOption.cmake")
EchoWithColor(COLOR GREEN "-- Build Type: ${CMAKE_BUILD_TYPE}")

include(CheckCXXCompilerFlag)

###########################################################
# 设置find类模块搜索路径
if (NOT CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH ${PROJECT_CMAKE_MODULE_DIR}/modules)
    message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
endif()

set(CRUCIS_PROJECT_ROOT "${PROJECT_SOURCE_DIR}"  CACHE INTERNAL "CRUCIS PROJECT ROOT")

### 设置缺省构建类型
if (NOT CMAKE_BUILD_TYPE)
    #SET(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_BUILD_TYPE Debug)
endif()


## 检查 Boost 库
include("${PROJECT_CMAKE_MODULE_DIR}/get_boost.cmake")
## 检查 protobuffer 库
 include("${PROJECT_CMAKE_MODULE_DIR}/get_protobuf.cmake")
## 检查 lzo 库
#include("${PROJECT_CMAKE_MODULE_DIR}/get_lzo.cmake")
## 检查 MARIADB 库
# include("${PROJECT_CMAKE_MODULE_DIR}/get_mariadb.cmake")
## 检查 lua 库
# include("${PROJECT_CMAKE_MODULE_DIR}/get_lua.cmake")

## 检查依赖库
# include("${PROJECT_CMAKE_MODULE_DIR}/dependence.cmake")

#if(CMAKE_BUILD_TYPE MATCHES Debug)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
#    list(APPEND CMAKE_CXX_FLAGS_DEBUG ${USER_DEBUG_FLAGS})
#    message(STATUS "Debug compiler flags: ${CMAKE_CXX_FLAGS_DEBUG}")
#else()
#    list(APPEND CMAKE_CXX_FLAGS_DEBUG ${USER_DEBUG_FLAGS})
#    message(STATUS "Debug compiler flags: ${CMAKE_CXX_FLAGS_DEBUG}")
#endif()

## 在MINGW中检测当前设置,是否支持c++11
if (MINGW)
#     CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
#     CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
#     CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

#     message(STATUS "The system is MINGW")
#    if(COMPILER_SUPPORTS_CXX14)
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#    elseif(COMPILER_SUPPORTS_CXX11)
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
#    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#    elseif(COMPILER_SUPPORTS_CXX0X)
#    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
#    else()
#        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
#    endif()

    set(CRUCIS_MINGW 1)
endif()

### vc 下取消一些警告
if(MSVC)
	add_definitions(
    /wd4018 # 'expression' : signed/unsigned mismatch
    /wd4065 # switch statement contains 'default' but no 'case' labels
    /wd4146 # unary minus operator applied to unsigned type, result still unsigned
    /wd4244 # 'conversion' conversion from 'type1' to 'type2', possible loss of data
    /wd4251 # 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
    /wd4267 # 'var' : conversion from 'size_t' to 'type', possible loss of data
    /wd4305 # 'identifier' : truncation from 'type1' to 'type2'
    /wd4307 # 'operator' : integral constant overflow
    /wd4309 # 'conversion' : truncation of constant value
    /wd4334 # 'operator' : result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
    /wd4355 # 'this' : used in base member initializer list
    /wd4506 # no definition for inline function 'function'
    /wd4800 # 'type' : forcing value to bool 'true' or 'false' (performance warning)
    /wd4996 # The compiler encountered a deprecated declaration.
  )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4819 -D_WIN32_WINNT=0x600")
endif(MSVC)

if (NOT gRPC_FOUND)
    message(STATUS " 开始搜索 grpc 库 ")

    find_package(gRPC REQUIRED)

    if (NOT gRPC_FOUND)
        message(FATAL_ERROR "无法找到 grpc 库")
    endif()
endif()

##
## TESTS
## create and configure the unit test target
##
include(CTest) #adds option BUILD_TESTING (default ON)

if(BUILD_TESTING)
	#message(STATUS " 开始搜索 catch2 ")
	#find_package(catch2 REQUIRED)
	#if (NOT catch2_FOUND)
	#	message(FATAL_ERROR "无法找到 catch2")
	#endif()
	#message(STATUS "catch2 library is " ${Boost_INCLUDE_DIRS})

	find_package(fmt REQUIRED)
	enable_testing()
	add_subdirectory(tests)
endif()

find_package(Threads)

include_directories("${PROJECT_SOURCE_DIR}/source/")
add_subdirectory(${PROJECT_SOURCE_DIR}/source/common)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/connect_mgr)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/rpc_server)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/service_mgr)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/services)




