#include(ExternalProject)
#
#ExternalProject_Add(
#    toluapp
#    GIT_REPOSITORY https://github.com/LuaDist/toluapp
#    GIT_TAG 1.0.93
#    INSTALL_DIR ${CRUCIS_PROJECT_ROOT}/tmp/install
#    CMAKE_ARGS
#        -DCMAKE_INSTALL_PREFIX=${CRUCIS_PROJECT_ROOT}/tmp/install
#        -DBUILD_TESTS:BOOL=OFF
#        -DBUILD_DOCS:BOOL=OFF
#)

## 检查 Behaviac 行为树库
if (NOT Behaviac_FOUND)
    message(STATUS " 开始搜索 Behaviac 行为树库 ")

    find_package(Behaviac REQUIRED)
    if (NOT Behaviac_FOUND)
        message(FATAL_ERROR "无法找到 Behaviac 行为树库")
    endif()
endif()

## 检查 flatbuffers
if (NOT flatbuffers_FOUND)
    message(STATUS " 开始搜索 Flatbuffers ")

    find_package(flatbuffers REQUIRED)
	if (NOT flatbuffers_FOUND)
        message(FATAL_ERROR "无法找到 Flatbuffers")
    endif()
	message(STATUS "flatbuffers library is " ${flatbuffers_LIBRARIES})
endif()
