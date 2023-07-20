//
// Created by andreas on 20.07.23.
//

#include "gtest/gtest.h"
#include "stacks_and_queues/asteroids_survival.h"

TEST(TestAsteroidsSurvival, simple1)
{
    const std::vector<int> asteroids{5, 10, -5};
    const std::vector<int> expected_results{5, 10};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple2)
{
    const std::vector<int> asteroids{8, -8};
    const std::vector<int> expected_results{};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple3)
{
    const std::vector<int> asteroids{10, 2, -5};
    const std::vector<int> expected_results{10};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}