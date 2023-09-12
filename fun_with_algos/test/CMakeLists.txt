project(test_fun_with_algos)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(test_fun_with_algos
        test_get_majority_element.cpp
        test_remove_occurences_of_value.cpp
        test_remove_duplicates_from_sorted_array.cpp
        test_minimum_intervals_to_cover_range.cpp test_minimum_deletions_for_unique_character_frequencies.cpp)

include_directories(./../)
target_link_libraries(test_fun_with_algos ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
