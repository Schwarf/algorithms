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

    //                          25
    //                    /            \
    //                  15              50
    //              /        \      /        \
    //            10          22  35          70
    //          /    \      /   \ /  \      /    \
    //         4      12   18  24 31  44   66     90
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

    EXPECT_EQ(inorder_find_successor(root, node10), node12);
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

TEST_F(SetupParentedBinaryTree, preorder_returns_nullptr_for_null_node)
{
    EXPECT_EQ(preorder_find_successor<int>(nullptr, nullptr), nullptr);
}

/////////////////// PRE-ORDER

TEST_F(SetupParentedBinaryTree, preorder_returns_left_child_when_present)
{
    create_tree();

    EXPECT_EQ(preorder_find_successor(root, root), node15);
    EXPECT_EQ(preorder_find_successor(root, node15), node10);
    EXPECT_EQ(preorder_find_successor(root, node4), node12);
}

TEST_F(SetupParentedBinaryTree, preorder_returns_right_child_when_left_child_is_missing)
{
    auto parent = make_node(1);
    auto right_child = make_node(2);
    connect(parent, nullptr, right_child);

    EXPECT_EQ(preorder_find_successor(parent, parent), right_child);
}

TEST_F(SetupParentedBinaryTree, preorder_returns_right_sibling_subtree_after_finishing_left_subtree)
{
    create_tree();

    EXPECT_EQ(preorder_find_successor(root, node4), node12);
    EXPECT_EQ(preorder_find_successor(root, node12), node22);
    EXPECT_EQ(preorder_find_successor(root, node24), node50);
}

TEST_F(SetupParentedBinaryTree, preorder_returns_nullptr_for_last_node_in_preorder_traversal)
{
    create_tree();

    EXPECT_EQ(preorder_find_successor(root, node90), nullptr);
}

TEST_F(SetupParentedBinaryTree, preorder_returns_nullptr_for_single_node_tree)
{
    auto single_node = make_node(42);

    EXPECT_EQ(preorder_find_successor(single_node, single_node), nullptr);
}

/////////////////// POST-ORDER

TEST_F(SetupParentedBinaryTree, postorder_returns_nullptr_for_null_node)
{
    EXPECT_EQ(postorder_find_successor<int>(nullptr, nullptr), nullptr);
}

TEST_F(SetupParentedBinaryTree, postorder_returns_first_node_in_right_subtree_after_left_subtree)
{
    create_tree();

    EXPECT_EQ(postorder_find_successor(root, node10), node18);
    EXPECT_EQ(postorder_find_successor(root, node15), node31);
    EXPECT_EQ(postorder_find_successor(root, node35), node66);
}

TEST_F(SetupParentedBinaryTree, postorder_returns_parent_after_right_subtree)
{
    create_tree();

    EXPECT_EQ(postorder_find_successor(root, node12), node10);
    EXPECT_EQ(postorder_find_successor(root, node24), node22);
    EXPECT_EQ(postorder_find_successor(root, node70), node50);
    EXPECT_EQ(postorder_find_successor(root, node50), root);
}

TEST_F(SetupParentedBinaryTree, postorder_returns_parent_when_left_child_has_no_right_sibling)
{
    auto parent = make_node(1);
    auto left_child = make_node(2);
    connect(parent, left_child, nullptr);

    EXPECT_EQ(postorder_find_successor(parent, left_child), parent);
}

TEST_F(SetupParentedBinaryTree, postorder_descends_to_right_child_when_right_subtree_has_no_left_branch)
{
    auto parent = make_node(1);
    auto left_child = make_node(2);
    auto right_child = make_node(3);
    auto right_grandchild = make_node(4);
    connect(parent, left_child, right_child);
    connect(right_child, nullptr, right_grandchild);

    EXPECT_EQ(postorder_find_successor(parent, left_child), right_grandchild);
}

TEST_F(SetupParentedBinaryTree, postorder_returns_successors_for_full_traversal_sequence)
{
    create_tree();

    EXPECT_EQ(postorder_find_successor(root, node4), node12);
    EXPECT_EQ(postorder_find_successor(root, node12), node10);
    EXPECT_EQ(postorder_find_successor(root, node10), node18);
    EXPECT_EQ(postorder_find_successor(root, node18), node24);
    EXPECT_EQ(postorder_find_successor(root, node24), node22);
    EXPECT_EQ(postorder_find_successor(root, node22), node15);
    EXPECT_EQ(postorder_find_successor(root, node15), node31);
    EXPECT_EQ(postorder_find_successor(root, node31), node44);
    EXPECT_EQ(postorder_find_successor(root, node44), node35);
    EXPECT_EQ(postorder_find_successor(root, node35), node66);
    EXPECT_EQ(postorder_find_successor(root, node66), node90);
    EXPECT_EQ(postorder_find_successor(root, node90), node70);
    EXPECT_EQ(postorder_find_successor(root, node70), node50);
    EXPECT_EQ(postorder_find_successor(root, node50), root);
    EXPECT_EQ(postorder_find_successor(root, root), nullptr);
}

TEST_F(SetupParentedBinaryTree, postorder_returns_nullptr_for_single_node_tree)
{
    auto single_node = make_node(42);

    EXPECT_EQ(postorder_find_successor(single_node, single_node), nullptr);
}
