project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(google_test_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()
add_executable(test_linked_lists
        linked_lists/test_singly_linked_list.cpp
        linked_lists/test_doubly_linked_list.cpp)

add_executable(test_stacks_and_queues
        stacks_and_queues/test_stack_linked_list_based.cpp
        stacks_and_queues/test_stack_array_based.cpp
        stacks_and_queues/setup_stack.h
        stacks_and_queues/test_queue_linked_list_based.cpp
        stacks_and_queues/test_queue_array_based.cpp)

add_executable(test_heaps
        heaps/test_binary_heap.cpp
        heaps/test_k_ary_heap.cpp)

add_executable(test_binary_tree_traversal
        trees/binary_trees/test_pre_order_traversal.cpp
        trees/binary_trees/test_in_order_traversal.cpp
        trees/binary_trees/test_post_order_traversal.cpp)

add_executable(test_binary_tree_algorithms
        trees/test_binary_tree.cpp
        trees/binary_trees/test_maximum_depth.cpp
        trees/binary_trees/test_invert_binary_tree.cpp)

target_link_libraries(test_linked_lists gtest gtest_main)
target_link_libraries(test_stacks_and_queues gtest gtest_main)
target_link_libraries(test_heaps gtest gtest_main)
target_link_libraries(test_binary_tree_traversal gtest gtest_main)
target_link_libraries(test_binary_tree_algorithms gtest gtest_main)


