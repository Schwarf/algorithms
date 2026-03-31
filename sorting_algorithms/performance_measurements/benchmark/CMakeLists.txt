project(benchmark_sorting_algos)

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)


# Default to Release build type if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Add optimization flags for Release builds
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(sort_benchmark benchmark.cpp)
add_executable(sort_profiling profiling.cpp)

target_link_libraries(sort_benchmark benchmark::benchmark)
target_compile_options(sort_benchmark PRIVATE $<$<CONFIG:Release>:-O3>)
target_compile_options(sort_profiling PRIVATE $<$<CONFIG:Release>:-O3>)