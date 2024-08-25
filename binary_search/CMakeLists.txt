cmake_minimum_required(VERSION 3.21)
project(binary_search)
include(CheckCXXCompilerFlag)
set(CMAKE_CXX_STANDARD 20)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if (flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if (flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif ()
        unset(flag_supported CACHE)
    endif ()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-std=c++17")
enable_cxx_compiler_flag_if_supported("-O0")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning

add_subdirectory(test)

add_executable(binary_search main.cpp
        binary_search.h
        first_appearance_in_sorted_vector.h
        last_appearance_in_sorted_vector.h
        minimum_car_size_to_ship_packages.h
        kth_missing_element.h
        minimum_time_to_schedule_n_bus_trips.h
        minimum_speed_to_eat_bananas_in_n_hours.h
        used_concepts.h
        construct_bounded_array_with_max_at_index.h
        median_of_two_sorted_arrays.h search_sorted_2d_matrix.h find_element_index_in_rotated_array.h
        minimum_number_of_days.h
        find_kth_smallest_distance.h
        range_sum_of_sorted_subarrays.h)
