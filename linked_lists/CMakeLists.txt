cmake_minimum_required(VERSION 3.22)
project(linked_lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(linked_lists main.cpp simple_single_linked_list.h reverse_linked_list.h reverse_linked_list_between_positions.h)
