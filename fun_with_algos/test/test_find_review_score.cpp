//
// Created by andreas on 13.03.25.
//
#include "./../find_review_score.h"
#include "gtest/gtest.h"

TEST(TestFindReviewScore, simple1)
{
    std::vector<std::string> prohibited_words{"crap", "odpro"};
    std::string review{"GoodProductButScrapAfterWash"};
    constexpr int expected_result{15};
    EXPECT_EQ(expected_result, find_review_score(review, prohibited_words));
}