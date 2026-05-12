//
// Created by andreas on 03.06.22.
//

#include "setup_for_segment_tree_testing.h"
#include "./../../../trees/segment_trees/segment_tree.h"


TEST_F(SetupSegmentTree, test_segment_tree)
{
    auto tree = SegmentTree<int>(input);
    int left_index{2};
    int right_index{6};
    auto sum1 = tree.sum_range(left_index, right_index);
    auto sum2 = prefix_sum[right_index + 1] - prefix_sum[left_index];
    EXPECT_EQ(sum1, sum2);
}

TEST_F(SetupSegmentTree, test_segment_tree_full_range)
{
    SegmentTree<int> tree(input);
    EXPECT_EQ(tree.sum_range(0, static_cast<int>(input.size()) - 1), prefix_sum.back());
}

TEST_F(SetupSegmentTree, test_segment_tree_single_element_ranges)
{
    SegmentTree<int> tree(input);

    for (int i = 0; i < input.size(); ++i) {
        EXPECT_EQ(tree.sum_range(i, i), input[i]);
    }
}

TEST_F(SetupSegmentTree, test_segment_tree_several_ranges)
{
    SegmentTree<int> tree(input);

    for (int left = 0; left < input.size(); ++left) {
        for (int right = left; right < input.size(); ++right) {
            int expected = prefix_sum[right + 1] - prefix_sum[left];
            EXPECT_EQ(tree.sum_range(left, right), expected)
                << "left=" << left << ", right=" << right;
        }
    }
}

TEST_F(SetupSegmentTree, test_update_changes_single_position)
{
    SegmentTree<int> tree(input);

    const int index = 4;
    const int new_value = 100;

    input[index] = new_value;
    tree.update(index, new_value);

    for (int left = 0; left < input.size(); ++left) {
        for (int right = left; right < input.size(); ++right) {
            int expected = 0;
            for (int i = left; i <= right; ++i)
                expected += input[i];

            EXPECT_EQ(tree.sum_range(left, right), expected)
                << "left=" << left << ", right=" << right;
        }
    }
}

TEST_F(SetupSegmentTree, test_multiple_updates)
{
    SegmentTree<int> tree(input);

    tree.update(0, 111);
    input[0] = 111;

    tree.update(7, -5);
    input[7] = -5;

    tree.update(14, 222);
    input[14] = 222;

    for (int left = 0; left < input.size(); ++left) {
        for (int right = left; right < input.size(); ++right) {
            int expected = 0;
            for (int i = left; i <= right; ++i)
                expected += input[i];

            EXPECT_EQ(tree.sum_range(left, right), expected)
                << "left=" << left << ", right=" << right;
        }
    }
}