//
// Created by andreas on 20.07.23.
//

#include "gtest/gtest.h"
#include "stacks_and_queues/asteroids_survival.h"

TEST(TestAsteroidsSurvival, simple1) {
    const std::vector<int> asteroids{5, 10, -5};
    const std::vector<int> expected_results{5, 10};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple2) {
    const std::vector<int> asteroids{8, -8};
    const std::vector<int> expected_results{};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple3) {
    const std::vector<int> asteroids{10, 2, -5};
    const std::vector<int> expected_results{10};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple4) {
    const std::vector<int> asteroids{-2, 5, 5, 5, 5, 5, -6};
    const std::vector<int> expected_results{-2, -6};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple5) {
    const std::vector<int> asteroids{20,10, -15, 12, -9, -21, 17};
    const std::vector<int> expected_results{-21, 17};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}

TEST(TestAsteroidsSurvival, simple6) {
    const std::vector<int> asteroids{5,10, -8, -10, 2, 3, 8, 9};
    const std::vector<int> expected_results{5,2,3,8,9};
    EXPECT_EQ(expected_results, survived_asteroids(asteroids));
}