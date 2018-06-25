## 检查 lua 库
if (NOT LUA51_FOUND)
    message(STATUS " 开始搜索 lua 库 ")

    find_package(LUA51 REQUIRED)
    if (NOT LUA51_FOUND)
        message(FATAL_ERROR "无法找到 lua 库")
    endif()
endif()

## 检查 toluapp 库
if (NOT TOLUAPP_FOUND)
    message(STATUS " 开始搜索 toluapp 库 ")

    find_package(TOLUAPP REQUIRED)
    if (NOT TOLUAPP_FOUND)
        message(FATAL_ERROR "无法找到 toluapp 库")
    endif()
endif()
