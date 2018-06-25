if (NOT Boost_FOUND)
    message(STATUS " 开始搜索 boost 库 ")

    ## 设置 boost 库编译选项
	set(BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE	ON)
    set(Boost_USE_MULTITHREADED      ON)
    # set(Boost_USE_STATIC_LIBS       ON)  # only find static libs
    set(Boost_USE_STATIC_LIBS       ON)  # only find static libs
    set(Boost_USE_STATIC_RUNTIME    ON)

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(Boost_USE_DEBUG_LIBS    ON) # ignore debug libs and
        set(Boost_USE_RELEASE_LIBS  OFF)  # only find release libs
    else()
        set(Boost_USE_DEBUG_LIBS    OFF) # ignore debug libs and
        set(Boost_USE_RELEASE_LIBS  ON)  # only find release libs
    endif()

    if ( WIN32 AND NOT MINGW)
        ## 设置连接库路径
        ## 判断编译目标的位数，32 or 64
        set(BITNESS 32)
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            set(BITNESS 64)
        endif()

#        set(BOOST_INCLUDEDIR ${CRUCIS_PROJECT_ROOT}/dep/include)
#		 set(BOOST_LIBRARYDIR ${CRUCIS_PROJECT_ROOT}/dep/lib/boost/msvc_${BITNESS})
#        set(BOOST_INCLUDEDIR "D:/src/c++/vcpkg/installed/x64-windows/include")
#        if (CMAKE_BUILD_TYPE MATCHES Debug)
#            set(BOOST_LIBRARYDIR "D:/src/c++/vcpkg/installed/x64-windows/debug/lib")
#        else()
#            set(BOOST_LIBRARYDIR "D:/src/c++/vcpkg/installed/x64-windows/lib")
#        endif()
    endif()
    find_package(Boost 1.6 REQUIRED COMPONENTS system date_time regex context coroutine fiber)
    if (NOT Boost_FOUND)
        message(FATAL_ERROR "无法找到 boost 库")
    endif()
endif()
