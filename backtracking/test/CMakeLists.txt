project(test_backtracking)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(test_backtracking
        test_generate_all_combinations_of_size_k.cpp
        test_compute_all_permutations.cpp
        test_queens_problem.cpp
        test_path_sum_binray_tree.cpp
        test_letter_combinations_of_phone_numbers.cpp
        test_find_all_summand_combinations_for_sum.cpp
        test_construct_lexicographically_largest_sequence.cpp
        test_search_word_in_character_grid.cpp
        test_construct_powerset.cpp
        test_find_sum_combinations.cpp
        test_binary_tree_paths.cpp
        test_target_sum_ways.cpp
        test_subsets_with_duplicates.cpp)


target_link_libraries(test_backtracking GTest::GTest GTest::Main pthread)
add_test(NAME BackTrackingTests COMMAND test_backtracking)
