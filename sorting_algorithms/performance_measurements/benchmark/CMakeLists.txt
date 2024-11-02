project(benchmark_sorting_algos)

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(sort_benchmark benchmark.cpp)

target_link_libraries(sort_benchmark benchmark::benchmark)