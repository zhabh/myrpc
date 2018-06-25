if (NOT MARIADBCLIENT_FOUND)
    message(STATUS " 开始搜索 MARIADB CLIENT 库 ")

#    if ( WIN32 AND NOT MINGW)
#        set(Protobuf_INCLUDE_DIR "D:/src/c++/vcpkg/installed/x64-windows/include")
#        if (CMAKE_BUILD_TYPE MATCHES Debug)
#            set(BOOST_LIBRARYDIR "D:/src/c++/vcpkg/installed/x64-windows/debug/lib")
#        else()
#            set(BOOST_LIBRARYDIR "D:/src/c++/vcpkg/installed/x64-windows/lib")
#        endif()
#		set(Protobuf_PROTOC_EXECUTABLE
#    endif()

#	set(Protobuf_PROTOC_EXECUTABLE "D:/src/c++/vcpkg/installed/x64-windows/tools")
    find_package(MariadbClient REQUIRED)
    if (NOT MARIADBCLIENT_FOUND)
        message(FATAL_ERROR "无法找到 MARIADB CLIENT 库")
    endif()
endif()

