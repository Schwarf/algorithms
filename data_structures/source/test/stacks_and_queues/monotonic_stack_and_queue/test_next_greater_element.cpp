#include <vector>

#include "gtest/gtest.h"
#include "stacks_and_queues/monotonic_stack_and_queue/next_greater_element.h"

namespace
{
void expect_next_greater_element(const std::vector<int>& input, const std::vector<int>& expected)
{
    EXPECT_EQ(expected, next_greater_element_brute_force(input));
    EXPECT_EQ(expected, next_greater_element(input));
}
}

TEST(NextGreaterElement, EmptyInput)
{
    expect_next_greater_element({}, {});
}

TEST(NextGreaterElement, SingleElementHasNoGreaterValue)
{
    expect_next_greater_element({42}, {-1});
}

TEST(NextGreaterElement, AllEqualElementsHaveNoStrictlyGreaterValue)
{
    expect_next_greater_element({7, 7, 7, 7}, {-1, -1, -1, -1});
}

TEST(NextGreaterElement, StrictlyIncreasingUsesRightNeighborAndCircularMaximum)
{
    expect_next_greater_element({1, 2, 3, 4}, {2, 3, 4, -1});
}

TEST(NextGreaterElement, StrictlyDecreasingUsesCircularWraparound)
{
    expect_next_greater_element({4, 3, 2, 1}, {-1, 4, 4, 4});
}

TEST(NextGreaterElement, MixedValuesWithDuplicates)
{
    expect_next_greater_element({2, 1, 2, 4, 3}, {4, 2, 4, -1, 4});
}

TEST(NextGreaterElement, HandlesNegativeValues)
{
    expect_next_greater_element({-2, -1, -3, 0}, {-1, 0, 0, -1});
}

TEST(NextGreaterElement, DuplicatedMaximumsAreNotGreaterThanEachOther)
{
    expect_next_greater_element({5, 1, 5, 3}, {-1, 5, -1, 5});
}
