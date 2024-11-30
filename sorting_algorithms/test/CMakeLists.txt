project(test_sorting_algorithms)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./../)

add_executable(test_sorting_algorithms
        test_heap_sort.cpp
        test_setup.h
        test_quick_sort.cpp
        test_counting_sort.cpp
        test_merge_sort.cpp
        test_insertion_sort.cpp
        test_selection_sort.cpp
        test_bubble_sort.cpp
        test_bitonic_sort.cpp
        test_shell_sort.cpp
        test_sort_characters_by_frequency.cpp
        test_sort_array_by_increasing_frequency.cpp
        test_sort_jumbled_numbers.cpp
        test_minimum_number_of_dial_pushes_for_word.cpp
        test_optimized_sort.cpp
)

#target_link_libraries(sorting_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_sorting_algorithms GTest::GTest GTest::Main pthread)
add_test(NAME SortingAlgorithmsTests COMMAND test_sorting_algorithms)
