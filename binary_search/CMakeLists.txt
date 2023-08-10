cmake_minimum_required(VERSION 3.21)
project(binary_search)

set(CMAKE_CXX_STANDARD 20)
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
        median_of_two_sorted_arrays.h search_sorted_2d_matrix.h find_element_index_in_rotated_array.h)
