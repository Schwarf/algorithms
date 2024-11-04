//
// Created by andreas on 04.11.24.
//

#include "graphs/tarjan_algorithm.h"
#include "gtest/gtest.h"

template <typename T>
class TarjanTest : public ::testing::Test
{
protected:
};

typedef ::testing::Types<int, long, short> TestTypes; // Example with int and long
TYPED_TEST_SUITE(TarjanTest, TestTypes);

TYPED_TEST(TarjanTest, SinglePathGraph)
{
    std::vector<std::vector<TypeParam>> edges({{0, 1}, {1, 2}, {2, 3}});
    constexpr int number_of_nodes{4};
    auto [low, discovered] = tarjan_algorithm(edges, number_of_nodes);

    // Expected discovery and low values for the path
    std::vector<TypeParam> expected_discovered = {1, 2, 3, 4};
    std::vector<TypeParam> expected_low = {1, 2, 3, 4}; // Each node only connects to the next one

    EXPECT_EQ(discovered, expected_discovered);
    EXPECT_EQ(low, expected_low);
}

TYPED_TEST(TarjanTest, CycleGraph)
{
    std::vector<std::vector<TypeParam>> edges({{0, 1}, {1, 2}, {2, 3}, {3, 0}});
    constexpr int number_of_nodes{4};
    auto [low, discovered] = tarjan_algorithm(edges, number_of_nodes);

    std::vector<TypeParam> expected_discovered = {1, 2, 3, 4};
    std::vector<TypeParam> expected_low = {1, 1, 1, 1}; // All nodes can reach back to the start of the cycle

    EXPECT_EQ(discovered, expected_discovered);
    EXPECT_EQ(low, expected_low);
}

TYPED_TEST(TarjanTest, PetersenGraph)
{
    std::vector<std::vector<TypeParam>> edges({
        {0, 2}, {0, 3}, {0, 5}, {1, 3}, {1, 4}, {1, 6}, {2, 4}, {2, 7}, {3, 8},
        {4, 9}, {5, 6}, {5, 9}, {6, 7}, {7, 8}, {8, 9}
    });
    constexpr int number_of_nodes{10};
    auto [low, discovered] = tarjan_algorithm(edges, number_of_nodes);

    std::vector<TypeParam> expected_discovered = {1, 7, 2, 8, 3, 5, 6, 4, 9, 4};
    std::vector<TypeParam> expected_low(10, 1); // All nodes can reach back to the start of the cycle

    EXPECT_EQ(discovered, expected_discovered);
    EXPECT_EQ(low, expected_low);
}
