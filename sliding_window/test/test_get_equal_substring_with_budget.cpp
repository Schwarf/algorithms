//
// Created by andreas on 17.01.24.
//
#include "./../get_equal_substrings_with_budget.h"
#include "gtest/gtest.h"

TEST(TestGetEqualSubstringsWithBudget, simple1)
{
    const std::string input1{"abcd"};
    const std::string input2{"bcdf"};
    constexpr int budget{3};
    ;
    constexpr int expected_result{3};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}

TEST(TestGetEqualSubstringsWithBudget, simple2)
{
    const std::string input1{"abcd"};
    const std::string input2{"cdef"};
    constexpr int budget{3};
    ;
    constexpr int expected_result{1};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}

TEST(TestGetEqualSubstringsWithBudget, simple3)
{
    const std::string input1{"abcd"};
    const std::string input2{"acde"};
    constexpr int budget{0};
    ;
    constexpr int expected_result{1};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}

TEST(TestGetEqualSubstringsWithBudget, simple4)
{
    const std::string input1{"fkfnkrfunni"};
    const std::string input2{"jyufzxzfbsa"};
    constexpr int budget{18};
    ;
    constexpr int expected_result{2};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}

TEST(TestGetEqualSubstringsWithBudget, simple5)
{
    const std::string input1{"whappqmhrgxhnwcoisgib"};
    const std::string input2{"vozknyobistswxjtobwbh"};
    constexpr int budget{149};
    ;
    constexpr int expected_result{18};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}

TEST(TestGetEqualSubstringsWithBudget, medium1)
{
    const std::string input1{
        "kkujxwtrlwvkkyccrimpiiinzyzcpuqnretofvouicbqwmuypaynwfjztmjugihipeyfasclggdzzofbcfbuazeppmxswdvuzlnwckkzzlqkph"
        "usagqmxfvjlpxgjwoprahezgrrlwtxbbhehvmvwcoyngwsgegcelpgehdzecxsrwozlvtogajxmbqhgljxerdgierc"};
    const std::string input2{
        "jynhwjttmbcelakawdfwqkfhgxxqzvpmsczlklzqnrxkpupmajzfcfgxhgzqzbbgvgmjtaiekkdbdnudnichmricfokewmxtlvdiqmuybpgsmc"
        "dhybwlxdqkhnfjfonilzohukpwztipmuroiknsnodvegbiugxsmcxqccccdcripyfrzqcmqtblowvkkbnagkgsftau"};
    constexpr int budget{715};
    ;
    constexpr int expected_result{94};
    EXPECT_EQ(get_equal_substring_with_budget(input1, input2, budget), expected_result);
}
