## 检查 lzo 库
if (NOT LZO_FOUND)
    message(STATUS " 开始搜索 lzo 库 ")

    find_package(lzo REQUIRED)
    if (NOT LZO_FOUND)
        message(FATAL_ERROR "无法找到 lzo 库")
    endif()
endif()
