cmake_minimum_required(VERSION 3.16)

project(cache_latency_benchmark
        VERSION 1.0
        LANGUAGES CXX
)

add_executable(cache_latency
        cache_latency_laptop.cpp
)

target_compile_features(cache_latency PRIVATE cxx_std_20)

target_compile_options(cache_latency PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

# This benchmark is intended to measure the local CPU.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(cache_latency PRIVATE
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-march=native>
            $<$<CONFIG:Release>:-DNDEBUG>
    )
endif()