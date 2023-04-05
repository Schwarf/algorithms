cmake_minimum_required(VERSION 3.24)
project(bit_manipulation)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

add_executable(bit_manipulation main.cpp
        basic_bit_operations.h)
