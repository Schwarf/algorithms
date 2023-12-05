cmake_minimum_required(VERSION 3.25)
project(2nd)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(../../misc ${CMAKE_CURRENT_BINARY_DIR}/misc)
add_executable(2nd main.cpp)

target_link_libraries(2nd misc)
