project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(google_test_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_data_structures
        linked_lists/test_singly_linked_list.cpp
        linked_lists/test_doubly_linked_list.cpp
        stacks_and_queues/test_stack_linked_list_based.cpp
        stacks_and_queues/test_stack_array_based.cpp
        stacks_and_queues/setup_stack.h
        stacks_and_queues/test_queue_linked_list_based.cpp
        stacks_and_queues/test_queue_array_based.cpp
        heaps/test_binary_heap.cpp
        heaps/test_k_ary_heap.cpp
        trees/test_binary_tree.cpp
        trees/binary_trees/test_pre_order_traversal.cpp trees/binary_trees/test_in_order_traversal.cpp)
target_link_libraries(test_data_structures gtest gtest_main)
target_link_libraries(test_data_structures linked_list_lib)
