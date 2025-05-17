project(test_fun_with_arrays)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)

add_executable(test_fun_with_arrays
        test_contiguous_array.cpp
        test_minimal_operations_to_get_zero.cpp
        test_three_sum_closest.cpp
        test_sum_longest_subarray_with_unique_elements.cpp
        test_longest_common_substring.cpp)

target_link_libraries(test_fun_with_arrays GTest::GTest GTest::Main pthread)
add_test(NAME FunWithArraysTests COMMAND test_fun_with_arrays)


