cmake_minimum_required(VERSION 3.20)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(sort main.cpp)
add_subdirectory(algorithms)
include_directories(algorithms)
target_link_libraries(sort sorting_lib)