if (NOT Protobuf_FOUND)
    message(STATUS " 开始搜索 protobuffer 库 ")

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
    find_package(Protobuf 3.0.0 REQUIRED)
    if (NOT Protobuf_FOUND)
        message(FATAL_ERROR "无法找到 Protobuf 库")
    endif()
endif()
