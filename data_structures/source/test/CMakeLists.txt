project(Google_tests)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


enable_testing()
add_executable(test_linked_lists
        linked_lists/test_singly_linked_list.cpp
        linked_lists/test_doubly_linked_list.cpp)

add_executable(test_stacks_and_queues
        stacks_and_queues/test_stack_linked_list_based.cpp
        stacks_and_queues/test_stack_array_based.cpp
        stacks_and_queues/setup_stack.h
        stacks_and_queues/test_queue_linked_list_based.cpp
        stacks_and_queues/test_queue_array_based.cpp
        stacks_and_queues/test_lru_cache.cpp)

add_executable(test_heaps
        heaps/test_binary_heap.cpp
        heaps/test_k_ary_heap.cpp)

add_executable(test_binary_tree_traversal
        trees/binary_trees/test_pre_order_traversal.cpp
        trees/binary_trees/test_in_order_traversal.cpp
        trees/binary_trees/test_post_order_traversal.cpp
        trees/binary_trees/test_level_order_traversal.cpp
        )

add_executable(test_binary_tree_inversion
        trees/binary_trees/test_invert_binary_tree.cpp
        )

add_executable(test_binary_tree_algorithms
        trees/test_binary_tree.cpp
        trees/binary_trees/test_maximum_depth.cpp
        trees/binary_trees/test_right_side_view.cpp
        trees/binary_trees/test_construct_binary_tree_from_inorder_and_postorder.cpp
        trees/binary_trees/test_construct_binary_tree_from_preorder_and_inorder.cpp
        trees/binary_trees/test_binary_search_tree_from_sorted_array.cpp
        trees/binary_trees/test_flatten_binary_search_tree_to_array.cpp
        )

add_executable(test_segment_tree_algorithms
        trees/segment_trees/setup_for_segment_tree_testing.h
        trees/segment_trees/test_segment_tree.cpp
)

add_executable(test_binary_search_tree_algorithms
        binary_search_tree/test_avl_tree.cpp
        )


target_link_libraries(test_linked_lists ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_stacks_and_queues ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_heaps ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_traversal ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_segment_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_search_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_inversion ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
