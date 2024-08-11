//
// Created by andreas on 17.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/delete_nodes.h"
#include <vector>

TEST_F(SetupSinglyLinkedLists, delete_nodes1) {
    std::vector<int> input{1, 2, 3, 4, 5};
    auto head = get_single_list_from_vector(input);
    auto node_to_delete = head->next->next;
    delete_given_node_but_not_last_node(node_to_delete);
    std::vector<int> expected_values{1, 2, 4, 5};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}


TEST_F(SetupSinglyLinkedLists, delete_nodes2) {
    std::vector<int> input{1, 2, 3, 4, 5};
    auto head = get_single_list_from_vector(input);
    auto node_to_delete = head;
    delete_given_node_but_not_last_node(node_to_delete);
    std::vector<int> expected_values{2, 3, 4, 5};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}


TEST_F(SetupSinglyLinkedLists, delete_nodes3) {
    std::vector<int> input{1, 2, 3, 4, 5};
    auto head = get_single_list_from_vector(input);
    auto node_to_delete = head->next->next->next;
    delete_given_node_but_not_last_node(node_to_delete);
    std::vector<int> expected_values{1, 2, 3, 5};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}

TEST_F(SetupSinglyLinkedLists, delete_middle_nodes1) {
    std::vector<int> input{1, 2, 3, 4, 5};
    auto head = get_single_list_from_vector(input);
    delete_middle_node_in_list_with_at_least_two_elements(head);
    std::vector<int> expected_values{1, 2, 4, 5};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}

TEST_F(SetupSinglyLinkedLists, delete_middle_nodes2) {
    std::vector<int> input{1, 2};
    auto head = get_single_list_from_vector(input);
    delete_middle_node_in_list_with_at_least_two_elements(head);
    std::vector<int> expected_values{2};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}


TEST_F(SetupSinglyLinkedLists, delete_middle_nodes3) {
    std::vector<int> input{1, 2, 3, 4};
    auto head = get_single_list_from_vector(input);
    delete_middle_node_in_list_with_at_least_two_elements(head);
    std::vector<int> expected_values{1, 3, 4};
    size_t index{};
    while (head) {
        EXPECT_EQ(head->value, expected_values[index++]);
        head = head->next;
    }
}
