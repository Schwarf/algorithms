project(benchmark_sorting_algos)

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default to Release build type if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Add optimization flags for Release builds
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(sort_benchmark benchmark.cpp)
add_executable(sort_profiling profiling.cpp)

target_link_libraries(sort_benchmark benchmark::benchmark)
target_compile_options(sort_benchmark PRIVATE $<$<CONFIG:Release>:-O3>)
target_compile_options(sort_profiling PRIVATE $<$<CONFIG:Release>:-O3>)