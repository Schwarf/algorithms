//
// Created by andreas on 15.03.23.
//

#include "test_setup_doubly_linked_lists.h"
#include "linked_lists/remove_duplicates_dll.h"
TEST_F(SetupDoublyLinkedLists, remove_duplicates1)
{
	std::vector<int> input_with_duplicates1{1, 2, 4, 2, 6, 7, 6};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates1);
	auto result = remove_duplicates(head);
	std::vector<int> result_without_duplicates1{1, 2, 4, 6 ,7};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates1[index++], result->value);
		result = result->next;
	}
}
