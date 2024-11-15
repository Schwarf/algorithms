//
// Created by andreas on 18.07.22.
//

#include "gtest/gtest.h"
#include "min_costs_to_reach_end.h"
#include <vector>

class SetupCostsPerStep : public testing::Test
{
protected:
    std::vector<int> costs_per_step1{10, 15, 20};
    int minimal_costs1{15};
    std::vector<int> costs_per_step2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int minimal_costs2{6};
    std::vector<int> costs_per_step3{1, 12, 419, 181, 17, 19, 0, 71, 26, 1, 2, 3, 4, 5, 6, 7};
    int minimal_costs3{248};
};


TEST_F(SetupCostsPerStep, test_scenario1)
{
    auto min_costs = min_cost_to_reach_end(costs_per_step1);
    EXPECT_EQ(minimal_costs1, min_costs);
}

TEST_F(SetupCostsPerStep, test_scenario2)
{
    auto min_costs = min_cost_to_reach_end(costs_per_step2);
    EXPECT_EQ(minimal_costs2, min_costs);
}

TEST_F(SetupCostsPerStep, test_scenario3)
{
    auto min_costs = min_cost_to_reach_end(costs_per_step3);
    EXPECT_EQ(minimal_costs3, min_costs);
}
