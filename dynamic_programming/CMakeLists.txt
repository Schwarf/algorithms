cmake_minimum_required(VERSION 3.22)
project(dynamic_programming_samples)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./)

add_executable(dynamic_programming_samples main.cpp)
include_directories(test)