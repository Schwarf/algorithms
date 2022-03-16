cmake_minimum_required(VERSION 3.20)
project(linked_lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(remove_duplicates remove_duplicates_2_1.cpp)
add_executable(kth_to_last kth_to_last_2_2.cpp)
add_executable(delete_middle_element delete_middle_element_2_3.cpp)
add_executable(partition partition_2_4.cpp)
#add_subdirectory(./../data_structures/source/linked_lists ./cmake-build-debug)
#include_directories(./../data_structures/source/linked_lists)
#target_link_libraries(remove_duplicates linked_list_lib)