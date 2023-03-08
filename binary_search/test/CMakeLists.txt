project(Google_tests_for_binary_search)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

add_executable(test_binary_search
        test_first_appearance_in_sorted_vector.cpp
        test_last_appearance_in_sorted_vector.cpp test_minimum_car_size_to_ship_packages.cpp test_kth_missing_element.cpp test_minimum_time_to_schedule_n_bus_trips.cpp)


target_link_libraries(test_binary_search ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)