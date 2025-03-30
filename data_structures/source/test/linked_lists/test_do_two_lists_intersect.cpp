//
// Created by andreas on 10.08.24.
//
#include "linked_lists/do_two_lists_intersect.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimple1)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4, 5});
    auto head2 = get_single_list_from_vector(std::vector<int>{6, 7, 8, 9, 0});
    EXPECT_TRUE(nullptr == do_lists_intersect(head1, head2));
}


TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimple2)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4, 5});
    auto head2 = get_single_list_from_vector(std::vector<int>{6, 7, 8});
    head2->next->next->next = head1->next;
    EXPECT_TRUE(head1->next == do_lists_intersect(head1, head2));
    EXPECT_TRUE(head2->next->next->next == do_lists_intersect(head1, head2));
}

TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimple3)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4, 5});
    auto head2 = get_single_list_from_vector(std::vector<int>{6, 7, 8});
    head2->next->next->next = head1;
    EXPECT_TRUE(head2->next->next->next == do_lists_intersect(head1, head2));
    EXPECT_TRUE(head1 == do_lists_intersect(head1, head2));
}

TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimple4)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4, 5});
    auto head2 = get_single_list_from_vector(std::vector<int>{6, 7, 8});
    head2->next->next->next = head1->next->next->next->next;
    EXPECT_TRUE(head2->next->next->next == do_lists_intersect(head1, head2));
    EXPECT_TRUE(head1->next->next->next->next == do_lists_intersect(head1, head2));
}

TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimple5)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4, 5});
    auto head2 = get_single_list_from_vector(std::vector<int>{6, 7, 8});
    head2->next->next->next = head1->next->next->next->next;
    EXPECT_TRUE(head2->next->next->next == do_lists_intersect(head2, head1));
    EXPECT_TRUE(head1->next->next->next->next == do_lists_intersect(head1, head2));
}

TEST_F(SetupSinglyLinkedLists, TestDoListsIntersectSimpler6)
{
    auto head1 = get_single_list_from_vector(std::vector<int>{1});
    auto head2 = get_single_list_from_vector(std::vector<int>{6});
    head2->next = head1;
    EXPECT_TRUE(head2->next == do_lists_intersect(head2, head1));
    EXPECT_TRUE(head1 == do_lists_intersect(head1, head2));
}
