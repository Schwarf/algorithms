cmake_minimum_required(VERSION 3.25)
project(misc)

set(CMAKE_CXX_STANDARD 20)

add_library(misc INTERFACE)
target_include_directories(misc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
