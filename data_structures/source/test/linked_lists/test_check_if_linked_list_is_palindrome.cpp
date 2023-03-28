//
// Created by andreas on 28.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/check_if_linked_list_is_palindrome.h"


TEST_F(SetupSinglyLinkedLists, check_for_palindrome_true1)
{
	std::vector<int> input{1,2,3,3,2,1};
	auto head = get_single_list_from_vector(input);
	EXPECT_TRUE(is_palindrome(head));
}

TEST_F(SetupSinglyLinkedLists, check_for_palindrome_true2)
{
	std::vector<int> input{1,2,3,2,1};
	auto head = get_single_list_from_vector(input);
	EXPECT_TRUE(is_palindrome(head));
}

TEST_F(SetupSinglyLinkedLists, check_for_palindrome_false1)
{
	std::vector<int> input{1,2,3,2};
	auto head = get_single_list_from_vector(input);
	EXPECT_TRUE(is_palindrome(head));
}


