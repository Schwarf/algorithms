//
// Created by andreas on 19.01.26.
//
// four_sum_test.cpp
#include <gtest/gtest.h>
#include "../four_sum.h"


#include <algorithm>
#include <utility>
#include <vector>

class SetupFourSum : public ::testing::Test {
protected:
    static void sortQuad(std::vector<int>& q) {
        EXPECT_EQ(q.size(), 4u);
        std::sort(q.begin(), q.end());
    }

    static std::vector<std::vector<int>> normalize(std::vector<std::vector<int>> qs) {
        for (auto& q : qs) sortQuad(q);
        std::sort(qs.begin(), qs.end());
        return qs;
    }

    static void expectSameQuads(std::vector<std::vector<int>> got,
                               std::vector<std::vector<int>> expected) {
        got = normalize(std::move(got));
        expected = normalize(std::move(expected));
        EXPECT_EQ(got, expected);
    }

    static void expectAllSumToTarget(const std::vector<std::vector<int>>& got, int target) {
        for (const auto& q : got) {
            EXPECT_EQ(q.size(), 4u);
            long long s = 0;
            for (auto x : q) s += x;
            EXPECT_EQ(s, target);
        }
    }
};


TEST_F(SetupFourSum, EmptyInputReturnsEmpty) {
    std::vector<int> input{};
    auto result = four_sum(input, 0);
    EXPECT_TRUE(result.empty());
}

TEST_F(SetupFourSum, FewerThanFourElementsReturnsEmpty) {
    std::vector<int> input{1, 2, 3};
    auto result = four_sum(input, 6);
    EXPECT_TRUE(result.empty());
}

TEST_F(SetupFourSum, ExactlyFourElementsMatch) {
    std::vector<int> input{1, 2, 3, 4};
    auto result = four_sum(input, 10);

    expectSameQuads(result, {{1, 2, 3, 4}});
}

TEST_F(SetupFourSum, ExactlyFourElementsNoMatch) {
    std::vector<int> input{1, 2, 3, 4};
    auto result = four_sum(input, 11);
    EXPECT_TRUE(result.empty());
}


TEST_F(SetupFourSum, ExampleFromCommonFourSumProblem) {
    std::vector<int> input{7, 6, 4, -1, 1, 2};
    auto result = four_sum(input, 16);

    // Order within a quadruplet is not important for verification, so we normalize.
    expectSameQuads(result, {
        {7, 6, 4, -1},
        {7, 6, 1, 2},
    });
}

TEST_F(SetupFourSum, HandlesNegativesAndDuplicatesClassicCase) {
    std::vector<int> input{1, 0, -1, 0, -2, 2};
    auto result = four_sum(input, 0);

    expectSameQuads(result, {
        {-1, 0, 0, 1},
        {-2, -1, 1, 2},
        {-2, 0, 0, 2},
    });
}

TEST_F(SetupFourSum, AllZerosMultiplicity) {
    // 5 zeros: number of index-quadruples is C(5,4)=5.
    // This implementation should return 5 quadruplets (all [0,0,0,0]).
    std::vector<int> input{0, 0, 0, 0, 0};
    auto result = four_sum(input, 0);
    EXPECT_EQ(result.size(), 5u);
    expectAllSumToTarget(result, 0);
}

TEST_F(SetupFourSum, NoSolutionsReturnsEmpty) {
    std::vector<int> input{5, 5, 5, 5, 5};
    auto result = four_sum(input, 123);
    EXPECT_TRUE(result.empty());
}


TEST_F(SetupFourSum, ManySolutionsAllSumCorrectly) {
    std::vector<int> input{-3, -1, 0, 2, 4, 5, 6, 7};
    int target = 10;

    auto result = four_sum(input, target);

    EXPECT_FALSE(result.empty());
    expectAllSumToTarget(result, target);
}
