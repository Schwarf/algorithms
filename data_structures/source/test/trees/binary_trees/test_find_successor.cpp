//
// Created by andreas on 07.09.26.
//

#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "trees/binary_trees/find_successor.h"

class SetupParentedBinaryTree : public testing::Test
{
protected:
    using Node = ParentedTreeNode<int>;

    Node* make_node(int value)
    {
        nodes.push_back(std::make_unique<Node>(value));
        return nodes.back().get();
    }

    Node* create_tree()
    {
        root = make_node(25);
        node15 = make_node(15);
        node50 = make_node(50);
        node10 = make_node(10);
        node22 = make_node(22);
        node35 = make_node(35);
        node70 = make_node(70);
        node4 = make_node(4);
        node12 = make_node(12);
        node18 = make_node(18);
        node24 = make_node(24);
        node31 = make_node(31);
        node44 = make_node(44);
        node66 = make_node(66);
        node90 = make_node(90);

        connect(root, node15, node50);
        connect(node15, node10, node22);
        connect(node50, node35, node70);
        connect(node10, node4, node12);
        connect(node22, node18, node24);
        connect(node35, node31, node44);
        connect(node70, node66, node90);

        return root;
    }

    static void connect(Node* parent, Node* left, Node* right)
    {
        parent->left = left;
        parent->right = right;

        if (left)
            left->parent = parent;
        if (right)
            right->parent = parent;
    }

    std::vector<std::unique_ptr<Node>> nodes;
    Node* root = nullptr;
    Node* node15 = nullptr;
    Node* node50 = nullptr;
    Node* node10 = nullptr;
    Node* node22 = nullptr;
    Node* node35 = nullptr;
    Node* node70 = nullptr;
    Node* node4 = nullptr;
    Node* node12 = nullptr;
    Node* node18 = nullptr;
    Node* node24 = nullptr;
    Node* node31 = nullptr;
    Node* node44 = nullptr;
    Node* node66 = nullptr;
    Node* node90 = nullptr;
};

TEST_F(SetupParentedBinaryTree, returns_nullptr_for_null_node)
{
    EXPECT_EQ(inorder_find_successor<int>(nullptr, nullptr), nullptr);
}

TEST_F(SetupParentedBinaryTree, returns_leftmost_node_in_right_subtree)
{
    create_tree();

    EXPECT_EQ(inorder_find_successor(root, root), node31);
    EXPECT_EQ(inorder_find_successor(root, node15), node18);
}

TEST_F(SetupParentedBinaryTree, returns_parent_when_node_is_left_child_without_right_subtree)
{
    create_tree();

    EXPECT_EQ(inorder_find_successor(root, node4), node10);
    EXPECT_EQ(inorder_find_successor(root, node18), node22);
}

TEST_F(SetupParentedBinaryTree, returns_first_ancestor_reached_from_left)
{
    create_tree();

    EXPECT_EQ(inorder_find_successor(root, node12), node15);
    EXPECT_EQ(inorder_find_successor(root, node24), root);
    EXPECT_EQ(inorder_find_successor(root, node44), node50);
}

TEST_F(SetupParentedBinaryTree, returns_nullptr_for_last_node_in_inorder_traversal)
{
    create_tree();

    EXPECT_EQ(inorder_find_successor(root, node90), nullptr);
}

TEST_F(SetupParentedBinaryTree, returns_nullptr_for_single_node_tree)
{
    auto single_node = make_node(42);

    EXPECT_EQ(inorder_find_successor(single_node, single_node), nullptr);
}
