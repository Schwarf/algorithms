//
// Created by andreas on 29.06.25.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/serialize_deserialize_binary_tree.h"

class SerializeDeserializeTest : public ::testing::Test
{
protected:
    // Utility to build a node
    template <typename T>
    TreeNode<T>* makeNode(T val, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr)
    {
        TreeNode<T>* node = new TreeNode<T>(val);
        node->left = left;
        node->right = right;
        return node;
    }

    template <typename T>
    bool treesEqual(TreeNode<T>* a, TreeNode<T>* b)
    {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->value == b->value
            && treesEqual(a->left, b->left)
            && treesEqual(a->right, b->right);
    }
};

TEST_F(SerializeDeserializeTest, EmptyTree)
{
    TreeNode<int>* root = nullptr;
    std::string s = serialize_tree(root);
    EXPECT_EQ(s, "#,");
    TreeNode<int>* des = deserialize_tree<int>(s);
    EXPECT_EQ(des, nullptr);
}

TEST_F(SerializeDeserializeTest, SingleNode)
{
    TreeNode<int>* root = makeNode<int>(42);
    std::string s = serialize_tree(root);
    EXPECT_EQ(s, "42,#,#,");
    TreeNode<int>* des = deserialize_tree<int>(s);
    EXPECT_TRUE(treesEqual(root, des));
}

TEST_F(SerializeDeserializeTest, CompleteTree)
{
    /*
        //    1
        //   / \
        //  2   3
        //     / \
        //    4   5
        */
    TreeNode<int>* root = makeNode<int>(1,
                                        makeNode<int>(2),
                                        makeNode<int>(3,
                                                      makeNode<int>(4),
                                                      makeNode<int>(5)));
    std::string s = serialize_tree(root);
    EXPECT_EQ(s, "1,2,#,#,3,4,#,#,5,#,#,");
    TreeNode<int>* des = deserialize_tree<int>(s);
    EXPECT_TRUE(treesEqual(root, des));
}

TEST_F(SerializeDeserializeTest, UnbalancedTree)
{
    /*
    //    7
    //     \
    //      8
    //       \
    //        9
    */
    TreeNode<int>* root = makeNode<int>(7,
                                        nullptr,
                                        makeNode<int>(8,
                                                      nullptr,
                                                      makeNode<int>(9)));
    std::string s = serialize_tree(root);
    EXPECT_EQ(s, "7,#,8,#,9,#,#,");
    TreeNode<int>* des = deserialize_tree<int>(s);
    EXPECT_TRUE(treesEqual(root, des));
}
