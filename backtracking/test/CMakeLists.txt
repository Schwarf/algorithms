project(test_backtracking)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)
add_executable(backtracking_test
        test_generate_all_subsets_of_size_k.cpp test_compute_all_permutations.cpp test_queens_problem.cpp
        test_path_sum_binray_tree.cpp
        test_letter_combinations_of_phone_numbers.cpp)

target_link_libraries(backtracking_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)