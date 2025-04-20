//
// Created by andreas on 20.04.25.
//
#include "./../reorder_log_files.h"
#include "gtest/gtest.h"

TEST(TestReorderLogFiles, simple1)
{
    std::vector<std::string> log_files{"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    std::vector<std::string> expected_result{
        "let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"
    };
    EXPECT_EQ(expected_result, reorder_log_files(log_files));
}

TEST(TestReorderLogFiles, simple2)
{
    std::vector<std::string> log_files{"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    std::vector<std::string> expected_result{"g1 act car", "a8 act zoo", "ab1 off key dog", "a1 9 2 3 1", "zo4 4 7"};
    EXPECT_EQ(expected_result, reorder_log_files(log_files));
}

TEST(TestReorderLogFiles, simple3)
{
    std::vector<std::string> log_files{
        "6p tzwmh ige mc", "ns 566543603829", "ubd cujg j d yf", "ha6 1 938 376 5", "3yx 97 666 56 5",
        "d 84 34353 2249", "0 tllgmf qp znc", "s 1088746413789", "ys0 splqqxoflgx", "uhb rfrwt qzx r", "u lrvmdt ykmox",
        "ah4 4209164350", "rap 7729 8 125", "4 nivgc qo z i", "apx 814023338 8"
    };
    std::vector<std::string> expected_result{
        "ubd cujg j d yf", "u lrvmdt ykmox", "4 nivgc qo z i", "uhb rfrwt qzx r", "ys0 splqqxoflgx", "0 tllgmf qp znc",
        "6p tzwmh ige mc", "ns 566543603829", "ha6 1 938 376 5", "3yx 97 666 56 5", "d 84 34353 2249",
        "s 1088746413789", "ah4 4209164350", "rap 7729 8 125", "apx 814023338 8"
    };
    EXPECT_EQ(expected_result, reorder_log_files(log_files));
}
