//
// Created by andreas on 03.06.22.
//

#ifndef SETUP_FOR_SEGMENT_TREE_TESTING_H
#define SETUP_FOR_SEGMENT_TREE_TESTING_H
//
// Created by andreas on 03.04.22.
//

#include "gtest/gtest.h"
#include <vector>


class SetupSegmentTree: public testing::Test
{
public:
	void SetUp() override
		{
			compute_prefix_sum();
		};
protected:
	std::vector<int> input{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
	std::vector<int> prefix_sum;
private:
	void compute_prefix_sum()
	{
		prefix_sum = std::vector<int>(input.size()+1);
		for(int i =0; i < input.size(); ++i)
		{
			prefix_sum[i+1] = prefix_sum[i] + input[i];
		}
	}


};

#endif //SETUP_FOR_SEGMENT_TREE_TESTING_H
