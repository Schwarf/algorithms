//
// Created by andreas on 19.01.26.
//
// four_sum_test.cpp
#include <gtest/gtest.h>
#include "../four_sum.h"


#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

class SetupFourSum : public ::testing::Test
{
protected:
    static void sortQuad(std::vector<int>& q)
    {
        EXPECT_EQ(q.size(), 4u);
        std::sort(q.begin(), q.end());
    }

    static std::vector<std::vector<int>> normalize(std::vector<std::vector<int>> qs)
    {
        for (auto& q : qs)
            sortQuad(q);
        std::sort(qs.begin(), qs.end());
        return qs;
    }

    static void expectSameQuads(std::vector<std::vector<int>> got, std::vector<std::vector<int>> expected)
    {
        got = normalize(std::move(got));
        expected = normalize(std::move(expected));
        EXPECT_EQ(got, expected);
    }

    static void expectAllSumToTarget(const std::vector<std::vector<int>>& got, int target)
    {
        for (const auto& q : got)
        {
            EXPECT_EQ(q.size(), 4u);
            long long s = 0;
            for (auto x : q)
                s += x;
            EXPECT_EQ(s, target);
        }
    }
};


TEST_F(SetupFourSum, EmptyInputReturnsEmpty)
{
    std::vector<int> input{};
    auto result = four_sum(input, 0);
    EXPECT_TRUE(result.empty());
}

TEST_F(SetupFourSum, FewerThanFourElementsReturnsEmpty)
{
    std::vector<int> input{1, 2, 3};
    auto result = four_sum(input, 6);
    EXPECT_TRUE(result.empty());
}

TEST_F(SetupFourSum, ExactlyFourElementsMatch)
{
    std::vector<int> input{1, 2, 3, 4};
    auto result = four_sum(input, 10);

    expectSameQuads(result, {{1, 2, 3, 4}});
}

TEST_F(SetupFourSum, ExactlyFourElementsNoMatch)
{
    std::vector<int> input{1, 2, 3, 4};
    auto result = four_sum(input, 11);
    EXPECT_TRUE(result.empty());
}


TEST_F(SetupFourSum, ExampleFromCommonFourSumProblem)
{
    std::vector<int> input{7, 6, 4, -1, 1, 2};
    auto result = four_sum(input, 16);

    // Order within a quadruplet is not important for verification, so we normalize.
    expectSameQuads(result,
                    {
                        {7, 6, 4, -1},
                        {7, 6, 1, 2},
                    });
}

TEST_F(SetupFourSum, HandlesNegativesAndDuplicatesClassicCase)
{
    std::vector<int> input{1, 0, -1, 0, -2, 2};
    auto result = four_sum(input, 0);

    expectSameQuads(result,
                    {
                        {-1, 0, 0, 1},
                        {-2, -1, 1, 2},
                        {-2, 0, 0, 2},
                    });
}

TEST_F(SetupFourSum, AllZerosMultiplicity)
{
    // 5 zeros: number of index-quadruples is C(5,4)=5.
    // This implementation should return 5 quadruplets (all [0,0,0,0]).
    std::vector<int> input{0, 0, 0, 0, 0};
    auto result = four_sum(input, 0);
    EXPECT_EQ(result.size(), 5u);
    expectAllSumToTarget(result, 0);
}

TEST_F(SetupFourSum, NoSolutionsReturnsEmpty)
{
    std::vector<int> input{5, 5, 5, 5, 5};
    auto result = four_sum(input, 123);
    EXPECT_TRUE(result.empty());
}


TEST_F(SetupFourSum, ManySolutionsAllSumCorrectly)
{
    std::vector<int> input{-3, -1, 0, 2, 4, 5, 6, 7};
    int target = 10;

    auto result = four_sum(input, target);

    EXPECT_FALSE(result.empty());
    expectAllSumToTarget(result, target);
}

class SetupFourSumUnique : public SetupFourSum
{
};

TEST_F(SetupFourSumUnique, EmptyInputReturnsEmpty)
{
    std::vector<int> input{};
    EXPECT_TRUE(four_sum_unique(input, 0).empty());
}

TEST_F(SetupFourSumUnique, FewerThanFourElementsReturnsEmpty)
{
    for (int size = 1; size < 4; ++size)
    {
        SCOPED_TRACE(size);
        std::vector<int> input(size, 0);
        EXPECT_TRUE(four_sum_unique(input, 0).empty());
    }
}

TEST_F(SetupFourSumUnique, ExactlyFourElementsMatch)
{
    std::vector<int> input{4, 1, 3, 2};
    expectSameQuads(four_sum_unique(input, 10), {{1, 2, 3, 4}});
}

