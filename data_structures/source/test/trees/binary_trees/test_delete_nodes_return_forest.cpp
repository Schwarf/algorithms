//
// Created by andreas on 02.06.24.
//
#include "./trees/binary_trees/delete_nodes_return_forest.h"
#include "gtest/gtest.h"
#include "trees/binary_trees/pre_order_traversal.h"

TEST(TestDeleteNodesReturnForest, delete_nodes_in_between) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{3, 5};
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->left->left = new TreeNode<int>(4);
    auto second_expected_tree = new TreeNode(6);
    auto third_expected_tree = new TreeNode(7);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree, second_expected_tree, third_expected_tree};
    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForest, empty_tree) {
    TreeNode<int> *input_root = nullptr;
    const std::vector<int> value_to_delete{};
    std::vector<TreeNode<int> *> expected_result{};
    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
}

TEST(TestDeleteNodesReturnForest, delete_root_node) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    const std::vector<int> value_to_delete{1};
    auto first_expected_tree = new TreeNode<int>(2);
    auto second_expected_tree = new TreeNode<int>(3);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree, second_expected_tree};
    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForest, all_nodes_deleted) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{1, 2, 3, 4, 5, 6, 7};
    std::vector<TreeNode<int> *> expected_result{};
    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
}

TEST(TestDeleteNodesReturnForest, delete_leaf_nodes) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{4, 5, 6, 7};
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->right = new TreeNode<int>(3);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree};
    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    auto result_values = pre_order_traversal(result[0]);
    auto expected_result_values = pre_order_traversal(expected_result[0]);
    EXPECT_EQ(result_values, expected_result_values);
}

TEST(TestDeleteNodesReturnForest, large_tree_multiple_deletions) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);

    const std::vector<int> value_to_delete{3, 5, 9};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->left->left = new TreeNode<int>(4);
    first_expected_tree->left->left->left = new TreeNode<int>(8);
    first_expected_tree->left->right = nullptr;

    auto second_expected_tree = new TreeNode<int>(6);

    auto third_expected_tree = new TreeNode<int>(7);

    auto fourth_expected_tree = new TreeNode<int>(10);

    auto fifth_expected_tree = new TreeNode<int>(11);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree, fifth_expected_tree};

    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForest, large_tree_deletions_various_levels) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);
    input_root->right->left->left = new TreeNode<int>(12);
    input_root->right->left->right = new TreeNode<int>(13);

    const std::vector<int> value_to_delete{2, 3, 8, 13};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);

    auto second_expected_tree = new TreeNode<int>(4);
    second_expected_tree->right = new TreeNode<int>(9);

    auto third_expected_tree = new TreeNode<int>(5);
    third_expected_tree->left = new TreeNode<int>(10);
    third_expected_tree->right = new TreeNode<int>(11);

    auto fourth_expected_tree = new TreeNode<int>(6);
    fourth_expected_tree->left = new TreeNode<int>(12);

    auto fifth_expected_tree = new TreeNode<int>(7);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree, fifth_expected_tree};

    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForest, delete_node_and_child_but_not_grandchildren) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);

    const std::vector<int> value_to_delete{2, 4};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->right = new TreeNode<int>(3);
    first_expected_tree->right->left = new TreeNode<int>(6);
    first_expected_tree->right->right = new TreeNode<int>(7);

    auto second_expected_tree = new TreeNode<int>(5);
    second_expected_tree->left = new TreeNode<int>(10);
    second_expected_tree->right = new TreeNode<int>(11);

    auto third_expected_tree = new TreeNode<int>(8);
    auto fourth_expected_tree = new TreeNode<int>(9);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree};

    auto result = delete_nodes_return_forest(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}


TEST(TestDeleteNodesReturnForestIterative, delete_nodes_in_between) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{3, 5};
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->left->left = new TreeNode<int>(4);
    auto second_expected_tree = new TreeNode(6);
    auto third_expected_tree = new TreeNode(7);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree, second_expected_tree, third_expected_tree};
    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForestIterative, empty_tree) {
    TreeNode<int> *input_root = nullptr;
    const std::vector<int> value_to_delete{};
    std::vector<TreeNode<int> *> expected_result{};
    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
}

