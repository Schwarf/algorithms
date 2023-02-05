//
// Created by andreas on 05.02.23.
//

#ifndef SETUP_DISJOINT_SETS_H
#define SETUP_DISJOINT_SETS_H
#include "gtest/gtest.h"
#include <vector>


class SetupDisjointSets: public testing::Test
{
public:
	SetupDisjointSets() = default;
protected:
	std::vector<size_t> set1{0, 2, 4, 6, 8};
	std::vector<size_t> set2{1, 3, 5, 7, 9};

};

#endif //SETUP_DISJOINT_SETS_H
