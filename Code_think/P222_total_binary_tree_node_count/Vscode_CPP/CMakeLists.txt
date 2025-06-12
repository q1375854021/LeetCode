cmake_minimum_required(VERSION 3.15)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译器路径
set(CMAKE_C_COMPILER "D:/Software/Extensions/Mingw/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Software/Extensions/Mingw/mingw64/bin/g++.exe")

# 设置exe生成路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)


#设置CMAKE包含当前工作目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#包含头文件目录和库文件路径
include_directories(${CMAKE_SOURCE_DIR})    #包含CMAKE工作路径
include_directories(Header)
include_directories(Source)

# 添加可执行文件（需在设置编译选项前定义main）
add_executable(main source/main.cpp   
)


# ！！！添加代码开始 ！！！
# 设置默认构建类型为 Debug（仅对单配置生成器有效，如Unix Makefiles）
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 根据不同构建类型设置编译选项
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(main PRIVATE
        -g      # 生成调试符号
        -O0     # 禁用优化
    )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(main PRIVATE
        -O3     # 最大优化
        -DNDEBUG  # 禁用断言（如assert()）
    )
endif()
# ！！！添加代码结束 ！！！



# 可选的附加依赖或文件头路径
# target_link_libraries(main ...)
# target_include_directories(main ...)
