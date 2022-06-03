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
	auto sum2 = prefix_sum[right_index+1] - prefix_sum[left_index];
	EXPECT_EQ(sum1, sum2);
}
