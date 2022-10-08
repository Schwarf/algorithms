cmake_minimum_required(VERSION 3.21)
project(trees_and_graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(route_4_1 route_between_nodes_4_1.cpp basics.h)
add_executable(minimal_tree_4_2 minimal_tree_4_2.cpp basics.h)
add_executable(depth_4_3 list_of_depths_4_3.cpp basics.h)
add_executable(balanced_4_4 balanced_binary_tree_4_4.cpp basics.h)
add_executable(main generate_random_graph.cpp)