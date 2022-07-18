cmake_minimum_required(VERSION 3.21)
project(test_dynamic_programming_samples)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(test_dynamic_programming_samples
        test_min_costs_to_reach_end.cpp)

target_link_libraries(test_dynamic_programming_samples ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
