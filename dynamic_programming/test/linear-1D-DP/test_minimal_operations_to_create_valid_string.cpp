//
// Created by andreas on 30.07.24.
//
#include "../../linear-1D-DP/minimal_operations_to_create_valid_string.h"
#include "gtest/gtest.h"

TEST(TestMinimalOperationsValiStringDP, simple1)
{
    const std::string input{"aababbab"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

TEST(TestMinimalOperationsValiStringDP, simple2)
{
    const std::string input{"bbaaaaabb"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

TEST(TestMinimalOperationsValiStringDP, simple3)
{
    const std::string input{"bbbbbbbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

TEST(TestMinimalOperationsValiStringDP, simple4)
{
    const std::string input{"aaaaa"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

TEST(TestMinimalOperationsValiStringDP, simple5)
{
    const std::string input{"aaaaabbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

TEST(TestMinimalOperationsValiStringDP, complex1)
{
    const std::string input{
        "aaaabaabbbabaabbabbababaabbbbaabbbababaaaaabbbbabaaaaabbbabbbbaaaabbabbbbbaaaabbabaabaaaaabbaaaabbbbbaaabababb"
        "aabbaabbbbbabbbabbaaaaaaabbbbabbabbabbaabaababbbaababaaaaababbbbabbbbbbbbbabbaaaaababbbbbbbaabbbbbbabaaababbab"
        "bbbbaaabbabbaaaabbabaaaaababbabbbbaaababaaabaaabaaababababbaabbaaaaaabbbbabbaaaababbaaabbbaaaaabbbabbbabbbabbb"
        "bbaabbabbbabbaabaaabbaabaaaaaaaababbbabbaaabaaaaababaabbbaabbbaaabbaabbbbaaaaaabbabbabbbaaabbbbababbbabbbaaaab"
        "bababbabbabaabbbaabbbbaaabbbbbbbaaaaaaaabaabaabaabaaabaaabbabbaabbbbaaababbbaaaabaaaababbbababbbabbbbabbbbbbba"
        "aabbbabaaabaaaaababbbabbbbbabbbababaabbabbbbabbaabbbabbbbabbbabbaaabbaabbbabbbabaabbabababbaaabbaaabbbbbabbbab"
        "bbaabbabbbbbababbbbabbabaaabaabaabbabaaabbaabbaaaaaaababaaaaabbababbababbbbbaababbaaaaaaabaabbbaababbabbbbaaba"
        "aaabbbaaaabababbaaaaabaaaaabbabbaaaabbabbaabbbabaaabbbabaaabbabaabbabbbbbabbaaaabaabbbaabbbabaabababbaabababaa"
        "abaabbbbabababaabbbbbaabaaaabaabbbbabbbbbbabbbabbbabbbaaaaabababbbbbaabbbbabbbbbbbbabbbaabaaaabababaaaaabbaabb"
        "babbaabaabaaaaababbbabbabbabbbbbaaaabbabbaaabaaaababaaabbbbbbbaaaabaaaabaaaabbaabbabbbbbaabbaababbbabbbabbbaba"
        "babbbaabaabbaaaabaabbababbaababaaaaabbaabbabbaaaabbababaababbbaababaabbaaaabababbbaababbaabbabbbbaababbbbabbaa"
        "abaabbbbaaabaabbbabbaaabaabbbaaaaaabbbbbaabaaabaababbbbbaaaababbbaabaaaaaabbbbaabbabbaabbaaabbaababababbababab"
        "aabbabbababaaabbbaabbaaabbbbbbaaabbabbbaabbababbabaababbaabaabbbababbbababbaababaaabaabbaabbbbaaabbbbbabababaa"
        "bbbbbaaaabaaaabaaaaaabbabaababbbaaabbaaaaaaaaaabbbaaababbababbbbbabbbabaabbbbaabbabaaabbababaaababbaabbbabbbaa"
        "aabbabbaababaabaabbbaabbaababbaaabaabbaaaabbabaaababaaaaabbbbbbaabbbbaaababaabbbabaaababbabbbabbbbbabababaabba"
        "aaababbbbaaabbabbaaaaabaabbbabbbaaabaabaababbbbaaabababbabababbaaaabbaaaabbabbbbaababababbaaabaaaabbbabbbaabbb"
        "abaaabaababaabaabbababbbbbabaabaabbbaabbaabbbaaaaabaaaabaaaabbabbabbbabaaaabbabaaaaababbaaaaaababbbabbababbbbb"
        "baaaaaababbbbbababaabaaaaabbbbbbbbbbaaabaaabaaabbabababbbbbabbbabaababaabbaaabbbababbaabbaabaaabababbabbbbaaba"
        "aaaabaaaaabbabaabababaabaababbbabaaabbbbabbaaaabbabababbbabbbbbaabbbbbbbbabaabbabbbaaabbaabbaababbaaaabbabbaaa"
        "bababbbaabaabbbabaabbaabaaaaabaaaaaaaabbbababbbaabababbbaaaabaaaaabaabaaaaababbabbabaaabbbaabbaaabaaaabbabbbba"
        "aaabbbbbabaabbbbabbaababaaabbbaaabbaababbaabbbbbaabbabbbabaababbbbbabbbababbbbabababbbaabbbbaaaabaabbabababbbb"
        "ababababbbababaabbabbbababaabbbbabbabbbaaaabababaababaaabbbbabbbbbabbaabbbbbababbabbbbabbaabaaabaaaabababbaaaa"
        "abbaabbbabbbbbaaaabbaaaabbaababbababaaaabbbaaaaaabbabaabbababababbbbaabaababbabbbbababbabaaababbaabaabaaaababb"
        "aabbaaaaaabaaaababbbabbbaababbbbbaaaabbaaaabaabbbabbbbaaabaababbabaabbbbababaaabbaaabbbaaaaababbabbabbbaaabbba"
        "bbbaabbaaaababbabbaaaaaabbaaaabaaaaaaabaaaabbbabbbbaaabaababbbaaababbbabbbaababbbabbaaababaabbabaaaaaabaabbaaa"
        "abbbaabbaaaaabbbaaaaaabababbbbbbbbaabaabaaabbbbbbaababbbabbababaaaabaabbbabbaaabbbbaaabbaaabbabaaaabaaabbabbaa"
        "babbababbaabbabaaaabbabaaabaababaaaababbaabaabbaaabbbbbabbbbaabaaabbbaaabaababaaaabbaabaaaabaaabaababaabbaaaba"
        "bbbaababaaabaaabaababbabbbbabbabbbaababbbaaaababaabaabbaaabbaabbabaabbabbaabbaaaaaaababaabaaababbbbaabaabbaaba"
        "baabbbababbababbaabaabbbbbbbaaaabbaabaabbaaaaabbabaabbbbbbabaababaaaabbabbbaababaabbbababababababbbaaaaabaaaaa"
        "baabaaabbaaaabbbbbabaaaaababbaababbbbbababbabbbbaaaaabaabbaabaababbabbaaabbbbbaaaabbabaaaababababaabbaababaaba"
        "bbaaaabbaaaabbabaaaaaaaabaababbbbaaabaabababbbbababbbabbbbbaaaabbabaaabbabbbbbbbbaabaabbabbbabaaaaabbbbbabaaab"
        "baaabbbabababaababababaaaabbabaabbbaaababbaaaaaabababaaababaaaaabaaabaaaaaabaaaaabbabababababbaaabababaababbaa"
        "bbaaabababbbbbbabaababbbbbaaabaaaabbbaabaabbbaaabaaaaabababbaabaababaaabaaaabbaabbabaababaababbaaabbabbbaaaaab"
        "bbbabbabbbbaaaaaaaaaabababaaaaababaabaabbbbabaabbbbbabaabaaababbbaaaabaaabbaabaabaabbbabbbbababaaabaaaaabbaaba"
        "ababbbbbabaabbabbbbabababbbaaaaabaaabbabbaaabbbaabaaaaaaaaaaabaaabbaabbaabbbabababbabbababbbbaaabaabbbbabbbaaa"
        "babbbabbaaabbbbbabbbabaabbabaabbabbbbbaababbabbbaaaababaabbbbbbaabbbaababbbaabbbbbaabbaababaabbbbabaaaaababbab"
        "abbbbbaabbaabaaabababbaaaaabaabaaaabbababaaaaabaaabbbaabaaaaabababbaaaababbabbbbabbaaaaaaaabaaabaaababbaaaaaaa"
        "bbaaabbbbabbbbaabaaaaababbbbbaabbbababbaaaaabbbbaabbbaaaaabaabbbaaabbbbbaaaaaaababababbbbaaabaaaaaaabbaabbbaaa"
        "aaaaaaaaabbababaabaaabbaaaabbbbbaabbbbbbbbbbbabaaababbabbbaaaabaabaababbabbabbaababbbbaabbabbbaaaabbbbabbaaaba"
        "aaababbbababaababaaabbbbbbabaaabbbbbbababbbbbaaabbbaaabbabbbbabbabbbbababaabbabbbbbbbbabbbbabbbaababbabbaaabbb"
        "bbababbabaababbaaaaabbaaababaabbbbaaabbbabbaababbabaababababbbababbabbbabbbbbbbbbbaabbaabbbbbbbbbbbbaaabbbaaba"
        "abbabbbbbbaabaaababaaaaaabbbbaabbabbbbabbbbabbbaaaaabaaabaabbaaaaaaaabbbbabbaababbbaaabbabbbaabaabaababbabbbba"
        "abbabaaaaaababaabababaaababababaaaaaababababbababbaabaabababbabaabbaabbabbbbbaaababbabaabaaabbaababbaaabbbbaba"
        "bbbbababaababbbaaabbbbabaabbbbbabbbbabaabbbaababbbbbabbabbabaaaaaabbbabbabababbabaaabbaabaaababbababaabbbbbbab"
        "babbaabaaaabaabaaababaaaaababbababbaabbaaabbbbbababaabbbaaaabaabbabbbbbbbbbabbbbaaaaababbbbabaabbaaabbbaabbbaa"
        "abbabaaaabaaabababbaabbaabaabbabbabaaaababbabbbbbbbbbbabaaabbbaabbbbaabbbabbaabbbabbabbabababaabbbbabbbaabbaaa"
        "aabaaaabbbabaabbbaababaaaabababbabbbaaabaaaabbbbbbaababaababbbbaaabaabbabbaaaaaaaabbbabaaabaababaababaaaaaaaab"
        "aaabbaaaaaaaababbbbbabaabbaabaabbbaaabbaababaaaaaabbbbabbaaabbaaaabaaabaabbbaaaabbabaaababbabbbabbaaabaababbbb"
        "baababaabbbabaabaabababaabbbaababbabbbaabbbaaaaaaaabaababbbaababababababababbababbababababaaaabbbabaabbabbbbbb"
        "abbaaabaaabbaaaaaabbbabaaaabbbaaabaabaaababaaabaaabaaaabbbaabbaaabaaabaaaabbbbbbbaaaaaabababbaabaabbbbbbbaaabb"
        "bbabababbaaaaabbaaaaaababbbbbbaaababaababaaaababaaaabaaabbababbbababaababaabbaabbbabbabbabbbbbbaababbaabaaaabb"
        "aabaabaaabaaababaaabbbbaaaaabaaabbabbaaaabbababbbbbbbbbababbbabbaaaabaaaabbaaaaabaaabbaaabbabbbbaababaabbaaaaa"
        "abbaaababaaaababbbaaabbababaababaabbbaabbabbbbaabbbaaabbabbabbbababaabaabbaaaababbbabbbbbaabbbbabaababbbbaabba"
        "abbaaabbaaaabbaaabbaababaaaaaabaabaabaabbbbbbabbbaabaaabbabbbaabbabbaaaabbbbababbaaaabbbbabbbabbbbabaaaababbbb"
        "bbbababbabbaaabaaaabbaaaabbabaababaababaabbaaababaaabaaabbababbaabaaaababaabbabbbaaabaabbaaaabaaabababbbbababa"
        "bbabbbabbaaabbbbbabababbabaaaabababbaaaabbaaabaaabbbbbaababaaabababaabbbaabbabaabbababbbbaaabbbbbabbababbababb"
        "bbaaababaabbabbabaabaabbbbbbaaabaaaabbaabbbbbabaabaabbabababbbaabbabaababbbaaaaaaabbabababbbabbaaabbbababbabaa"
        "aaaabaababababaabbabbabbaaabbbbabbbbbabbbababababaabbaababbbabaaabbabbbbbbabbabbbabbabbbbabaaaaabbaabbabbbabab"
        "bababaaaaaaabbbabbbbbbabbabababaababbaaaabbbabbbababaabbbbbaaabbaabaabbaaaabbbabbbbbaaabaababbabaababbaaabaaab"
        "aaabbbbabbaabaaabbabababbabaabababaaaaaaabbabbbbbbbaaaabbabbaabbabbbabbaaabbbbaaabababbaabbabbababbaaabaaababb"
        "ababbaaabababbabaaaabbababbbaabaaababbbaabbabababbbbaabbbaababbbbaaabbababbababbaaababbbabbbbabaabbaaababababa"
        "abaabbaaabaaaaaaabbbabbaaaababbabbbbaabbababaabbaabbaaabbaabbabbaaababaaabababaababbbabaabbaabbbbaabbbabaaaaaa"
        "bbaabaabaababaabbbbaaaababbbabbbabbbbbaaaababbaaabbbbabbabaaaabbbbbabbabababaaabbaaaaababbbbabaababbabbaaaaaba"
        "aabbbbabbbabbbaababbbbbabbbbbaaabaaaababaabbabbbaaababbabaaaabaaaabaaaaaaaababbaaaaaabbababaaabbaaababaabbbaaa"
        "bbbbaaababbbbbaabbaaababaaaaaaaaaabbaaabbabbabbbabababbabbbbbbababaabbbbbbbabaabbbabbbaaaaaaaabbababaaababbbaa"
        "abbaababbbaabaaaaababbababbaaaabbbbaabbaabaaabbbbbabbaaaababbbbbabbaabaaabbaaabbaabbbaaaabbbaaaaaabbabababbbaa"
        "aaabbbabbbbbaabbbbbabababababaabbbaaaaabaabbbbaaaaaabbbaaabaaabaaabbbbabaabaaabaabaaabaaaabbabbbaabaaaaaababab"
        "bbabaaabbbbbbbbaaaabbbbbbabbbaaabaaababbabaaabaaaaabbaaaabbaaabaabaaabbbabaaabaababababaabbaaababbbaabbbbbbbbb"
        "babbbbabaaaaaabbababbabbabaaaaaaabbbaaaaaabbbbaabbabbbbbbbbabaabbaaababbaabbabbbbbbbabbabbaaaabababaabbbaaabbb"
        "aaaaabbbabbbaabaabbabbbabaababaaaabbbaababbaababaaaaabbababbbabaaaabbbabaaaaaaaaabbbbbaabaaabbbaabaaaabbbaaaaa"
        "abbaaaaabbabbaaaabbaaaabaabaaabaaabbbabbbabaabbbbaaabaaabbbbbaaaaabbabababaabaaaaabaabaabbaabbbbabbbbaaababbba"
        "aaabbaaababbbaaaaabaababbbabaabababbbabbbbabababaabaaabaabbbbabbbaabaaabababbaababbabbabbbaaabbaaaaaabbbbababb"
        "babaaabbaabaababaaabbabababbbaabaabbbbbabbbbaaaaabaaabbbaabababaaabbbabbababaabbababbbaabbaabaaabbbaabaaabbbbb"
        "bbababababaaaabbbabaaaabbbaabbaababababbaabbbbbaaabbabaabaabaaaabaaabaaaabababbbbababbbaabbabbbbbbaaababbbabba"
        "aabaaabbaaaabbbbaaaabbbbabbabbabbabbbbbaaababbabbaaabaabbabbbaabaaabbbabbaabbbbbbaaaabaabbbaabbaaabbbbbaabbbbb"
        "aaabaababbbbbabbaaaaaaabbbbbbbabaababbbabbabbbaaaabbbaabbaabbbababaaaaabbbbaababbbaabbabaaaaabbaababbbaaabbbaa"
        "bbabaabbabababbbaabbaaaaaabbaabbbaabbbaabbbababbbbbbbabbbbabababbaaabbbbaaaababbbaaabbbaabbababbabbbbbaabaaaaa"
        "aabbbaabaaaaabbbaaaaabaabbabbaabbbbabaababbaabbbabbabaabaababbbaaaaaabaaaabbaababbaaaabbaabbbababbbabbaabbabab"
        "bbbbbabbabaaabaabbabaaabbabbaaabaaaabaabaabaaabbbabbbbbaabababaabbbbabbaaaaaaabbbabbbbaaaabbbababbaaaababaaabb"
        "babaaabaabaaabaabbbbbbaaaaaabaabbabbbbabbbbbbabaabbabababbaabaabaabbabbbabababbbabbabbabbbbbbbaaabbbabaaaaaabb"
        "abbbbabbaaaababbaaabaaaaaababbbbbaaababbaabababbbaaaabbbabbbbaaabbabbabbaaabbbbbababaabaaaaaabbaabbabbbabaaaab"
        "babaaaaaaaaabbabbbabbaaaabbaaaaababbbabaabaaabbaabbaabaababbbaabababaababaabababaababaabaaabbbbaababbaaababbaa"
        "abaabbbababaabaaaabbabaababbabbbbaabbababbabbabbbbbababbaabaabbabaaabbbaaababbaaaabbbaabaabaabaaabbbbababaaaaa"
        "ababababbbababbabbaabaabbabaababbaaabbbaaabaaaabaaabbbbabaaaabbabbbababababbbbbbbbabaaabbbbbbbbbababbbbbbababb"
        "babbbbbaaaababbabaabbababaabaabbababbaaabaaaaaaabaabbbabbaabbbababbbbbbabaababbbbbabababbabaabbbbaabbbaaababab"
        "baaabaababbbbbbababaaaabaaabaaaaabaaabbbabaabbbbbbbaabbaaaabbbaababbbabbbbbaaaaabbbaabbaaabaaabaabbababbabbbba"
        "abbabbababbaaaabbaaabbabbabbabbbbbbbababaabbbaaabaabbaabaaabbabaaaababbabbababbabbbbbabbaababaaabbbbaaabbaabba"
        "baaaaabbbbbaaabaaaaabaaaaababaabaaaabbabbbabbbaabbbabbaaabaabbbbaabbaaabaaabbbbabaababbbbbabaababbbbbaaaabbaaa"
        "abbaaaaababbbabbbbbbabaabbbbbbaabbbabaabbbbbbaababaabbaaabaaaaabbaaaaabbaababaaababbbabbaaaaabaaabbbaabbaabbab"
        "bbbaabbaaabbbbababbaaaabbaaabbabbabaabaaaaabbabababbbbbbbbbbbbbaababaaaabaabaabbbbbbbabaabaabaaabbaabaaababbba"
        "baaaaaaaaabaabbbababbbabbbababbbbaaabbaabaaabbabaaabbaaabaaabbbbbbbbaabbbabbabbbbaababbaaababaabbaaabbaabaabab"
        "bbabaaabaababbababbbaabaabbabbaaabaaaaaababbbbbbabbbaaabaabaaababbbaaaaabbbbbbaabbabbbabbaabbaaabbbabbbabbbaba"
        "baaaaaababbbbaabaabbbababbbaaabaabaabababbaababbabaabaaabbbaaaaabbbababbaabbbabaabaaabbaaaaabbaababaaabaaababa"
        "bbbbbaababbababababbbaabbaaabbbabbabbbbabaaaabbbaaabbbaaabbbbabaaababaabaabbaaaaabaaaaabbaaababbbabbbbaaaaabaa"
        "bbbabaaabbaaabbabbbaaaabbabababbababaabababbbaaaaababababaabbbabbbbbaaaabaabbaaaabbbbbbbbaabbabbbaaabbbbabbaab"
        "bbbbababbbbbabaababaabbaabbbbabbbbbabababbbbbbaabbabbbabbbbbbaaababaabbabbabababaaaaaaababbbabbabaaaaabaaaabab"
        "abaaabaabaabbabbbabaabaabbbaabbbaabbbbaabbbbbababaabaaabaaaaabbabaaaabbbbababaababbaabbbbbabbababaabbaabbaaaba"
        "bbbabbaabbaabababaabaabbbaaaabaabbaaabbbaabaabbaabbbbabbbbaabaaaababbbbbbaaaaaaabaabaaabbbbaaabbbabbabbaabbbab"
        "aaaababbbbabbbababbbaabbbaabbbbababbaabbbbababbbaaaabaababbaabbabbbabbabbbbbabaaaabaaaababaabbababbbabbabbbaab"
        "abbbaabbbbbbabbabbbbabbbabbaabaabbbabbbaaababbaaaaabababbaaabbbaabaabbbbabaabaabbbaaaaabababaabbabbbaaabaaaaaa"
        "babaabbabbaaaaabbaabbabbabbbaaabbaaaaabbaaaaababbbabbbbbbbababbaaaaabaaaabababbbabbabaabbbaaaababababaaabaabaa"
        "aabaabaaaabaaaaabbbbabbbbaabbbababbbbaaaaabaabbabababbabbbbaabbaabaaabbbaaaabababaaabbbabbbabaabaabbabaabbaaab"
        "bbbaabbabababaababbbbbbabaaaabaaabaabbaaababaaaaaabababbabaaaababaaaaaabaaaababbbababbbaaabaabaabaaaaababaaaaa"
        "bbbabaaaaaabbbbbababbbbaaababaaaabbaabbbbbabaababaababbaababbbabaaabbbaaaaabbbaaaabaabbbaabaabaaabababaaababba"
        "bbabaabaaabaabbabaaaabaabbbbbbbbbbbaaababababaabbabababbbabbbbaababbaaaaabbaaabbbbababbabaaabbbbbbbbabbaabaabb"
        "bbbbbbbaabbbabbaabababaaababbababbaabbabbaaabbaabaaababaabaabbbabbabbabbaaaababbbbababbbbbbbbbbbabaababaaabaaa"
        "babbabbbabbabaaaababbbbaaaaabbabbbbaaaabababbaabababababaabbbaabbabbbabbaaaabaabbaaaabbbaabbaaaaabaabababaabba"
        "aaabbababbbaabaabbbaaabbabbbbaabbbbababbbaaaaabbbabbbaaaaabbaabaaabaaababbbbbaaaaabbbabbbbbabaaabbbaabbabaabba"
        "bbbababbaaabbaaabbabbbabaabaaabbaaabbabbbbababbabababbaabbbbabbbabbbaabbaaaaabbbabbaabbaaababbaaabbaabaaaaaaaa"
        "bbabbbbaabaababaabbbbbabbaabbaabbaabaaabaabbaaaaaababbbaabbaaaaabbaabababbabbbbbaaaabbaaabbabbbabbaaaababaabaa"
        "aabaabaabbbbbabbabbbaabbbaaababaaababbabaaabbbbbbbaaaaabaaababbbaabababbbbaaabbaaaaaabababaababaabaaaabbbaabbb"
        "babbbaaabbbabababaabbbaabaabbbabbbbbabbabbabbbbbbbbaaabbbabaababbbbabbaabbabbaabbabbabaaaaabbbbaabbabababbaabb"
        "babbbabaaaaaabbabaabbbaaababbaabbabababbababbababababbbbbabbbabbbabaabbbabaaaaabbabaaaabbbbbabbbaabababbbababa"
        "ababbbbaabaabbbbbbbbabbbbbbbbaabaabbaabbbabbabaabbabbabababaababaabaabababaaabbabaaaababbbbbbbabbabbbbbbbabbab"
        "bbabaababbbbbbbbbaaaaababbbbabbababaaabbababababaabbbbbbbbaaabbaababbababbbababbaabbbbaaabababbbabaabaaaabbaaa"
        "bbbbbbabaaababbabababbabbaaaabaabaabaabbbababbaabbbbbabbaabbbababbbbababaabbaabaababbabbbabbaababaababbaabbabb"
        "aaaaaaaababbbbabbbaaaabbababbabbabbabaaaaabaabaaabbaabbbaaaabbbbababbaabaaaabbbaabbabbaaabbababababababababbbb"
        "baaabababababbbabbabaaaabbaaabbbbabababbbabababbaabbaabbabbbbbbbababbabbbbabaabbababbaaabbbbabbaabbabbbbbbabba"
        "aaaaabbaabaababbaabbaabbabbaabaabaaaaaaaababbbbbabbababbaababababaaabbbbabbababbbabaabbbaabaaaabaaabbaabbbaaaa"
        "aaaaababaaabbbbbaaaaaabbbaababbabbababaaaaaabbbbbbbbaaaabbbbbaabbaaaaabaabbabaaaaabaabbbabbbbbababbbbbbabbbbaa"
        "aabbaaaaaaabbbbbbbaabbbbabbabababaababbbaaabaaabaaaaabababbbabaabbbabaabaabaaabbababbaababbbbbabbaabbaabaabbaa"
        "bbbbaabbaababbaaababbbaabbbbaaabababbbbbbabaabbbbbbabbbaabababbbbaabaabbaaababbaaababaababababbababaababaabbaa"
        "abbaabaaabbabbabbbabbabbbaaaababababaaaabbabaabbbbabbababbabaaaaabbbabbabbbbabaaabbaabaaabbbbabbabbbbbbabbabba"
        "abbbaaabaaababbaaaaaaaaabbbbbaabbbaaaabaabbabbaaabbbaababaababababaaababbbaabbaaabbbabaabaabaaaabaaaababbaaabb"
        "abaabaabbbaaaaaaaabbabbbaababbaabababaaaaabababaababababbbbababababbaaababbbbbbabbbaababababbabaaaaabbbabaabaa"
        "babababaaabbbbbbabbbbabbabbaaaabaaaabbaaaabbaabbbabbabbbabababbaabaabbbabbbbabbbaaabbababaabaabbbaabbbaaabbaab"
        "aabbabababaabbabbbbabaabbabababaabbbabbbbabbbbaababbabbbaabbbbaabbabaaaabaaabaababababbaaabaabbaaaabaaaaaaabaa"
        "aabaaabbbbbbbbaababbbabbabbaaaaaaaabbbaaabababaaaaaabbaabaabaababbbbbabaabbbabaaabbbbabbbabbbbbbbbbbbbbabbbbab"
        "aabbbababbabababbaabbbbbaaaabbababaababbbbbaabaaaababababbbbaaababbbbabaaaabbaaaaababaabaabbbabbbbbaabbbbaaabb"
        "bbbbbabbbababaaabaabbabbbbbaabababbaaabbbabaabbaaabbabaabbbaabbbaabbbaabaabbbbbbbbbbbbabbabbaabbbbbbbbabbababb"
        "baabaabaaaaaaabaabbaabbbbbbaabbbbaaaabbbababbbaababbabbaaaaaabbabbbabbbababbbbbbbbababbaaabbaaaaaaababaaaaaaba"
        "babbabbbbabbaabbabbbbbabbbbbbbaabbbbabababaabaababaaaabaabbbabaabbaabbabbbbabababbbbaaabbaababababbbbabbbbabaa"
        "baabbaaabbabbbbaabbbbabbaaabbbbbbbabababbabbabbabaababaaabbbbbbbbbbabbabaabbbbbbabbaabbabbbbaaaaaaaababbbbabba"
        "bbbbbbabbabaababbaabbabbbaabbaaaababaababbbabaabbababbbbabbababbbbbbabbbbababbababbbbbbababbbabaabbbaaababaaaa"
        "baabbbabbaabbbbaaabbabbaabbbbababababababbabababbbabaaaabbababaaabbbabaabbabbabaaaaabbaaaabbbababababbbabbbbaa"
        "baababaabbbabbaabbbbaaaaaaabaababaabaabbabaaabaabaababbaabbaaabbaabbaabaaababaaabbabbaabaaabaababaaabbbbbbaaab"
        "babbbbabbbabaabaabababbabbbbbaaabbbbabaaabaaaaabbaaabababaaaaabbaaaaaaababababbbabbbbaabaabaabababbaabbbbaabbb"
        "aababbbbbabbaabbabbbbabbbbaabbaababbbaaabbabbabbaabaabbbbbaabaaabaabbaaaaabbaaabbabbaaaaaaaaabbbabbbbbbbbbbbba"
        "babbbabaaaaaabaabbbaaabaabaabababbabbabbaaaaaabaabaaaabbbabbaababbbabaaabbabbaaaabaaaabbaabababbbbbbbababbbbba"
        "bababbbaaabaabbaaaabbbbabbabbbbbbaaabbbbbbbbbbbababaabbbaaabbbaaaaaabbaabaabbababbaabbaababaabbbbaaaabaaaababa"
        "aaabaaaabababaaaaaaaaababababbbbaabbaabaaabaaaabaabbabaababaaaababbbababababbbabbbbbbbbbbbaabbbaaabbabaabababa"
        "babaaabaaaabbaaabbabbaabbbbaaaaaabaabbaababbabbbbabbaababbababababbaaabaabbabaababbabbbbbaaabbbbbbaabbaaaaaaab"
        "babbaabababaabbbbaabbabbaaaaaaaaabbbbababbabbbaabaaababbabbaaaaaabbaaabbbbaaaabbbbaaaabbbababaababbaaaabaaabba"
        "ababbbbbaaabbabbbabbbabaaabbaabaabbaaabaaaaabababbbbbaaababbbababaaaaabbbabbabbaaabbbbababbbbabaabbbbaaababbab"
        "bbaaabbbaaabaababaaaaaaaaaabbbabbabbabaaabaabababaabaaaaaaabaaaabbbbbaaabbbabbaabbbaaababaaabbaababbbbaaaababa"
        "bbabababbaaaaaabaabbaabbbaabbabaabaaaaaaaaaaaaabaabbbabbaaaababbaabaaabbaabaaaababbaabbbaaaabbabbabbbabbbbabaa"
        "aababaabbaaabbbbbabbaababaabbbabababbbbabaaababbabbaaabbbbbaaabaabaababbabbaabaaababbbbaabaabbbbbbabbabbbbaaba"
        "ababbbbbabbbbaaabababababbbaaaababaaaaaaabbaaaababbabbbbbbbbbbaaaabababbabbabbabaabbaaabaabbbbabaaaabbbbabbbab"
        "aabaabbabbbaababbababbbbabbbbabaaaababbaaabbaababbabaaaaaaaababaaaabbbababbbbaababbbbaabbbbaaabaaabbabbabbaabb"
        "bbbababbabbabbbbabbababbaaababbaabaaabbaabbabbabbbbbbbaaabaaabbbbaabbabbaaabbaabbabbaabbbaabbaabbbaaabbaaabbba"
        "abaabbaaaaabbbbaaaababaabbbabababaaaabababbbaabbbbaaababbbabababaababababaaabaabbaabababaaaaabbbabbbbbaaaababb"
        "bababaaabbbabaababaaaabbabababbaabbabbbbabaabaaaabbaabbabbabbbbbaaaabaababbaaaabbabbbbbbbababbabababbbaabaaaab"
        "bbbababbabaaabbbbbababaabbbaaaaababbaabaabbaaabababaabbbbaabbabaabbabbaaababbabababbbbbbabaaaabbabbbaaabbbabbb"
        "abbabbbbbbaabaababaaaabbbaabababbaaaabaabbbbaabbbbbaabbabbbbaaaabbabbaaaaaaabbbbbbbabbbabaaabbbbabbbabbbbbaaaa"
        "aabbbbbabbbaabbbbaabbabbaabbba"};
    constexpr int expected_result{8294};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_dp(input));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestMinimalOperationsValiStringStack, simple1)
{
    const std::string input{"aababbab"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

TEST(TestMinimalOperationsValiStringStack, simple2)
{
    const std::string input{"bbaaaaabb"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

TEST(TestMinimalOperationsValiStringStack, simple3)
{
    const std::string input{"bbbbbbbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

TEST(TestMinimalOperationsValiStringStack, simple4)
{
    const std::string input{"aaaaa"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

TEST(TestMinimalOperationsValiStringStack, simple5)
{
    const std::string input{"aaaaabbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

TEST(TestMinimalOperationsValiStringStack, complex1)
{
    const std::string input{
        "aaaabaabbbabaabbabbababaabbbbaabbbababaaaaabbbbabaaaaabbbabbbbaaaabbabbbbbaaaabbabaabaaaaabbaaaabbbbbaaabababb"
        "aabbaabbbbbabbbabbaaaaaaabbbbabbabbabbaabaababbbaababaaaaababbbbabbbbbbbbbabbaaaaababbbbbbbaabbbbbbabaaababbab"
        "bbbbaaabbabbaaaabbabaaaaababbabbbbaaababaaabaaabaaababababbaabbaaaaaabbbbabbaaaababbaaabbbaaaaabbbabbbabbbabbb"
        "bbaabbabbbabbaabaaabbaabaaaaaaaababbbabbaaabaaaaababaabbbaabbbaaabbaabbbbaaaaaabbabbabbbaaabbbbababbbabbbaaaab"
        "bababbabbabaabbbaabbbbaaabbbbbbbaaaaaaaabaabaabaabaaabaaabbabbaabbbbaaababbbaaaabaaaababbbababbbabbbbabbbbbbba"
        "aabbbabaaabaaaaababbbabbbbbabbbababaabbabbbbabbaabbbabbbbabbbabbaaabbaabbbabbbabaabbabababbaaabbaaabbbbbabbbab"
        "bbaabbabbbbbababbbbabbabaaabaabaabbabaaabbaabbaaaaaaababaaaaabbababbababbbbbaababbaaaaaaabaabbbaababbabbbbaaba"
        "aaabbbaaaabababbaaaaabaaaaabbabbaaaabbabbaabbbabaaabbbabaaabbabaabbabbbbbabbaaaabaabbbaabbbabaabababbaabababaa"
        "abaabbbbabababaabbbbbaabaaaabaabbbbabbbbbbabbbabbbabbbaaaaabababbbbbaabbbbabbbbbbbbabbbaabaaaabababaaaaabbaabb"
        "babbaabaabaaaaababbbabbabbabbbbbaaaabbabbaaabaaaababaaabbbbbbbaaaabaaaabaaaabbaabbabbbbbaabbaababbbabbbabbbaba"
        "babbbaabaabbaaaabaabbababbaababaaaaabbaabbabbaaaabbababaababbbaababaabbaaaabababbbaababbaabbabbbbaababbbbabbaa"
        "abaabbbbaaabaabbbabbaaabaabbbaaaaaabbbbbaabaaabaababbbbbaaaababbbaabaaaaaabbbbaabbabbaabbaaabbaababababbababab"
        "aabbabbababaaabbbaabbaaabbbbbbaaabbabbbaabbababbabaababbaabaabbbababbbababbaababaaabaabbaabbbbaaabbbbbabababaa"
        "bbbbbaaaabaaaabaaaaaabbabaababbbaaabbaaaaaaaaaabbbaaababbababbbbbabbbabaabbbbaabbabaaabbababaaababbaabbbabbbaa"
        "aabbabbaababaabaabbbaabbaababbaaabaabbaaaabbabaaababaaaaabbbbbbaabbbbaaababaabbbabaaababbabbbabbbbbabababaabba"
        "aaababbbbaaabbabbaaaaabaabbbabbbaaabaabaababbbbaaabababbabababbaaaabbaaaabbabbbbaababababbaaabaaaabbbabbbaabbb"
        "abaaabaababaabaabbababbbbbabaabaabbbaabbaabbbaaaaabaaaabaaaabbabbabbbabaaaabbabaaaaababbaaaaaababbbabbababbbbb"
        "baaaaaababbbbbababaabaaaaabbbbbbbbbbaaabaaabaaabbabababbbbbabbbabaababaabbaaabbbababbaabbaabaaabababbabbbbaaba"
        "aaaabaaaaabbabaabababaabaababbbabaaabbbbabbaaaabbabababbbabbbbbaabbbbbbbbabaabbabbbaaabbaabbaababbaaaabbabbaaa"
        "bababbbaabaabbbabaabbaabaaaaabaaaaaaaabbbababbbaabababbbaaaabaaaaabaabaaaaababbabbabaaabbbaabbaaabaaaabbabbbba"
        "aaabbbbbabaabbbbabbaababaaabbbaaabbaababbaabbbbbaabbabbbabaababbbbbabbbababbbbabababbbaabbbbaaaabaabbabababbbb"
        "ababababbbababaabbabbbababaabbbbabbabbbaaaabababaababaaabbbbabbbbbabbaabbbbbababbabbbbabbaabaaabaaaabababbaaaa"
        "abbaabbbabbbbbaaaabbaaaabbaababbababaaaabbbaaaaaabbabaabbababababbbbaabaababbabbbbababbabaaababbaabaabaaaababb"
        "aabbaaaaaabaaaababbbabbbaababbbbbaaaabbaaaabaabbbabbbbaaabaababbabaabbbbababaaabbaaabbbaaaaababbabbabbbaaabbba"
        "bbbaabbaaaababbabbaaaaaabbaaaabaaaaaaabaaaabbbabbbbaaabaababbbaaababbbabbbaababbbabbaaababaabbabaaaaaabaabbaaa"
        "abbbaabbaaaaabbbaaaaaabababbbbbbbbaabaabaaabbbbbbaababbbabbababaaaabaabbbabbaaabbbbaaabbaaabbabaaaabaaabbabbaa"
        "babbababbaabbabaaaabbabaaabaababaaaababbaabaabbaaabbbbbabbbbaabaaabbbaaabaababaaaabbaabaaaabaaabaababaabbaaaba"
        "bbbaababaaabaaabaababbabbbbabbabbbaababbbaaaababaabaabbaaabbaabbabaabbabbaabbaaaaaaababaabaaababbbbaabaabbaaba"
        "baabbbababbababbaabaabbbbbbbaaaabbaabaabbaaaaabbabaabbbbbbabaababaaaabbabbbaababaabbbababababababbbaaaaabaaaaa"
        "baabaaabbaaaabbbbbabaaaaababbaababbbbbababbabbbbaaaaabaabbaabaababbabbaaabbbbbaaaabbabaaaababababaabbaababaaba"
        "bbaaaabbaaaabbabaaaaaaaabaababbbbaaabaabababbbbababbbabbbbbaaaabbabaaabbabbbbbbbbaabaabbabbbabaaaaabbbbbabaaab"
        "baaabbbabababaababababaaaabbabaabbbaaababbaaaaaabababaaababaaaaabaaabaaaaaabaaaaabbabababababbaaabababaababbaa"
        "bbaaabababbbbbbabaababbbbbaaabaaaabbbaabaabbbaaabaaaaabababbaabaababaaabaaaabbaabbabaababaababbaaabbabbbaaaaab"
        "bbbabbabbbbaaaaaaaaaabababaaaaababaabaabbbbabaabbbbbabaabaaababbbaaaabaaabbaabaabaabbbabbbbababaaabaaaaabbaaba"
        "ababbbbbabaabbabbbbabababbbaaaaabaaabbabbaaabbbaabaaaaaaaaaaabaaabbaabbaabbbabababbabbababbbbaaabaabbbbabbbaaa"
        "babbbabbaaabbbbbabbbabaabbabaabbabbbbbaababbabbbaaaababaabbbbbbaabbbaababbbaabbbbbaabbaababaabbbbabaaaaababbab"
        "abbbbbaabbaabaaabababbaaaaabaabaaaabbababaaaaabaaabbbaabaaaaabababbaaaababbabbbbabbaaaaaaaabaaabaaababbaaaaaaa"
        "bbaaabbbbabbbbaabaaaaababbbbbaabbbababbaaaaabbbbaabbbaaaaabaabbbaaabbbbbaaaaaaababababbbbaaabaaaaaaabbaabbbaaa"
        "aaaaaaaaabbababaabaaabbaaaabbbbbaabbbbbbbbbbbabaaababbabbbaaaabaabaababbabbabbaababbbbaabbabbbaaaabbbbabbaaaba"
        "aaababbbababaababaaabbbbbbabaaabbbbbbababbbbbaaabbbaaabbabbbbabbabbbbababaabbabbbbbbbbabbbbabbbaababbabbaaabbb"
        "bbababbabaababbaaaaabbaaababaabbbbaaabbbabbaababbabaababababbbababbabbbabbbbbbbbbbaabbaabbbbbbbbbbbbaaabbbaaba"
        "abbabbbbbbaabaaababaaaaaabbbbaabbabbbbabbbbabbbaaaaabaaabaabbaaaaaaaabbbbabbaababbbaaabbabbbaabaabaababbabbbba"
        "abbabaaaaaababaabababaaababababaaaaaababababbababbaabaabababbabaabbaabbabbbbbaaababbabaabaaabbaababbaaabbbbaba"
        "bbbbababaababbbaaabbbbabaabbbbbabbbbabaabbbaababbbbbabbabbabaaaaaabbbabbabababbabaaabbaabaaababbababaabbbbbbab"
        "babbaabaaaabaabaaababaaaaababbababbaabbaaabbbbbababaabbbaaaabaabbabbbbbbbbbabbbbaaaaababbbbabaabbaaabbbaabbbaa"
        "abbabaaaabaaabababbaabbaabaabbabbabaaaababbabbbbbbbbbbabaaabbbaabbbbaabbbabbaabbbabbabbabababaabbbbabbbaabbaaa"
        "aabaaaabbbabaabbbaababaaaabababbabbbaaabaaaabbbbbbaababaababbbbaaabaabbabbaaaaaaaabbbabaaabaababaababaaaaaaaab"
        "aaabbaaaaaaaababbbbbabaabbaabaabbbaaabbaababaaaaaabbbbabbaaabbaaaabaaabaabbbaaaabbabaaababbabbbabbaaabaababbbb"
        "baababaabbbabaabaabababaabbbaababbabbbaabbbaaaaaaaabaababbbaababababababababbababbababababaaaabbbabaabbabbbbbb"
        "abbaaabaaabbaaaaaabbbabaaaabbbaaabaabaaababaaabaaabaaaabbbaabbaaabaaabaaaabbbbbbbaaaaaabababbaabaabbbbbbbaaabb"
        "bbabababbaaaaabbaaaaaababbbbbbaaababaababaaaababaaaabaaabbababbbababaababaabbaabbbabbabbabbbbbbaababbaabaaaabb"
        "aabaabaaabaaababaaabbbbaaaaabaaabbabbaaaabbababbbbbbbbbababbbabbaaaabaaaabbaaaaabaaabbaaabbabbbbaababaabbaaaaa"
        "abbaaababaaaababbbaaabbababaababaabbbaabbabbbbaabbbaaabbabbabbbababaabaabbaaaababbbabbbbbaabbbbabaababbbbaabba"
        "abbaaabbaaaabbaaabbaababaaaaaabaabaabaabbbbbbabbbaabaaabbabbbaabbabbaaaabbbbababbaaaabbbbabbbabbbbabaaaababbbb"
        "bbbababbabbaaabaaaabbaaaabbabaababaababaabbaaababaaabaaabbababbaabaaaababaabbabbbaaabaabbaaaabaaabababbbbababa"
        "bbabbbabbaaabbbbbabababbabaaaabababbaaaabbaaabaaabbbbbaababaaabababaabbbaabbabaabbababbbbaaabbbbbabbababbababb"
        "bbaaababaabbabbabaabaabbbbbbaaabaaaabbaabbbbbabaabaabbabababbbaabbabaababbbaaaaaaabbabababbbabbaaabbbababbabaa"
        "aaaabaababababaabbabbabbaaabbbbabbbbbabbbababababaabbaababbbabaaabbabbbbbbabbabbbabbabbbbabaaaaabbaabbabbbabab"
        "bababaaaaaaabbbabbbbbbabbabababaababbaaaabbbabbbababaabbbbbaaabbaabaabbaaaabbbabbbbbaaabaababbabaababbaaabaaab"
        "aaabbbbabbaabaaabbabababbabaabababaaaaaaabbabbbbbbbaaaabbabbaabbabbbabbaaabbbbaaabababbaabbabbababbaaabaaababb"
        "ababbaaabababbabaaaabbababbbaabaaababbbaabbabababbbbaabbbaababbbbaaabbababbababbaaababbbabbbbabaabbaaababababa"
        "abaabbaaabaaaaaaabbbabbaaaababbabbbbaabbababaabbaabbaaabbaabbabbaaababaaabababaababbbabaabbaabbbbaabbbabaaaaaa"
        "bbaabaabaababaabbbbaaaababbbabbbabbbbbaaaababbaaabbbbabbabaaaabbbbbabbabababaaabbaaaaababbbbabaababbabbaaaaaba"
        "aabbbbabbbabbbaababbbbbabbbbbaaabaaaababaabbabbbaaababbabaaaabaaaabaaaaaaaababbaaaaaabbababaaabbaaababaabbbaaa"
        "bbbbaaababbbbbaabbaaababaaaaaaaaaabbaaabbabbabbbabababbabbbbbbababaabbbbbbbabaabbbabbbaaaaaaaabbababaaababbbaa"
        "abbaababbbaabaaaaababbababbaaaabbbbaabbaabaaabbbbbabbaaaababbbbbabbaabaaabbaaabbaabbbaaaabbbaaaaaabbabababbbaa"
        "aaabbbabbbbbaabbbbbabababababaabbbaaaaabaabbbbaaaaaabbbaaabaaabaaabbbbabaabaaabaabaaabaaaabbabbbaabaaaaaababab"
        "bbabaaabbbbbbbbaaaabbbbbbabbbaaabaaababbabaaabaaaaabbaaaabbaaabaabaaabbbabaaabaababababaabbaaababbbaabbbbbbbbb"
        "babbbbabaaaaaabbababbabbabaaaaaaabbbaaaaaabbbbaabbabbbbbbbbabaabbaaababbaabbabbbbbbbabbabbaaaabababaabbbaaabbb"
        "aaaaabbbabbbaabaabbabbbabaababaaaabbbaababbaababaaaaabbababbbabaaaabbbabaaaaaaaaabbbbbaabaaabbbaabaaaabbbaaaaa"
        "abbaaaaabbabbaaaabbaaaabaabaaabaaabbbabbbabaabbbbaaabaaabbbbbaaaaabbabababaabaaaaabaabaabbaabbbbabbbbaaababbba"
        "aaabbaaababbbaaaaabaababbbabaabababbbabbbbabababaabaaabaabbbbabbbaabaaabababbaababbabbabbbaaabbaaaaaabbbbababb"
        "babaaabbaabaababaaabbabababbbaabaabbbbbabbbbaaaaabaaabbbaabababaaabbbabbababaabbababbbaabbaabaaabbbaabaaabbbbb"
        "bbababababaaaabbbabaaaabbbaabbaababababbaabbbbbaaabbabaabaabaaaabaaabaaaabababbbbababbbaabbabbbbbbaaababbbabba"
        "aabaaabbaaaabbbbaaaabbbbabbabbabbabbbbbaaababbabbaaabaabbabbbaabaaabbbabbaabbbbbbaaaabaabbbaabbaaabbbbbaabbbbb"
        "aaabaababbbbbabbaaaaaaabbbbbbbabaababbbabbabbbaaaabbbaabbaabbbababaaaaabbbbaababbbaabbabaaaaabbaababbbaaabbbaa"
        "bbabaabbabababbbaabbaaaaaabbaabbbaabbbaabbbababbbbbbbabbbbabababbaaabbbbaaaababbbaaabbbaabbababbabbbbbaabaaaaa"
        "aabbbaabaaaaabbbaaaaabaabbabbaabbbbabaababbaabbbabbabaabaababbbaaaaaabaaaabbaababbaaaabbaabbbababbbabbaabbabab"
        "bbbbbabbabaaabaabbabaaabbabbaaabaaaabaabaabaaabbbabbbbbaabababaabbbbabbaaaaaaabbbabbbbaaaabbbababbaaaababaaabb"
        "babaaabaabaaabaabbbbbbaaaaaabaabbabbbbabbbbbbabaabbabababbaabaabaabbabbbabababbbabbabbabbbbbbbaaabbbabaaaaaabb"
        "abbbbabbaaaababbaaabaaaaaababbbbbaaababbaabababbbaaaabbbabbbbaaabbabbabbaaabbbbbababaabaaaaaabbaabbabbbabaaaab"
        "babaaaaaaaaabbabbbabbaaaabbaaaaababbbabaabaaabbaabbaabaababbbaabababaababaabababaababaabaaabbbbaababbaaababbaa"
        "abaabbbababaabaaaabbabaababbabbbbaabbababbabbabbbbbababbaabaabbabaaabbbaaababbaaaabbbaabaabaabaaabbbbababaaaaa"
        "ababababbbababbabbaabaabbabaababbaaabbbaaabaaaabaaabbbbabaaaabbabbbababababbbbbbbbabaaabbbbbbbbbababbbbbbababb"
        "babbbbbaaaababbabaabbababaabaabbababbaaabaaaaaaabaabbbabbaabbbababbbbbbabaababbbbbabababbabaabbbbaabbbaaababab"
        "baaabaababbbbbbababaaaabaaabaaaaabaaabbbabaabbbbbbbaabbaaaabbbaababbbabbbbbaaaaabbbaabbaaabaaabaabbababbabbbba"
        "abbabbababbaaaabbaaabbabbabbabbbbbbbababaabbbaaabaabbaabaaabbabaaaababbabbababbabbbbbabbaababaaabbbbaaabbaabba"
        "baaaaabbbbbaaabaaaaabaaaaababaabaaaabbabbbabbbaabbbabbaaabaabbbbaabbaaabaaabbbbabaababbbbbabaababbbbbaaaabbaaa"
        "abbaaaaababbbabbbbbbabaabbbbbbaabbbabaabbbbbbaababaabbaaabaaaaabbaaaaabbaababaaababbbabbaaaaabaaabbbaabbaabbab"
        "bbbaabbaaabbbbababbaaaabbaaabbabbabaabaaaaabbabababbbbbbbbbbbbbaababaaaabaabaabbbbbbbabaabaabaaabbaabaaababbba"
        "baaaaaaaaabaabbbababbbabbbababbbbaaabbaabaaabbabaaabbaaabaaabbbbbbbbaabbbabbabbbbaababbaaababaabbaaabbaabaabab"
        "bbabaaabaababbababbbaabaabbabbaaabaaaaaababbbbbbabbbaaabaabaaababbbaaaaabbbbbbaabbabbbabbaabbaaabbbabbbabbbaba"
        "baaaaaababbbbaabaabbbababbbaaabaabaabababbaababbabaabaaabbbaaaaabbbababbaabbbabaabaaabbaaaaabbaababaaabaaababa"
        "bbbbbaababbababababbbaabbaaabbbabbabbbbabaaaabbbaaabbbaaabbbbabaaababaabaabbaaaaabaaaaabbaaababbbabbbbaaaaabaa"
        "bbbabaaabbaaabbabbbaaaabbabababbababaabababbbaaaaababababaabbbabbbbbaaaabaabbaaaabbbbbbbbaabbabbbaaabbbbabbaab"
        "bbbbababbbbbabaababaabbaabbbbabbbbbabababbbbbbaabbabbbabbbbbbaaababaabbabbabababaaaaaaababbbabbabaaaaabaaaabab"
        "abaaabaabaabbabbbabaabaabbbaabbbaabbbbaabbbbbababaabaaabaaaaabbabaaaabbbbababaababbaabbbbbabbababaabbaabbaaaba"
        "bbbabbaabbaabababaabaabbbaaaabaabbaaabbbaabaabbaabbbbabbbbaabaaaababbbbbbaaaaaaabaabaaabbbbaaabbbabbabbaabbbab"
        "aaaababbbbabbbababbbaabbbaabbbbababbaabbbbababbbaaaabaababbaabbabbbabbabbbbbabaaaabaaaababaabbababbbabbabbbaab"
        "abbbaabbbbbbabbabbbbabbbabbaabaabbbabbbaaababbaaaaabababbaaabbbaabaabbbbabaabaabbbaaaaabababaabbabbbaaabaaaaaa"
        "babaabbabbaaaaabbaabbabbabbbaaabbaaaaabbaaaaababbbabbbbbbbababbaaaaabaaaabababbbabbabaabbbaaaababababaaabaabaa"
        "aabaabaaaabaaaaabbbbabbbbaabbbababbbbaaaaabaabbabababbabbbbaabbaabaaabbbaaaabababaaabbbabbbabaabaabbabaabbaaab"
        "bbbaabbabababaababbbbbbabaaaabaaabaabbaaababaaaaaabababbabaaaababaaaaaabaaaababbbababbbaaabaabaabaaaaababaaaaa"
        "bbbabaaaaaabbbbbababbbbaaababaaaabbaabbbbbabaababaababbaababbbabaaabbbaaaaabbbaaaabaabbbaabaabaaabababaaababba"
        "bbabaabaaabaabbabaaaabaabbbbbbbbbbbaaababababaabbabababbbabbbbaababbaaaaabbaaabbbbababbabaaabbbbbbbbabbaabaabb"
        "bbbbbbbaabbbabbaabababaaababbababbaabbabbaaabbaabaaababaabaabbbabbabbabbaaaababbbbababbbbbbbbbbbabaababaaabaaa"
        "babbabbbabbabaaaababbbbaaaaabbabbbbaaaabababbaabababababaabbbaabbabbbabbaaaabaabbaaaabbbaabbaaaaabaabababaabba"
        "aaabbababbbaabaabbbaaabbabbbbaabbbbababbbaaaaabbbabbbaaaaabbaabaaabaaababbbbbaaaaabbbabbbbbabaaabbbaabbabaabba"
        "bbbababbaaabbaaabbabbbabaabaaabbaaabbabbbbababbabababbaabbbbabbbabbbaabbaaaaabbbabbaabbaaababbaaabbaabaaaaaaaa"
        "bbabbbbaabaababaabbbbbabbaabbaabbaabaaabaabbaaaaaababbbaabbaaaaabbaabababbabbbbbaaaabbaaabbabbbabbaaaababaabaa"
        "aabaabaabbbbbabbabbbaabbbaaababaaababbabaaabbbbbbbaaaaabaaababbbaabababbbbaaabbaaaaaabababaababaabaaaabbbaabbb"
        "babbbaaabbbabababaabbbaabaabbbabbbbbabbabbabbbbbbbbaaabbbabaababbbbabbaabbabbaabbabbabaaaaabbbbaabbabababbaabb"
        "babbbabaaaaaabbabaabbbaaababbaabbabababbababbababababbbbbabbbabbbabaabbbabaaaaabbabaaaabbbbbabbbaabababbbababa"
        "ababbbbaabaabbbbbbbbabbbbbbbbaabaabbaabbbabbabaabbabbabababaababaabaabababaaabbabaaaababbbbbbbabbabbbbbbbabbab"
        "bbabaababbbbbbbbbaaaaababbbbabbababaaabbababababaabbbbbbbbaaabbaababbababbbababbaabbbbaaabababbbabaabaaaabbaaa"
        "bbbbbbabaaababbabababbabbaaaabaabaabaabbbababbaabbbbbabbaabbbababbbbababaabbaabaababbabbbabbaababaababbaabbabb"
        "aaaaaaaababbbbabbbaaaabbababbabbabbabaaaaabaabaaabbaabbbaaaabbbbababbaabaaaabbbaabbabbaaabbababababababababbbb"
        "baaabababababbbabbabaaaabbaaabbbbabababbbabababbaabbaabbabbbbbbbababbabbbbabaabbababbaaabbbbabbaabbabbbbbbabba"
        "aaaaabbaabaababbaabbaabbabbaabaabaaaaaaaababbbbbabbababbaababababaaabbbbabbababbbabaabbbaabaaaabaaabbaabbbaaaa"
        "aaaaababaaabbbbbaaaaaabbbaababbabbababaaaaaabbbbbbbbaaaabbbbbaabbaaaaabaabbabaaaaabaabbbabbbbbababbbbbbabbbbaa"
        "aabbaaaaaaabbbbbbbaabbbbabbabababaababbbaaabaaabaaaaabababbbabaabbbabaabaabaaabbababbaababbbbbabbaabbaabaabbaa"
        "bbbbaabbaababbaaababbbaabbbbaaabababbbbbbabaabbbbbbabbbaabababbbbaabaabbaaababbaaababaababababbababaababaabbaa"
        "abbaabaaabbabbabbbabbabbbaaaababababaaaabbabaabbbbabbababbabaaaaabbbabbabbbbabaaabbaabaaabbbbabbabbbbbbabbabba"
        "abbbaaabaaababbaaaaaaaaabbbbbaabbbaaaabaabbabbaaabbbaababaababababaaababbbaabbaaabbbabaabaabaaaabaaaababbaaabb"
        "abaabaabbbaaaaaaaabbabbbaababbaabababaaaaabababaababababbbbababababbaaababbbbbbabbbaababababbabaaaaabbbabaabaa"
        "babababaaabbbbbbabbbbabbabbaaaabaaaabbaaaabbaabbbabbabbbabababbaabaabbbabbbbabbbaaabbababaabaabbbaabbbaaabbaab"
        "aabbabababaabbabbbbabaabbabababaabbbabbbbabbbbaababbabbbaabbbbaabbabaaaabaaabaababababbaaabaabbaaaabaaaaaaabaa"
        "aabaaabbbbbbbbaababbbabbabbaaaaaaaabbbaaabababaaaaaabbaabaabaababbbbbabaabbbabaaabbbbabbbabbbbbbbbbbbbbabbbbab"
        "aabbbababbabababbaabbbbbaaaabbababaababbbbbaabaaaababababbbbaaababbbbabaaaabbaaaaababaabaabbbabbbbbaabbbbaaabb"
        "bbbbbabbbababaaabaabbabbbbbaabababbaaabbbabaabbaaabbabaabbbaabbbaabbbaabaabbbbbbbbbbbbabbabbaabbbbbbbbabbababb"
        "baabaabaaaaaaabaabbaabbbbbbaabbbbaaaabbbababbbaababbabbaaaaaabbabbbabbbababbbbbbbbababbaaabbaaaaaaababaaaaaaba"
        "babbabbbbabbaabbabbbbbabbbbbbbaabbbbabababaabaababaaaabaabbbabaabbaabbabbbbabababbbbaaabbaababababbbbabbbbabaa"
        "baabbaaabbabbbbaabbbbabbaaabbbbbbbabababbabbabbabaababaaabbbbbbbbbbabbabaabbbbbbabbaabbabbbbaaaaaaaababbbbabba"
        "bbbbbbabbabaababbaabbabbbaabbaaaababaababbbabaabbababbbbabbababbbbbbabbbbababbababbbbbbababbbabaabbbaaababaaaa"
        "baabbbabbaabbbbaaabbabbaabbbbababababababbabababbbabaaaabbababaaabbbabaabbabbabaaaaabbaaaabbbababababbbabbbbaa"
        "baababaabbbabbaabbbbaaaaaaabaababaabaabbabaaabaabaababbaabbaaabbaabbaabaaababaaabbabbaabaaabaababaaabbbbbbaaab"
        "babbbbabbbabaabaabababbabbbbbaaabbbbabaaabaaaaabbaaabababaaaaabbaaaaaaababababbbabbbbaabaabaabababbaabbbbaabbb"
        "aababbbbbabbaabbabbbbabbbbaabbaababbbaaabbabbabbaabaabbbbbaabaaabaabbaaaaabbaaabbabbaaaaaaaaabbbabbbbbbbbbbbba"
        "babbbabaaaaaabaabbbaaabaabaabababbabbabbaaaaaabaabaaaabbbabbaababbbabaaabbabbaaaabaaaabbaabababbbbbbbababbbbba"
        "bababbbaaabaabbaaaabbbbabbabbbbbbaaabbbbbbbbbbbababaabbbaaabbbaaaaaabbaabaabbababbaabbaababaabbbbaaaabaaaababa"
        "aaabaaaabababaaaaaaaaababababbbbaabbaabaaabaaaabaabbabaababaaaababbbababababbbabbbbbbbbbbbaabbbaaabbabaabababa"
        "babaaabaaaabbaaabbabbaabbbbaaaaaabaabbaababbabbbbabbaababbababababbaaabaabbabaababbabbbbbaaabbbbbbaabbaaaaaaab"
        "babbaabababaabbbbaabbabbaaaaaaaaabbbbababbabbbaabaaababbabbaaaaaabbaaabbbbaaaabbbbaaaabbbababaababbaaaabaaabba"
        "ababbbbbaaabbabbbabbbabaaabbaabaabbaaabaaaaabababbbbbaaababbbababaaaaabbbabbabbaaabbbbababbbbabaabbbbaaababbab"
        "bbaaabbbaaabaababaaaaaaaaaabbbabbabbabaaabaabababaabaaaaaaabaaaabbbbbaaabbbabbaabbbaaababaaabbaababbbbaaaababa"
        "bbabababbaaaaaabaabbaabbbaabbabaabaaaaaaaaaaaaabaabbbabbaaaababbaabaaabbaabaaaababbaabbbaaaabbabbabbbabbbbabaa"
        "aababaabbaaabbbbbabbaababaabbbabababbbbabaaababbabbaaabbbbbaaabaabaababbabbaabaaababbbbaabaabbbbbbabbabbbbaaba"
        "ababbbbbabbbbaaabababababbbaaaababaaaaaaabbaaaababbabbbbbbbbbbaaaabababbabbabbabaabbaaabaabbbbabaaaabbbbabbbab"
        "aabaabbabbbaababbababbbbabbbbabaaaababbaaabbaababbabaaaaaaaababaaaabbbababbbbaababbbbaabbbbaaabaaabbabbabbaabb"
        "bbbababbabbabbbbabbababbaaababbaabaaabbaabbabbabbbbbbbaaabaaabbbbaabbabbaaabbaabbabbaabbbaabbaabbbaaabbaaabbba"
        "abaabbaaaaabbbbaaaababaabbbabababaaaabababbbaabbbbaaababbbabababaababababaaabaabbaabababaaaaabbbabbbbbaaaababb"
        "bababaaabbbabaababaaaabbabababbaabbabbbbabaabaaaabbaabbabbabbbbbaaaabaababbaaaabbabbbbbbbababbabababbbaabaaaab"
        "bbbababbabaaabbbbbababaabbbaaaaababbaabaabbaaabababaabbbbaabbabaabbabbaaababbabababbbbbbabaaaabbabbbaaabbbabbb"
        "abbabbbbbbaabaababaaaabbbaabababbaaaabaabbbbaabbbbbaabbabbbbaaaabbabbaaaaaaabbbbbbbabbbabaaabbbbabbbabbbbbaaaa"
        "aabbbbbabbbaabbbbaabbabbaabbba"};
    constexpr int expected_result{8294};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_stack(input));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestMinimalOperationsValiStringOptimizedDP, simple1)
{
    const std::string input{"aababbab"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}

TEST(TestMinimalOperationsValiStringOptimizedDP, simple2)
{
    const std::string input{"bbaaaaabb"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}

TEST(TestMinimalOperationsValiStringOptimizedDP, simple3)
{
    const std::string input{"bbbbbbbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}

TEST(TestMinimalOperationsValiStringOptimizedDP, simple4)
{
    const std::string input{"aaaaa"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}

TEST(TestMinimalOperationsValiStringOptimizedDP, simple5)
{
    const std::string input{"aaaaabbb"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}

TEST(TestMinimalOperationsValiStringOptimizedDP, complex1)
{
    const std::string input{
        "aaaabaabbbabaabbabbababaabbbbaabbbababaaaaabbbbabaaaaabbbabbbbaaaabbabbbbbaaaabbabaabaaaaabbaaaabbbbbaaabababb"
        "aabbaabbbbbabbbabbaaaaaaabbbbabbabbabbaabaababbbaababaaaaababbbbabbbbbbbbbabbaaaaababbbbbbbaabbbbbbabaaababbab"
        "bbbbaaabbabbaaaabbabaaaaababbabbbbaaababaaabaaabaaababababbaabbaaaaaabbbbabbaaaababbaaabbbaaaaabbbabbbabbbabbb"
        "bbaabbabbbabbaabaaabbaabaaaaaaaababbbabbaaabaaaaababaabbbaabbbaaabbaabbbbaaaaaabbabbabbbaaabbbbababbbabbbaaaab"
        "bababbabbabaabbbaabbbbaaabbbbbbbaaaaaaaabaabaabaabaaabaaabbabbaabbbbaaababbbaaaabaaaababbbababbbabbbbabbbbbbba"
        "aabbbabaaabaaaaababbbabbbbbabbbababaabbabbbbabbaabbbabbbbabbbabbaaabbaabbbabbbabaabbabababbaaabbaaabbbbbabbbab"
        "bbaabbabbbbbababbbbabbabaaabaabaabbabaaabbaabbaaaaaaababaaaaabbababbababbbbbaababbaaaaaaabaabbbaababbabbbbaaba"
        "aaabbbaaaabababbaaaaabaaaaabbabbaaaabbabbaabbbabaaabbbabaaabbabaabbabbbbbabbaaaabaabbbaabbbabaabababbaabababaa"
        "abaabbbbabababaabbbbbaabaaaabaabbbbabbbbbbabbbabbbabbbaaaaabababbbbbaabbbbabbbbbbbbabbbaabaaaabababaaaaabbaabb"
        "babbaabaabaaaaababbbabbabbabbbbbaaaabbabbaaabaaaababaaabbbbbbbaaaabaaaabaaaabbaabbabbbbbaabbaababbbabbbabbbaba"
        "babbbaabaabbaaaabaabbababbaababaaaaabbaabbabbaaaabbababaababbbaababaabbaaaabababbbaababbaabbabbbbaababbbbabbaa"
        "abaabbbbaaabaabbbabbaaabaabbbaaaaaabbbbbaabaaabaababbbbbaaaababbbaabaaaaaabbbbaabbabbaabbaaabbaababababbababab"
        "aabbabbababaaabbbaabbaaabbbbbbaaabbabbbaabbababbabaababbaabaabbbababbbababbaababaaabaabbaabbbbaaabbbbbabababaa"
        "bbbbbaaaabaaaabaaaaaabbabaababbbaaabbaaaaaaaaaabbbaaababbababbbbbabbbabaabbbbaabbabaaabbababaaababbaabbbabbbaa"
        "aabbabbaababaabaabbbaabbaababbaaabaabbaaaabbabaaababaaaaabbbbbbaabbbbaaababaabbbabaaababbabbbabbbbbabababaabba"
        "aaababbbbaaabbabbaaaaabaabbbabbbaaabaabaababbbbaaabababbabababbaaaabbaaaabbabbbbaababababbaaabaaaabbbabbbaabbb"
        "abaaabaababaabaabbababbbbbabaabaabbbaabbaabbbaaaaabaaaabaaaabbabbabbbabaaaabbabaaaaababbaaaaaababbbabbababbbbb"
        "baaaaaababbbbbababaabaaaaabbbbbbbbbbaaabaaabaaabbabababbbbbabbbabaababaabbaaabbbababbaabbaabaaabababbabbbbaaba"
        "aaaabaaaaabbabaabababaabaababbbabaaabbbbabbaaaabbabababbbabbbbbaabbbbbbbbabaabbabbbaaabbaabbaababbaaaabbabbaaa"
        "bababbbaabaabbbabaabbaabaaaaabaaaaaaaabbbababbbaabababbbaaaabaaaaabaabaaaaababbabbabaaabbbaabbaaabaaaabbabbbba"
        "aaabbbbbabaabbbbabbaababaaabbbaaabbaababbaabbbbbaabbabbbabaababbbbbabbbababbbbabababbbaabbbbaaaabaabbabababbbb"
        "ababababbbababaabbabbbababaabbbbabbabbbaaaabababaababaaabbbbabbbbbabbaabbbbbababbabbbbabbaabaaabaaaabababbaaaa"
        "abbaabbbabbbbbaaaabbaaaabbaababbababaaaabbbaaaaaabbabaabbababababbbbaabaababbabbbbababbabaaababbaabaabaaaababb"
        "aabbaaaaaabaaaababbbabbbaababbbbbaaaabbaaaabaabbbabbbbaaabaababbabaabbbbababaaabbaaabbbaaaaababbabbabbbaaabbba"
        "bbbaabbaaaababbabbaaaaaabbaaaabaaaaaaabaaaabbbabbbbaaabaababbbaaababbbabbbaababbbabbaaababaabbabaaaaaabaabbaaa"
        "abbbaabbaaaaabbbaaaaaabababbbbbbbbaabaabaaabbbbbbaababbbabbababaaaabaabbbabbaaabbbbaaabbaaabbabaaaabaaabbabbaa"
        "babbababbaabbabaaaabbabaaabaababaaaababbaabaabbaaabbbbbabbbbaabaaabbbaaabaababaaaabbaabaaaabaaabaababaabbaaaba"
        "bbbaababaaabaaabaababbabbbbabbabbbaababbbaaaababaabaabbaaabbaabbabaabbabbaabbaaaaaaababaabaaababbbbaabaabbaaba"
        "baabbbababbababbaabaabbbbbbbaaaabbaabaabbaaaaabbabaabbbbbbabaababaaaabbabbbaababaabbbababababababbbaaaaabaaaaa"
        "baabaaabbaaaabbbbbabaaaaababbaababbbbbababbabbbbaaaaabaabbaabaababbabbaaabbbbbaaaabbabaaaababababaabbaababaaba"
        "bbaaaabbaaaabbabaaaaaaaabaababbbbaaabaabababbbbababbbabbbbbaaaabbabaaabbabbbbbbbbaabaabbabbbabaaaaabbbbbabaaab"
        "baaabbbabababaababababaaaabbabaabbbaaababbaaaaaabababaaababaaaaabaaabaaaaaabaaaaabbabababababbaaabababaababbaa"
        "bbaaabababbbbbbabaababbbbbaaabaaaabbbaabaabbbaaabaaaaabababbaabaababaaabaaaabbaabbabaababaababbaaabbabbbaaaaab"
        "bbbabbabbbbaaaaaaaaaabababaaaaababaabaabbbbabaabbbbbabaabaaababbbaaaabaaabbaabaabaabbbabbbbababaaabaaaaabbaaba"
        "ababbbbbabaabbabbbbabababbbaaaaabaaabbabbaaabbbaabaaaaaaaaaaabaaabbaabbaabbbabababbabbababbbbaaabaabbbbabbbaaa"
        "babbbabbaaabbbbbabbbabaabbabaabbabbbbbaababbabbbaaaababaabbbbbbaabbbaababbbaabbbbbaabbaababaabbbbabaaaaababbab"
        "abbbbbaabbaabaaabababbaaaaabaabaaaabbababaaaaabaaabbbaabaaaaabababbaaaababbabbbbabbaaaaaaaabaaabaaababbaaaaaaa"
        "bbaaabbbbabbbbaabaaaaababbbbbaabbbababbaaaaabbbbaabbbaaaaabaabbbaaabbbbbaaaaaaababababbbbaaabaaaaaaabbaabbbaaa"
        "aaaaaaaaabbababaabaaabbaaaabbbbbaabbbbbbbbbbbabaaababbabbbaaaabaabaababbabbabbaababbbbaabbabbbaaaabbbbabbaaaba"
        "aaababbbababaababaaabbbbbbabaaabbbbbbababbbbbaaabbbaaabbabbbbabbabbbbababaabbabbbbbbbbabbbbabbbaababbabbaaabbb"
        "bbababbabaababbaaaaabbaaababaabbbbaaabbbabbaababbabaababababbbababbabbbabbbbbbbbbbaabbaabbbbbbbbbbbbaaabbbaaba"
        "abbabbbbbbaabaaababaaaaaabbbbaabbabbbbabbbbabbbaaaaabaaabaabbaaaaaaaabbbbabbaababbbaaabbabbbaabaabaababbabbbba"
        "abbabaaaaaababaabababaaababababaaaaaababababbababbaabaabababbabaabbaabbabbbbbaaababbabaabaaabbaababbaaabbbbaba"
        "bbbbababaababbbaaabbbbabaabbbbbabbbbabaabbbaababbbbbabbabbabaaaaaabbbabbabababbabaaabbaabaaababbababaabbbbbbab"
        "babbaabaaaabaabaaababaaaaababbababbaabbaaabbbbbababaabbbaaaabaabbabbbbbbbbbabbbbaaaaababbbbabaabbaaabbbaabbbaa"
        "abbabaaaabaaabababbaabbaabaabbabbabaaaababbabbbbbbbbbbabaaabbbaabbbbaabbbabbaabbbabbabbabababaabbbbabbbaabbaaa"
        "aabaaaabbbabaabbbaababaaaabababbabbbaaabaaaabbbbbbaababaababbbbaaabaabbabbaaaaaaaabbbabaaabaababaababaaaaaaaab"
        "aaabbaaaaaaaababbbbbabaabbaabaabbbaaabbaababaaaaaabbbbabbaaabbaaaabaaabaabbbaaaabbabaaababbabbbabbaaabaababbbb"
        "baababaabbbabaabaabababaabbbaababbabbbaabbbaaaaaaaabaababbbaababababababababbababbababababaaaabbbabaabbabbbbbb"
        "abbaaabaaabbaaaaaabbbabaaaabbbaaabaabaaababaaabaaabaaaabbbaabbaaabaaabaaaabbbbbbbaaaaaabababbaabaabbbbbbbaaabb"
        "bbabababbaaaaabbaaaaaababbbbbbaaababaababaaaababaaaabaaabbababbbababaababaabbaabbbabbabbabbbbbbaababbaabaaaabb"
        "aabaabaaabaaababaaabbbbaaaaabaaabbabbaaaabbababbbbbbbbbababbbabbaaaabaaaabbaaaaabaaabbaaabbabbbbaababaabbaaaaa"
        "abbaaababaaaababbbaaabbababaababaabbbaabbabbbbaabbbaaabbabbabbbababaabaabbaaaababbbabbbbbaabbbbabaababbbbaabba"
        "abbaaabbaaaabbaaabbaababaaaaaabaabaabaabbbbbbabbbaabaaabbabbbaabbabbaaaabbbbababbaaaabbbbabbbabbbbabaaaababbbb"
        "bbbababbabbaaabaaaabbaaaabbabaababaababaabbaaababaaabaaabbababbaabaaaababaabbabbbaaabaabbaaaabaaabababbbbababa"
        "bbabbbabbaaabbbbbabababbabaaaabababbaaaabbaaabaaabbbbbaababaaabababaabbbaabbabaabbababbbbaaabbbbbabbababbababb"
        "bbaaababaabbabbabaabaabbbbbbaaabaaaabbaabbbbbabaabaabbabababbbaabbabaababbbaaaaaaabbabababbbabbaaabbbababbabaa"
        "aaaabaababababaabbabbabbaaabbbbabbbbbabbbababababaabbaababbbabaaabbabbbbbbabbabbbabbabbbbabaaaaabbaabbabbbabab"
        "bababaaaaaaabbbabbbbbbabbabababaababbaaaabbbabbbababaabbbbbaaabbaabaabbaaaabbbabbbbbaaabaababbabaababbaaabaaab"
        "aaabbbbabbaabaaabbabababbabaabababaaaaaaabbabbbbbbbaaaabbabbaabbabbbabbaaabbbbaaabababbaabbabbababbaaabaaababb"
        "ababbaaabababbabaaaabbababbbaabaaababbbaabbabababbbbaabbbaababbbbaaabbababbababbaaababbbabbbbabaabbaaababababa"
        "abaabbaaabaaaaaaabbbabbaaaababbabbbbaabbababaabbaabbaaabbaabbabbaaababaaabababaababbbabaabbaabbbbaabbbabaaaaaa"
        "bbaabaabaababaabbbbaaaababbbabbbabbbbbaaaababbaaabbbbabbabaaaabbbbbabbabababaaabbaaaaababbbbabaababbabbaaaaaba"
        "aabbbbabbbabbbaababbbbbabbbbbaaabaaaababaabbabbbaaababbabaaaabaaaabaaaaaaaababbaaaaaabbababaaabbaaababaabbbaaa"
        "bbbbaaababbbbbaabbaaababaaaaaaaaaabbaaabbabbabbbabababbabbbbbbababaabbbbbbbabaabbbabbbaaaaaaaabbababaaababbbaa"
        "abbaababbbaabaaaaababbababbaaaabbbbaabbaabaaabbbbbabbaaaababbbbbabbaabaaabbaaabbaabbbaaaabbbaaaaaabbabababbbaa"
        "aaabbbabbbbbaabbbbbabababababaabbbaaaaabaabbbbaaaaaabbbaaabaaabaaabbbbabaabaaabaabaaabaaaabbabbbaabaaaaaababab"
        "bbabaaabbbbbbbbaaaabbbbbbabbbaaabaaababbabaaabaaaaabbaaaabbaaabaabaaabbbabaaabaababababaabbaaababbbaabbbbbbbbb"
        "babbbbabaaaaaabbababbabbabaaaaaaabbbaaaaaabbbbaabbabbbbbbbbabaabbaaababbaabbabbbbbbbabbabbaaaabababaabbbaaabbb"
        "aaaaabbbabbbaabaabbabbbabaababaaaabbbaababbaababaaaaabbababbbabaaaabbbabaaaaaaaaabbbbbaabaaabbbaabaaaabbbaaaaa"
        "abbaaaaabbabbaaaabbaaaabaabaaabaaabbbabbbabaabbbbaaabaaabbbbbaaaaabbabababaabaaaaabaabaabbaabbbbabbbbaaababbba"
        "aaabbaaababbbaaaaabaababbbabaabababbbabbbbabababaabaaabaabbbbabbbaabaaabababbaababbabbabbbaaabbaaaaaabbbbababb"
        "babaaabbaabaababaaabbabababbbaabaabbbbbabbbbaaaaabaaabbbaabababaaabbbabbababaabbababbbaabbaabaaabbbaabaaabbbbb"
        "bbababababaaaabbbabaaaabbbaabbaababababbaabbbbbaaabbabaabaabaaaabaaabaaaabababbbbababbbaabbabbbbbbaaababbbabba"
        "aabaaabbaaaabbbbaaaabbbbabbabbabbabbbbbaaababbabbaaabaabbabbbaabaaabbbabbaabbbbbbaaaabaabbbaabbaaabbbbbaabbbbb"
        "aaabaababbbbbabbaaaaaaabbbbbbbabaababbbabbabbbaaaabbbaabbaabbbababaaaaabbbbaababbbaabbabaaaaabbaababbbaaabbbaa"
        "bbabaabbabababbbaabbaaaaaabbaabbbaabbbaabbbababbbbbbbabbbbabababbaaabbbbaaaababbbaaabbbaabbababbabbbbbaabaaaaa"
        "aabbbaabaaaaabbbaaaaabaabbabbaabbbbabaababbaabbbabbabaabaababbbaaaaaabaaaabbaababbaaaabbaabbbababbbabbaabbabab"
        "bbbbbabbabaaabaabbabaaabbabbaaabaaaabaabaabaaabbbabbbbbaabababaabbbbabbaaaaaaabbbabbbbaaaabbbababbaaaababaaabb"
        "babaaabaabaaabaabbbbbbaaaaaabaabbabbbbabbbbbbabaabbabababbaabaabaabbabbbabababbbabbabbabbbbbbbaaabbbabaaaaaabb"
        "abbbbabbaaaababbaaabaaaaaababbbbbaaababbaabababbbaaaabbbabbbbaaabbabbabbaaabbbbbababaabaaaaaabbaabbabbbabaaaab"
        "babaaaaaaaaabbabbbabbaaaabbaaaaababbbabaabaaabbaabbaabaababbbaabababaababaabababaababaabaaabbbbaababbaaababbaa"
        "abaabbbababaabaaaabbabaababbabbbbaabbababbabbabbbbbababbaabaabbabaaabbbaaababbaaaabbbaabaabaabaaabbbbababaaaaa"
        "ababababbbababbabbaabaabbabaababbaaabbbaaabaaaabaaabbbbabaaaabbabbbababababbbbbbbbabaaabbbbbbbbbababbbbbbababb"
        "babbbbbaaaababbabaabbababaabaabbababbaaabaaaaaaabaabbbabbaabbbababbbbbbabaababbbbbabababbabaabbbbaabbbaaababab"
        "baaabaababbbbbbababaaaabaaabaaaaabaaabbbabaabbbbbbbaabbaaaabbbaababbbabbbbbaaaaabbbaabbaaabaaabaabbababbabbbba"
        "abbabbababbaaaabbaaabbabbabbabbbbbbbababaabbbaaabaabbaabaaabbabaaaababbabbababbabbbbbabbaababaaabbbbaaabbaabba"
        "baaaaabbbbbaaabaaaaabaaaaababaabaaaabbabbbabbbaabbbabbaaabaabbbbaabbaaabaaabbbbabaababbbbbabaababbbbbaaaabbaaa"
        "abbaaaaababbbabbbbbbabaabbbbbbaabbbabaabbbbbbaababaabbaaabaaaaabbaaaaabbaababaaababbbabbaaaaabaaabbbaabbaabbab"
        "bbbaabbaaabbbbababbaaaabbaaabbabbabaabaaaaabbabababbbbbbbbbbbbbaababaaaabaabaabbbbbbbabaabaabaaabbaabaaababbba"
        "baaaaaaaaabaabbbababbbabbbababbbbaaabbaabaaabbabaaabbaaabaaabbbbbbbbaabbbabbabbbbaababbaaababaabbaaabbaabaabab"
        "bbabaaabaababbababbbaabaabbabbaaabaaaaaababbbbbbabbbaaabaabaaababbbaaaaabbbbbbaabbabbbabbaabbaaabbbabbbabbbaba"
        "baaaaaababbbbaabaabbbababbbaaabaabaabababbaababbabaabaaabbbaaaaabbbababbaabbbabaabaaabbaaaaabbaababaaabaaababa"
        "bbbbbaababbababababbbaabbaaabbbabbabbbbabaaaabbbaaabbbaaabbbbabaaababaabaabbaaaaabaaaaabbaaababbbabbbbaaaaabaa"
        "bbbabaaabbaaabbabbbaaaabbabababbababaabababbbaaaaababababaabbbabbbbbaaaabaabbaaaabbbbbbbbaabbabbbaaabbbbabbaab"
        "bbbbababbbbbabaababaabbaabbbbabbbbbabababbbbbbaabbabbbabbbbbbaaababaabbabbabababaaaaaaababbbabbabaaaaabaaaabab"
        "abaaabaabaabbabbbabaabaabbbaabbbaabbbbaabbbbbababaabaaabaaaaabbabaaaabbbbababaababbaabbbbbabbababaabbaabbaaaba"
        "bbbabbaabbaabababaabaabbbaaaabaabbaaabbbaabaabbaabbbbabbbbaabaaaababbbbbbaaaaaaabaabaaabbbbaaabbbabbabbaabbbab"
        "aaaababbbbabbbababbbaabbbaabbbbababbaabbbbababbbaaaabaababbaabbabbbabbabbbbbabaaaabaaaababaabbababbbabbabbbaab"
        "abbbaabbbbbbabbabbbbabbbabbaabaabbbabbbaaababbaaaaabababbaaabbbaabaabbbbabaabaabbbaaaaabababaabbabbbaaabaaaaaa"
        "babaabbabbaaaaabbaabbabbabbbaaabbaaaaabbaaaaababbbabbbbbbbababbaaaaabaaaabababbbabbabaabbbaaaababababaaabaabaa"
        "aabaabaaaabaaaaabbbbabbbbaabbbababbbbaaaaabaabbabababbabbbbaabbaabaaabbbaaaabababaaabbbabbbabaabaabbabaabbaaab"
        "bbbaabbabababaababbbbbbabaaaabaaabaabbaaababaaaaaabababbabaaaababaaaaaabaaaababbbababbbaaabaabaabaaaaababaaaaa"
        "bbbabaaaaaabbbbbababbbbaaababaaaabbaabbbbbabaababaababbaababbbabaaabbbaaaaabbbaaaabaabbbaabaabaaabababaaababba"
        "bbabaabaaabaabbabaaaabaabbbbbbbbbbbaaababababaabbabababbbabbbbaababbaaaaabbaaabbbbababbabaaabbbbbbbbabbaabaabb"
        "bbbbbbbaabbbabbaabababaaababbababbaabbabbaaabbaabaaababaabaabbbabbabbabbaaaababbbbababbbbbbbbbbbabaababaaabaaa"
        "babbabbbabbabaaaababbbbaaaaabbabbbbaaaabababbaabababababaabbbaabbabbbabbaaaabaabbaaaabbbaabbaaaaabaabababaabba"
        "aaabbababbbaabaabbbaaabbabbbbaabbbbababbbaaaaabbbabbbaaaaabbaabaaabaaababbbbbaaaaabbbabbbbbabaaabbbaabbabaabba"
        "bbbababbaaabbaaabbabbbabaabaaabbaaabbabbbbababbabababbaabbbbabbbabbbaabbaaaaabbbabbaabbaaababbaaabbaabaaaaaaaa"
        "bbabbbbaabaababaabbbbbabbaabbaabbaabaaabaabbaaaaaababbbaabbaaaaabbaabababbabbbbbaaaabbaaabbabbbabbaaaababaabaa"
        "aabaabaabbbbbabbabbbaabbbaaababaaababbabaaabbbbbbbaaaaabaaababbbaabababbbbaaabbaaaaaabababaababaabaaaabbbaabbb"
        "babbbaaabbbabababaabbbaabaabbbabbbbbabbabbabbbbbbbbaaabbbabaababbbbabbaabbabbaabbabbabaaaaabbbbaabbabababbaabb"
        "babbbabaaaaaabbabaabbbaaababbaabbabababbababbababababbbbbabbbabbbabaabbbabaaaaabbabaaaabbbbbabbbaabababbbababa"
        "ababbbbaabaabbbbbbbbabbbbbbbbaabaabbaabbbabbabaabbabbabababaababaabaabababaaabbabaaaababbbbbbbabbabbbbbbbabbab"
        "bbabaababbbbbbbbbaaaaababbbbabbababaaabbababababaabbbbbbbbaaabbaababbababbbababbaabbbbaaabababbbabaabaaaabbaaa"
        "bbbbbbabaaababbabababbabbaaaabaabaabaabbbababbaabbbbbabbaabbbababbbbababaabbaabaababbabbbabbaababaababbaabbabb"
        "aaaaaaaababbbbabbbaaaabbababbabbabbabaaaaabaabaaabbaabbbaaaabbbbababbaabaaaabbbaabbabbaaabbababababababababbbb"
        "baaabababababbbabbabaaaabbaaabbbbabababbbabababbaabbaabbabbbbbbbababbabbbbabaabbababbaaabbbbabbaabbabbbbbbabba"
        "aaaaabbaabaababbaabbaabbabbaabaabaaaaaaaababbbbbabbababbaababababaaabbbbabbababbbabaabbbaabaaaabaaabbaabbbaaaa"
        "aaaaababaaabbbbbaaaaaabbbaababbabbababaaaaaabbbbbbbbaaaabbbbbaabbaaaaabaabbabaaaaabaabbbabbbbbababbbbbbabbbbaa"
        "aabbaaaaaaabbbbbbbaabbbbabbabababaababbbaaabaaabaaaaabababbbabaabbbabaabaabaaabbababbaababbbbbabbaabbaabaabbaa"
        "bbbbaabbaababbaaababbbaabbbbaaabababbbbbbabaabbbbbbabbbaabababbbbaabaabbaaababbaaababaababababbababaababaabbaa"
        "abbaabaaabbabbabbbabbabbbaaaababababaaaabbabaabbbbabbababbabaaaaabbbabbabbbbabaaabbaabaaabbbbabbabbbbbbabbabba"
        "abbbaaabaaababbaaaaaaaaabbbbbaabbbaaaabaabbabbaaabbbaababaababababaaababbbaabbaaabbbabaabaabaaaabaaaababbaaabb"
        "abaabaabbbaaaaaaaabbabbbaababbaabababaaaaabababaababababbbbababababbaaababbbbbbabbbaababababbabaaaaabbbabaabaa"
        "babababaaabbbbbbabbbbabbabbaaaabaaaabbaaaabbaabbbabbabbbabababbaabaabbbabbbbabbbaaabbababaabaabbbaabbbaaabbaab"
        "aabbabababaabbabbbbabaabbabababaabbbabbbbabbbbaababbabbbaabbbbaabbabaaaabaaabaababababbaaabaabbaaaabaaaaaaabaa"
        "aabaaabbbbbbbbaababbbabbabbaaaaaaaabbbaaabababaaaaaabbaabaabaababbbbbabaabbbabaaabbbbabbbabbbbbbbbbbbbbabbbbab"
        "aabbbababbabababbaabbbbbaaaabbababaababbbbbaabaaaababababbbbaaababbbbabaaaabbaaaaababaabaabbbabbbbbaabbbbaaabb"
        "bbbbbabbbababaaabaabbabbbbbaabababbaaabbbabaabbaaabbabaabbbaabbbaabbbaabaabbbbbbbbbbbbabbabbaabbbbbbbbabbababb"
        "baabaabaaaaaaabaabbaabbbbbbaabbbbaaaabbbababbbaababbabbaaaaaabbabbbabbbababbbbbbbbababbaaabbaaaaaaababaaaaaaba"
        "babbabbbbabbaabbabbbbbabbbbbbbaabbbbabababaabaababaaaabaabbbabaabbaabbabbbbabababbbbaaabbaababababbbbabbbbabaa"
        "baabbaaabbabbbbaabbbbabbaaabbbbbbbabababbabbabbabaababaaabbbbbbbbbbabbabaabbbbbbabbaabbabbbbaaaaaaaababbbbabba"
        "bbbbbbabbabaababbaabbabbbaabbaaaababaababbbabaabbababbbbabbababbbbbbabbbbababbababbbbbbababbbabaabbbaaababaaaa"
        "baabbbabbaabbbbaaabbabbaabbbbababababababbabababbbabaaaabbababaaabbbabaabbabbabaaaaabbaaaabbbababababbbabbbbaa"
        "baababaabbbabbaabbbbaaaaaaabaababaabaabbabaaabaabaababbaabbaaabbaabbaabaaababaaabbabbaabaaabaababaaabbbbbbaaab"
        "babbbbabbbabaabaabababbabbbbbaaabbbbabaaabaaaaabbaaabababaaaaabbaaaaaaababababbbabbbbaabaabaabababbaabbbbaabbb"
        "aababbbbbabbaabbabbbbabbbbaabbaababbbaaabbabbabbaabaabbbbbaabaaabaabbaaaaabbaaabbabbaaaaaaaaabbbabbbbbbbbbbbba"
        "babbbabaaaaaabaabbbaaabaabaabababbabbabbaaaaaabaabaaaabbbabbaababbbabaaabbabbaaaabaaaabbaabababbbbbbbababbbbba"
        "bababbbaaabaabbaaaabbbbabbabbbbbbaaabbbbbbbbbbbababaabbbaaabbbaaaaaabbaabaabbababbaabbaababaabbbbaaaabaaaababa"
        "aaabaaaabababaaaaaaaaababababbbbaabbaabaaabaaaabaabbabaababaaaababbbababababbbabbbbbbbbbbbaabbbaaabbabaabababa"
        "babaaabaaaabbaaabbabbaabbbbaaaaaabaabbaababbabbbbabbaababbababababbaaabaabbabaababbabbbbbaaabbbbbbaabbaaaaaaab"
        "babbaabababaabbbbaabbabbaaaaaaaaabbbbababbabbbaabaaababbabbaaaaaabbaaabbbbaaaabbbbaaaabbbababaababbaaaabaaabba"
        "ababbbbbaaabbabbbabbbabaaabbaabaabbaaabaaaaabababbbbbaaababbbababaaaaabbbabbabbaaabbbbababbbbabaabbbbaaababbab"
        "bbaaabbbaaabaababaaaaaaaaaabbbabbabbabaaabaabababaabaaaaaaabaaaabbbbbaaabbbabbaabbbaaababaaabbaababbbbaaaababa"
        "bbabababbaaaaaabaabbaabbbaabbabaabaaaaaaaaaaaaabaabbbabbaaaababbaabaaabbaabaaaababbaabbbaaaabbabbabbbabbbbabaa"
        "aababaabbaaabbbbbabbaababaabbbabababbbbabaaababbabbaaabbbbbaaabaabaababbabbaabaaababbbbaabaabbbbbbabbabbbbaaba"
        "ababbbbbabbbbaaabababababbbaaaababaaaaaaabbaaaababbabbbbbbbbbbaaaabababbabbabbabaabbaaabaabbbbabaaaabbbbabbbab"
        "aabaabbabbbaababbababbbbabbbbabaaaababbaaabbaababbabaaaaaaaababaaaabbbababbbbaababbbbaabbbbaaabaaabbabbabbaabb"
        "bbbababbabbabbbbabbababbaaababbaabaaabbaabbabbabbbbbbbaaabaaabbbbaabbabbaaabbaabbabbaabbbaabbaabbbaaabbaaabbba"
        "abaabbaaaaabbbbaaaababaabbbabababaaaabababbbaabbbbaaababbbabababaababababaaabaabbaabababaaaaabbbabbbbbaaaababb"
        "bababaaabbbabaababaaaabbabababbaabbabbbbabaabaaaabbaabbabbabbbbbaaaabaababbaaaabbabbbbbbbababbabababbbaabaaaab"
        "bbbababbabaaabbbbbababaabbbaaaaababbaabaabbaaabababaabbbbaabbabaabbabbaaababbabababbbbbbabaaaabbabbbaaabbbabbb"
        "abbabbbbbbaabaababaaaabbbaabababbaaaabaabbbbaabbbbbaabbabbbbaaaabbabbaaaaaaabbbbbbbabbbabaaabbbbabbbabbbbbaaaa"
        "aabbbbbabbbaabbbbaabbabbaabbba"};
    constexpr int expected_result{8294};
    EXPECT_EQ(expected_result, operations_to_create_valid_string_optimized_dp(input));
}
