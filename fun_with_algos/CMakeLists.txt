cmake_minimum_required(VERSION 3.22)
project(fun_with_algos)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(./test)

add_executable(fun_with_algos main.cpp
        get_majority_element.h
        three_sum.h
        interval_merging.h
        subarray_product_less_than.h
        used_concepts.h
        remove_occurences_of_value.h
        remove_duplicates_from_sorted_array.h minimum_intervals_to_cover_range.h)
