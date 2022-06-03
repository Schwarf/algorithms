//
// Created by andreas on 03.06.22.
//

#include "setup_for_segment_tree_testing.h"
#include "./../../../trees/segment_trees/segment_tree.h"


TEST_F(SetupSegmentTree, test_segment_tree)
{
	auto tree = SegmentTree<int>(input);
	EXPECT_TRUE(1==1);
}
