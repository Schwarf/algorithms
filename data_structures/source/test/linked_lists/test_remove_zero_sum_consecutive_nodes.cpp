//
// Created by andreas on 12.03.24.
//

#include "setup_singly_linked_lists.h"
#include "linked_lists/remove_zero_sum_consecutive_nodes.h"

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodes)
{
	const std::vector<int> input_with_duplicates1{1, 2, -3, 3, 1};
	auto head = get_single_list_from_vector(input_with_duplicates1);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{3, 1};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}