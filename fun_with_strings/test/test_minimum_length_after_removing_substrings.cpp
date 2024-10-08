//
// Created by andreas on 08.10.24.
//
#include "gtest/gtest.h"
#include "../minimum_length_after_removing_substrings.h"

TEST(TestMinimumLengthAfterRemovingSubStringsoptimal, simple1)
{
    std::string input{"ABFCACDB"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}

TEST(TestMinimumLengthAfterRemovingSubStringsoptimal, simple2)
{
    std::string input{"ACBBD"};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}

TEST(TestMinimumLengthAfterRemovingSubStringsoptimal, simple3)
{
    std::string input{"QYVBCACACCAACCCCACCCCCACCAAAAAAACCACCAABBDDBDDBBBBBBBDDBDDDDDBDDDDBBDDBDBDWXACACDBDPELYCDUCD"};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestMinimumLengthAfterRemovingSubStringsOptimal, simple1)
{
    std::string input{"ABFCACDB"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}

TEST(TestMinimumLengthAfterRemovingSubStringsOptimal, simple2)
{
    std::string input{"ACBBD"};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}

TEST(TestMinimumLengthAfterRemovingSubStringsOptimal, simple3)
{
    std::string input{"QYVBCACACCAACCCCACCCCCACCAAAAAAACCACCAABBDDBDDBBBBBBBDDBDDDDDBDDDDBBDDBDBDWXACACDBDPELYCDUCD"};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, minimum_length_optimal(input));
}
