//
// Created by andreas on 12.07.23.
//

#include "gtest/gtest.h"
#include "trees/binary_trees/all_nodes_in_distance_k.h"

#include "setup_binary_tree.h"
TEST_F(SetupBinaryTree, simple1_distance2)
{
    auto root_target_pair = k_distance_tree();
    auto root = root_target_pair.first;
    auto target = root_target_pair.second;
    std::vector<unsigned int> expected_result{1,4,7};
    constexpr int distance{2};
    auto result = all_nodes_in_distance_k(root, target, distance);
    std::sort(result.begin(), result.end());
    for(int i{}; i < result.size(); ++i)
    {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}

TEST_F(SetupBinaryTree, simple1_distance1)
{
    auto root_target_pair = k_distance_tree();
    auto root = root_target_pair.first;
    auto target = root_target_pair.second;
    std::vector<unsigned int> expected_result{2,3,6};
    constexpr int distance{1};
    auto result = all_nodes_in_distance_k(root, target, distance);
    std::sort(result.begin(), result.end());
    for(int i{}; i < result.size(); ++i)
    {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}

TEST_F(SetupBinaryTree, simple1_distance3)
{
    auto root_target_pair = k_distance_tree();
    auto root = root_target_pair.first;
    auto target = root_target_pair.second;
    std::vector<unsigned int> expected_result{0, 8};
    constexpr int distance{3};
    auto result = all_nodes_in_distance_k(root, target, distance);
    std::sort(result.begin(), result.end());
    for(int i{}; i < result.size(); ++i)
    {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}


TEST_F(SetupBinaryTree, simple2_distance5)
{
    auto root_target_pair = k_distance_tree2();
    auto root = root_target_pair.first;
    auto target = root_target_pair.second;
    std::vector<unsigned int> expected_result{0, 8};
    constexpr int distance{5};
    auto result = all_nodes_in_distance_k(root, target, distance);
    std::sort(result.begin(), result.end());
    for(int i{}; i < result.size(); ++i)
    {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}

TEST_F(SetupBinaryTree, simple2_invalid_distance)
{
    auto root_target_pair = k_distance_tree2();
    auto root = root_target_pair.first;
    auto target = root_target_pair.second;
    constexpr int distance{7};
    auto result = all_nodes_in_distance_k(root, target, distance);
    std::sort(result.begin(), result.end());
    EXPECT_TRUE(result.empty());
}
