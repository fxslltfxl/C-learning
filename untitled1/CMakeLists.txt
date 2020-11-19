cmake_minimum_required(VERSION 3.14)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

#boost库所在的根目录
set(BOOST_ROOT "/usr/local/include/boost")
#添加头文件搜索路径
include_directories(/usr/local/include)
#添加库文件搜索路径
link_directories(/usr/local/lib)

add_executable(untitled1 main.cpp test.cpp test.h)

# 目标进行链接
target_link_libraries(untitled1 boost_system)
