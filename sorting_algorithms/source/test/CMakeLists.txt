# 'Google_test' is the subproject name
project(Google_tests)

#add_subdirectory(google_test_lib)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(sorting_tests
        sorting_algorithms/sorting_setup.h
        sorting_algorithms/test_selection_sort.cpp
        sorting_algorithms/test_merge_sort.cpp
        sorting_algorithms/test_main.cpp
        sorting_algorithms/test_shell_sort.cpp
        sorting_algorithms/test_bubble_sort.cpp
        sorting_algorithms/test_counting_sort.cpp
        sorting_algorithms/test_upper_bound.cpp
        sorting_algorithms/test_lower_bound.cpp)
#target_link_libraries(sorting_tests gtest gtest_main)
target_link_libraries(sorting_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(sorting_tests sorting_lib)