TEST_F(SetupFourSumUnique, ExactlyFourElementsNoMatch)
{
    std::vector<int> input{1, 2, 3, 4};
    EXPECT_TRUE(four_sum_unique(input, 11).empty());
}

TEST_F(SetupFourSumUnique, FindsAllUniqueQuadrupletsInClassicCase)
{
    std::vector<int> input{1, 0, -1, 0, -2, 2};
    expectSameQuads(four_sum_unique(input, 0),
                    {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
}

TEST_F(SetupFourSumUnique, AllZerosReturnOneQuadruplet)
{
    std::vector<int> input{0, 0, 0, 0, 0, 0};
    expectSameQuads(four_sum_unique(input, 0), {{0, 0, 0, 0}});
}

TEST_F(SetupFourSumUnique, AllEqualNonzeroValuesReturnOneQuadruplet)
{
    std::vector<int> input{2, 2, 2, 2, 2, 2};
    expectSameQuads(four_sum_unique(input, 8), {{2, 2, 2, 2}});
}

TEST_F(SetupFourSumUnique, AllEqualValuesWithWrongTargetReturnEmpty)
{
    std::vector<int> input{2, 2, 2, 2, 2, 2};
    EXPECT_TRUE(four_sum_unique(input, 9).empty());
}

TEST_F(SetupFourSumUnique, RepeatedValuesDoNotDuplicateOrHideQuadruplets)
{
    std::vector<int> input{2, -1, 0, -2, 1, 2, -1, 0, -2, 1};
    expectSameQuads(four_sum_unique(input, 0),
                    {
                        {-2, -2, 2, 2},
                        {-2, -1, 1, 2},
                        {-2, 0, 0, 2},
                        {-2, 0, 1, 1},
                        {-1, -1, 0, 2},
                        {-1, -1, 1, 1},
                        {-1, 0, 0, 1},
                    });
}

TEST_F(SetupFourSumUnique, SkipsRepeatedRightValuesAtEndOfInput)
{
    std::vector<int> input{0, 0, 0, 1, 1, 1};
    expectSameQuads(four_sum_unique(input, 1), {{0, 0, 0, 1}});
}

TEST_F(SetupFourSumUnique, DoesNotReuseAnInputElement)
{
    std::vector<int> input{0, 1, 2, 4};
    EXPECT_TRUE(four_sum_unique(input, 8).empty());
}

TEST_F(SetupFourSumUnique, AllPositiveValuesWithPositiveTarget)
{
    std::vector<int> input{5, 1, 4, 2, 3};
    expectSameQuads(four_sum_unique(input, 12), {{1, 2, 4, 5}});
}

TEST_F(SetupFourSumUnique, AllNegativeValuesWithNegativeTarget)
{
    std::vector<int> input{-5, -1, -4, -2, -3};
    expectSameQuads(four_sum_unique(input, -12), {{-5, -4, -2, -1}});
}

TEST_F(SetupFourSumUnique, TargetsOutsidePossibleSumRangeReturnEmpty)
{
    for (int target : {-100, 100})
    {
        SCOPED_TRACE(target);
        std::vector<int> input{-3, -2, -1, 0, 1, 2, 3};
        EXPECT_TRUE(four_sum_unique(input, target).empty());
    }
}

TEST_F(SetupFourSumUnique, FindsQuadrupletWithCancellingIntegerLimits)
{
    constexpr int min = std::numeric_limits<int>::min();
    constexpr int max = std::numeric_limits<int>::max();
    std::vector<int> input{max, min, max, min};
    expectSameQuads(four_sum_unique(input, -2), {{min, min, max, max}});
}

TEST_F(SetupFourSumUnique, HandlesIntegerLimitTargets)
{
    for (int target : {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()})
    {
        SCOPED_TRACE(target);
        std::vector<int> input{0, target, 0, 0};
        expectSameQuads(four_sum_unique(input, target), {{target, 0, 0, 0}});
    }
}

TEST_F(SetupFourSumUnique, PositiveSumOverflowDoesNotProduceFalseMatch)
{
    std::vector<int> input{1'000'000'000, 1'000'000'000, 1'000'000'000, 1'000'000'000};
    EXPECT_TRUE(four_sum_unique(input, -294'967'296).empty());
}

TEST_F(SetupFourSumUnique, NegativeSumOverflowDoesNotProduceFalseMatch)
{
    std::vector<int> input{-1'000'000'000, -1'000'000'000, -1'000'000'000, -1'000'000'000};
    EXPECT_TRUE(four_sum_unique(input, 294'967'296).empty());
}
