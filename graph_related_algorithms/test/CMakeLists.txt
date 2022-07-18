cmake_minimum_required(VERSION 3.21)
project(graph_related_algorithms)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(test_depth_first_search
        depth_first_search/test_size_of_largest_island.cpp test_main.cpp)

target_link_libraries(test_depth_first_search ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
