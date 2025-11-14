project(test_prefix_sums)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(test_prefix_sums
        test_contiguous_array.cpp
        test_k_radius_subarray_averages.cpp
        test_make_divisible_by_value.cpp
        test_number_of_sub_matrices_that_sum_to_target.cpp
        test_number_of_subarrays.cpp
        test_product_of_array_but_current_index_value.cpp
        test_query_subarrays_with_different_parity_neighbors.cpp
        test_count_subarrays_with_odd_sum.cpp
        test_number_of_valid_triplets.cpp
        test_rob_banks.cpp
        test_plates_between_candles.cpp
        test_find_longest_contiguous_array.cpp
        test_contineous_subarray_sum.cpp
        test_increment_sub_matrices.cpp)

target_link_libraries(test_prefix_sums GTest::GTest GTest::Main pthread)
add_test(NAME PrefixSumsTests COMMAND test_prefix_sums)
