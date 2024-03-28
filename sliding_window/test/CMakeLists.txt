
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(sliding_window_test
        test_number_of_substrings.cpp
        test_longest_substring_without_repeating_characters.cpp
        test_get_equal_substring_with_budget.cpp test_count_subarrays_with_target.cpp test_find_longest_subarray_with_at_most_k_frequency.cpp)


target_link_libraries(sliding_window_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)