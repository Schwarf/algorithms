project(test_dynamic_programming_samples)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(fun_with_strings_test test_remove_duplicates.cpp)
