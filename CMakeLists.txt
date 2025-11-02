# 要求的最低CMake版本
cmake_minimum_required(VERSION 3.10)

project(MyProject C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(main 
    src/main.c
    src/banner.c
    src/utils.c
)