TEST(TestDeleteNodesReturnForestIterative, delete_root_node) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    const std::vector<int> value_to_delete{1};
    auto first_expected_tree = new TreeNode<int>(2);
    auto second_expected_tree = new TreeNode<int>(3);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree, second_expected_tree};
    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForestIterative, all_nodes_deleted) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{1, 2, 3, 4, 5, 6, 7};
    std::vector<TreeNode<int> *> expected_result{};
    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
}

TEST(TestDeleteNodesReturnForestIterative, delete_leaf_nodes) {
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    const std::vector<int> value_to_delete{4, 5, 6, 7};
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->right = new TreeNode<int>(3);
    std::vector<TreeNode<int> *> expected_result{first_expected_tree};
    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    auto result_values = pre_order_traversal(result[0]);
    auto expected_result_values = pre_order_traversal(expected_result[0]);
    EXPECT_EQ(result_values, expected_result_values);
}

TEST(TestDeleteNodesReturnForestIterative, large_tree_multiple_deletions) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);

    const std::vector<int> value_to_delete{3, 5, 9};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->left = new TreeNode<int>(2);
    first_expected_tree->left->left = new TreeNode<int>(4);
    first_expected_tree->left->left->left = new TreeNode<int>(8);
    first_expected_tree->left->right = nullptr;

    auto second_expected_tree = new TreeNode<int>(6);

    auto third_expected_tree = new TreeNode<int>(7);

    auto fourth_expected_tree = new TreeNode<int>(10);

    auto fifth_expected_tree = new TreeNode<int>(11);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree, fifth_expected_tree};

    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForestIterative, large_tree_deletions_various_levels) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);
    input_root->right->left->left = new TreeNode<int>(12);
    input_root->right->left->right = new TreeNode<int>(13);

    const std::vector<int> value_to_delete{2, 3, 8, 13};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);

    auto second_expected_tree = new TreeNode<int>(4);
    second_expected_tree->right = new TreeNode<int>(9);

    auto third_expected_tree = new TreeNode<int>(5);
    third_expected_tree->left = new TreeNode<int>(10);
    third_expected_tree->right = new TreeNode<int>(11);

    auto fourth_expected_tree = new TreeNode<int>(6);
    fourth_expected_tree->left = new TreeNode<int>(12);

    auto fifth_expected_tree = new TreeNode<int>(7);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree, fifth_expected_tree};

    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}

TEST(TestDeleteNodesReturnForestIterative, delete_node_and_child_but_not_grandchildren) {
    // Creating a larger binary tree
    auto input_root = new TreeNode<int>(1);
    input_root->left = new TreeNode<int>(2);
    input_root->right = new TreeNode<int>(3);
    input_root->left->left = new TreeNode<int>(4);
    input_root->left->right = new TreeNode<int>(5);
    input_root->right->left = new TreeNode<int>(6);
    input_root->right->right = new TreeNode<int>(7);
    input_root->left->left->left = new TreeNode<int>(8);
    input_root->left->left->right = new TreeNode<int>(9);
    input_root->left->right->left = new TreeNode<int>(10);
    input_root->left->right->right = new TreeNode<int>(11);

    const std::vector<int> value_to_delete{2, 4};

    // Expected forest
    auto first_expected_tree = new TreeNode<int>(1);
    first_expected_tree->right = new TreeNode<int>(3);
    first_expected_tree->right->left = new TreeNode<int>(6);
    first_expected_tree->right->right = new TreeNode<int>(7);

    auto second_expected_tree = new TreeNode<int>(5);
    second_expected_tree->left = new TreeNode<int>(10);
    second_expected_tree->right = new TreeNode<int>(11);

    auto third_expected_tree = new TreeNode<int>(8);
    auto fourth_expected_tree = new TreeNode<int>(9);

    std::vector<TreeNode<int> *> expected_result{
            first_expected_tree, second_expected_tree, third_expected_tree, fourth_expected_tree};

    auto result = delete_nodes_return_forest_bfs(input_root, value_to_delete);
    EXPECT_EQ(expected_result.size(), result.size());
    std::sort(result.begin(), result.end(), [](TreeNode<int> *root1, TreeNode<int> *root2) {
        return root1->value < root2->value;
    });
    for (int i{}; i < result.size(); ++i) {
        auto result_values = pre_order_traversal(result[i]);
        auto expected_result_values = pre_order_traversal(expected_result[i]);
        EXPECT_EQ(result_values, expected_result_values);
    }
}
