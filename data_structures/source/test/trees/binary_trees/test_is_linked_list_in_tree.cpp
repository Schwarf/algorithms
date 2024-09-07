//
// Created by andreas on 07.09.24.
//

#include "trees/binary_trees/is_linked_list_in_tree.h"
#include "setup_binary_tree.h"
#include "./../../linked_lists/setup_singly_linked_lists.h"

class SetupBinaryTreesAndLinkedLists : public SetupSinglyLinkedLists, public SetupBinaryTree {
protected:
    void SetUp() override {
        SetupSinglyLinkedLists::SetUp();
        SetupBinaryTree::SetUp();
    }

    void TearDown() override {
        SetupSinglyLinkedLists::TearDown();
        SetupBinaryTree::TearDown();
    }
};


TEST_F(SetupBinaryTreesAndLinkedLists, TestIsLinkedListInTreeSimple1) {
    auto list_head = get_single_list_from_vector(std::vector<unsigned int>{15, 10, 12});
    auto tree = binary_tree_root();
    EXPECT_TRUE(is_linked_list_in_tree(list_head, tree));


}