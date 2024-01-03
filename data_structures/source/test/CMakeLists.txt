project(Google_tests)

# 'lib' is the folder with Google Test sources
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./../)
enable_testing()
add_executable(test_graphs
        graphs/test_does_path_graph_exist.cpp
        graphs/test_graph.cpp
        graphs/test_is_bipartition_possible.cpp
        graphs/test_breadth_first_search.cpp
        graphs/test_depth_first_search.cpp
        graphs/test_weighted_graph.cpp
        graphs/test_find_shortest_edge_in_subgraph.cpp
        graphs/test_minimum_number_of_egdes_to_create_connected_graph.cpp
        graphs/test_all_roads_lead_to_rome.cpp
        graphs/test_clone_graph.cpp
        graphs/test_minimal_distance_to_connect_all_points.cpp
        graphs/test_size_of_largest_island.cpp graphs/test_maximum_marked_circles.cpp
        graphs/test_time_to_inform_hierachy.cpp graphs/test_can_finish_course_schedule.cpp graphs/test_max_rank_of_city_network.cpp graphs/test_reconstruct_flight_itinerary.cpp graphs/test_path_with_minimum_effort.cpp graphs/test_shortest_path_length.cpp graphs/test_reconstruct_array_from_adjacent_pairs.cpp graphs/test_design_graph_with_shortest_path_calculator.cpp graphs/test_is_graph_a_valid_tree.cpp graphs/test_shortest_path_algorithms.cpp)

add_executable(test_linked_lists
        linked_lists/test_singly_linked_list.cpp
        linked_lists/test_doubly_linked_list.cpp
        linked_lists/test_remove_duplicates.cpp
        linked_lists/setup_singly_linked_lists.h
        linked_lists/test_remove_duplicates_dll.cpp
        linked_lists/setup_doubly_linked_lists.h
        linked_lists/test_kth_to_last.cpp
        linked_lists/test_delete_nodes.cpp
        linked_lists/test_partition_linked_list_for_element.cpp
        linked_lists/test_add_two_numbers.cpp
        linked_lists/test_check_if_linked_list_is_palindrome.cpp
        linked_lists/test_are_linked_lists_intersecting.cpp
        linked_lists/test_does_linked_list_have_loop.cpp linked_lists/test_swapping_nodes.cpp linked_lists/test_swap_nodes_in_pairs.cpp linked_lists/test_maximum_twin_sum.cpp linked_lists/test_deep_copy_linked_list_with_random_pointer.cpp linked_lists/test_split_linked_list_in_parts.cpp)

add_executable(test_stacks_and_queues
        stacks_and_queues/test_stack_linked_list_based.cpp
        stacks_and_queues/test_stack_array_based.cpp
        stacks_and_queues/setup_stack.h
        stacks_and_queues/test_queue_linked_list_based.cpp
        stacks_and_queues/test_queue_array_based.cpp
        stacks_and_queues/test_lru_cache.cpp
        stacks_and_queues/monotonic_stack_and_queue/test_monotonic_stack.cpp
        stacks_and_queues/test_longest_parentheses_string.cpp stacks_and_queues/test_asteroids_survival.cpp stacks_and_queues/monotonic_stack_and_queue/test_monotonic_queue.cpp stacks_and_queues/test_132_pattern.cpp)

add_executable(test_heaps
        heaps/test_binary_heap.cpp
        heaps/test_k_ary_heap.cpp
        heaps/test_find_remaining_stone.cpp heaps/test_smallest_number_in_infinite_set.cpp heaps/test_kth_largest_element_in_stream.cpp)

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
        trees/binary_trees/test_maximum_difference_between_node_and_ancestor.cpp
        trees/binary_trees/test_find_duplicate_subtrees.cpp
        trees/binary_trees/test_is_binary_tree_complete.cpp
        trees/binary_trees/test_minimum_depth_binary_tree.cpp
        trees/binary_trees/test_all_nodes_in_distance_k.cpp trees/binary_trees/test_maximum_path_sum.cpp trees/binary_trees/test_find_mode_in_binary_tree.cpp trees/binary_trees/test_find_two_sum_in_binary_tree.cpp)

add_executable(test_segment_tree_algorithms
        trees/segment_trees/setup_for_segment_tree_testing.h
        trees/segment_trees/test_segment_tree.cpp
        )

add_executable(test_binary_search_tree_algorithms
        binary_search_tree/test_avl_tree.cpp
        tries/test_trie.cpp union_find_disjoint_set/test_quick_find.cpp)


add_executable(test_union_find_disjoint_set_algorithms
        union_find_disjoint_set/test_quick_find.cpp
        union_find_disjoint_set/test_optimized_disjoint_set.cpp
        )

add_executable(test_dictionaries dictionaries/test_ordered_dictionary.cpp)
add_executable(test_caches caches/test_lru_cache.cpp caches/test_lfu_cache.cpp)

target_link_libraries(test_graphs ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_linked_lists ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_stacks_and_queues ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_heaps ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_traversal ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_segment_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_search_tree_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_binary_tree_inversion ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_union_find_disjoint_set_algorithms ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_dictionaries ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(test_caches ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)