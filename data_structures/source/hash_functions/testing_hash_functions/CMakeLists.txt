project(hash_function_tests)
cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)

add_executable(test_hash_functions test_hash_function_for_pairs.cpp)
enable_testing()

target_link_libraries(test_hash_functions ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)