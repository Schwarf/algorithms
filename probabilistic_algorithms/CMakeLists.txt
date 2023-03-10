cmake_minimum_required(VERSION 3.24)
project(probabilistic_algorithms)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(test)

add_executable(probabilistic_algorithms main.cpp reservoir_sampling.h)