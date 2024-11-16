project(test_bit_manipulation)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)
enable_testing()
add_executable(test_bit_manipulation
        test_basic_bit_operations.cpp
        test_insert_bit_sequence_into_bitstring.cpp
        test_find_unique_numbers_in_arrays.cpp
        test_counting_bits.cpp
        test_sort_according_to_hamming_weight.cpp
        test_find_original_array_XOR.cpp
        test_integer_division.cpp
        test_bitwise_and_numbers_in_range.cpp
        test_count_operations_to_make_xor_of_array_equal_k.cpp
        test_sum_all_xor_subsets.cpp
        test_find_two_singular_elements.cpp
        test_find_longest_substring_with_even_vowl_count.cpp
        test_xor_queries_for_subarrays.cpp
        test_can_array_be_sorted.cpp
        test_longest_combination_with_bitwise_and.cpp)


target_link_libraries(test_bit_manipulation ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)