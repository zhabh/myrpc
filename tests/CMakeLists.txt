cmake_minimum_required(VERSION 3.2)
project(
    crucis_proto_tests 
    VERSION 0.0.0.1
    LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

#############################################################################
# Catch library with the main function to speed up build
#############################################################################

add_library(${PROJECT_NAME}_main OBJECT
    "test_main.cpp"
)

set(include_dir 
${CRUCIS_PROJECT_ROOT}/source/
${CRUCIS_PROJECT_ROOT}/source/services
${Boost_INCLUDE_DIRS}
)


set_target_properties(${PROJECT_NAME}_main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    COMPILE_DEFINITIONS "$<$<CXX_COMPILER_ID:MSVC>:_SCL_SECURE_NO_WARNINGS>"
    COMPILE_OPTIONS "$<$<CXX_COMPILER_ID:MSVC>:/EHsc;$<$<CONFIG:Release>:/Od>>"
)

target_include_directories(
${PROJECT_NAME}_main PRIVATE 
${include_dir}
)



# https://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()

    # Disable warning C4389: '==': signed/unsigned mismatch
	# Disable warning C4309: 'static_cast': truncation of constant value
	# Disable warning C4566: character represented by universal-character-name '\uFF01' cannot be represented in the current code page (1252)
	# Disable warning C4996: 'nlohmann::basic_json<std::map,std::vector,std::string,bool,int64_t,uint64_t,double,std::allocator,nlohmann::adl_serializer>::operator <<': was declared deprecated
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4389 /wd4309 /wd4566 /wd4996")
endif()

#############################################################################
# one executable for each unit test file
#############################################################################

file(GLOB files "source/unit-*.cpp")
foreach(file ${files})
    get_filename_component(file_basename ${file} NAME_WE)
    string(REGEX REPLACE "unit-([^$]+)" "test-\\1" testcase ${file_basename})

    add_executable(${testcase} $<TARGET_OBJECTS:${PROJECT_NAME}_main> ${file})
    set_target_properties(${testcase} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        COMPILE_DEFINITIONS "$<$<CXX_COMPILER_ID:MSVC>:_SCL_SECURE_NO_WARNINGS>"
        COMPILE_OPTIONS "$<$<CXX_COMPILER_ID:MSVC>:/EHsc;$<$<CONFIG:Release>:/Od>>"
    )

    target_compile_definitions(${testcase} PRIVATE CATCH_CONFIG_FAST_COMPILE)
	include_directories("${CMAKE_CURRENT_LIST_DIR}/../source/")


	set (EXTRA_LIBS ${EXTRA_LIBS} common services service_mgr rpc_server connect_mgr)

    target_include_directories(
		${testcase} PRIVATE 
		${include_dir}
	)

    target_link_libraries(
		${testcase} ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES}  ${Protobuf_LIBRARIES}
		fmt::fmt fmt::fmt-header-only  gRPC::gpr gRPC::grpc gRPC::grpc++
		${EXTRA_LIBS}
	)

    if(NOT MSVC)
        set_target_properties(${testcase} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-float-equal")
    endif()

    add_test(NAME "${testcase}_default"
      COMMAND ${testcase} ${CATCH_TEST_FILTER}
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
    set_tests_properties("${testcase}_default" PROPERTIES LABELS "default")

    add_test(NAME "${testcase}_all"
      COMMAND ${testcase} ${CATCH_TEST_FILTER} "*"
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
    set_tests_properties("${testcase}_all" PROPERTIES LABELS "all")

    if(JSON_Valgrind)
        add_test(NAME "${testcase}_valgrind"
          COMMAND ${memcheck_command} ${CMAKE_CURRENT_BINARY_DIR}/${testcase} ${CATCH_TEST_FILTER}
          WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )
        set_tests_properties("${testcase}_valgrind" PROPERTIES LABELS "valgrind")
    endif()

endforeach()