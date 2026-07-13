//
// Created by andreas on 12.01.24.
//
#include "gtest/gtest.h"
#include "number_of_substrings.h"

TEST(TestNumberOfSubstrings, simple1)
{
    const std::string input{"abcabc"};
    constexpr int expected_result{10};
    EXPECT_EQ(expected_result, number_of_substrings(input));
}

TEST(TestNumberOfSubstrings, simple2)
{
    const std::string input{"abc"};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_substrings(input));
}

TEST(TestNumberOfSubstrings, simple3)
{
    const std::string input{"def"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, number_of_substrings(input));
}

TEST(TestNumberOfSubstrings, medium1)
{
    const std::string input{"abcabcbacababccbcbabaccabababcbcccbccbababbbabaaababcab"};
    constexpr int expected_result{1273};
    EXPECT_EQ(expected_result, number_of_substrings(input));
}

TEST(TestNumberOfSubstrings, complex1)
{
    const std::string input{
        "aacbacaaabababacabbaaabcacbccbbcbbbaabbbbababccacbaaabaacabcccbcacccbaccabccbccbacbaaabaabbcabcbaacacacbacccab"
        "abaaccbcabacbbcbabcbbaaabcabbabcabcbccbcaacaaaaacabbccbbbbabaccbaccabababaabaccbaccacabbbccabbaabaccaabaaaacba"
        "abacaacabbcbcbcbbaacbaaabccbbbbbaabcbabacccbcbbacabaabababacccbabbababcbabaccccaaaaababcacaacabbbbaacbaccaaaab"
        "bacccbaaaccabcccccaabbcaaccabacbbcbcbcbabbabbacbcaacbcacaabbbcbacaabaacbccbcccaabbcbacbbccccbcaaaccbacabbcbcba"
        "cccbcaacccbaabbaccabcbccbbcaccacabcabcaaccccababbbabbacbaabccbacbbabccaacbcaaccabaabacabbcbcbacbbbaacbabaaacca"
        "cbcccaacbcbbccbcbaabcbbbcbbcccbacbbacabccccccabccbccbcabcccabcacbcbbbcccccabcaccbcabccacbbaacabbcbccbabbbabcab"
        "caccbabacbaaccacabccbcbacaabbaacccbbcccaabccccbbccabcbabbcbcabccacacbbbabaaccacbccacbbcaaacbbbbaacaccbaaabbbaa"
        "aacaacabccccbbcbaccaaababbbaaabbccbabcbbbcaaaaaabbbcbabacaaabaccacbbaabcbaacacaababaaabcacbcacbbbcbbccaaaccabb"
        "cccccabcbcaccbcacbcccabaaaaabaacacbcbabaacabcabcbaccbabbababacbbcabbacbabaccabbcbcbaacbcccccccabcaabbcbabbacaa"
        "bccbbbbbbbccccacaabcbbcabbbbbcbacaaacbcbacccbbcbbbbcbccaaabcacaaabccaaccbcaabaccccaaacacbacbbcbaacbabbcbcabcab"
        "baaccbcbabccccbabbaabcccacabccbccccbcbccbcccbbbacbcacabcabcccabbbbccaaaabbbbbccbbbbabbabaaabbacbbbcbcbcbbbbacb"
        "bcbaaaaaacaabababccaaabcacacbbacacccbccabcbabcaaccabacbbccbbacbaabccaacbbccbbccacbbaaccbcbaccbbaacbbcabaababcc"
        "cacccabbbbcbbbabbcbabacacccbcaacbccacabcbbbaaacbaacccacacaacacccbbbaabcaacabccbbcccbaabbaabaccabaacabbabcabaaa"
        "bbcccaacbbacbabccacbbacccccbcbcbbacbcaaccaaaabbcabcbcbbabcacbaccbccccccacbbcaaacacabbbbaabbbacabbccccacacabcca"
        "babccbbbbbcbaabacccaaacaccbcbccbbcacaacbaaacbbcbbccacbbbbbbbcacccaabcacacccbbcacababcabcaaabbcacbcbbbcccabbbca"
        "cbbaaabbaacaabbccbaacababbcccaccbacabacabcaaccaabcacabaaccaccccccaabbaccabacacbacaaabbbcbacaccbccbcbcacbcbabbb"
        "abcbaccacbbabbbbbbcbaaabaaacccacbcacacbbcaacaacaacbbbcaccacccaababaccbbcaabcabbcbacbacbabccacbbbcaabaacaabccac"
        "accbacabccaccbcacaacbcbccabacaccccabbcbbbbacaacabababccbaaaccabbaaccacbcbaabccababacaabbaccacbabcccbbbbbacbabb"
        "ccbacccbacbbbcaccaaccaabbbcacbcabcacbbccaabbaacacabbcbbbbcbacacabbcbccaacabbaabcccbaaabcbaccbacacbbbcaabbcaabb"
        "cacaccccccbaaaacaccacbbaabbbccbacaabaabcaaaacaacaabbabcbbbcaacaaccbcbcbbabaacccccbccbbacbaccbcccccbccccbcbabcc"
        "bcbccbbbacabbbacbacbbccabbacababccabbabbbcaacabaccaacbbcbaacccaccccbbbbbcbaabacacacaacbbacacbccbacccbbbacaabbc"
        "bcbbcaccbccbbabacbacaccccbbbaaaccccaabaaaacabccaaaaacbbacacababbcccbaaabaaccbabbbaacaccaaaaabaabcaabaaacbbacab"
        "aacaaaaaccaacabcbcbacacbabbbbccbcbababbaccaaabbcbbbbbbbbbbcabababcacccaabccaaaacbabcbabbbabacbbaacbacabcaacacb"
        "cbcbcccbbcaababccaaabbcbabaabccaaaaabcbaaaabccccccbbccbacbababaaaaaaabbaabacaccaabccacbaccccaabbcaabbcbabacbcc"
        "ccbcbcabbbabaccbaababbbbbbabacbaabbcabbcccbcbcbcabababbccccabbabcaaccaacaaccbcbcbcaccbbabccccbaccbacbbbaccccba"
        "bbaaababcbacbbacacabcacabbabbaabaacccbaccbbbccbacccbcabcacababbccccacbbcbbaaacaacbabbabbccacacbbbbbacbaacacaca"
        "bbbbcabacbbbbbcaabcbccbcababacaaabcaacabababcbbbabbcbbccbccbbbaabababacacbbbcccbccbccbbbcbcaaacacaabcabbabbbcc"
        "cbababbcbcaabcbccaaacbbacbabababaaccababbbccccbaaaacaaabccababccccbcaabaaacbcbacaacbcaabcabcbabbacbacaacaccbab"
        "caaaabbabcccccbcbabbcbbbbbcaaaaaaaacbbcbcaaacaabbbaaccbbbccacbaccbcabaaccabaabaababcabacbabcccaacccbcccbacbbcb"
        "baaacccbaabaaacccaacbaabbcacbcbbcaccabcbbabbbbcabcaccbbbccabccbccbcccbbcabaaababbbcbaacababbccbcbacacabcabbacb"
        "cccacbaacbccccccbacbcbccaaaacaaaccbaacaaaacbccbbcabcaacbaabcbbbbaaacacbbbbcaaaaababbaabacccbabcccabbbcbaaccbca"
        "bbcaaabcabccbacbaaabcaabbcccccbbcbacbabaabbcbcaacbbcbbcabacccbccacccabbbabaabcbabccacbbacababcaacababcabaaaacb"
        "bbacbcbbacbcabcaaccabbcbcbcacbbcaaaaabbaaaccabbcaaababacbaccbccbbaaaaacbccbacabbcaaaabaccbbbbbbaaacbaaabbcbaac"
        "aaaacaccccabcacabacaaaaaabcaccbabacbbbcbbcccbbaabcbacacacabaabbabccbcacaacbcbcbcaaabcbbcacbaccccaaaabaacbbaaaa"
        "ccbbaacbcacbaaabcbbccbbcabbbbbcabcaacccbaabcbabaccabbcabcabcccbacabcbcbcabcbacbabbacabcccaabcaabbbcbcbccacbcac"
        "aaababbacbcccbabbaabccaabcabaaaabaababcccaababccbaaccbbbcbbbbcaabccbabaccccccabbcbbbcbbcbbabcccccabacabcbabcbb"
        "aabaaaabaaaabcccbaabacbccabcbabbbcbbaacbcbbbcccbcbaaabbbaccbcaaccacabcabccccaabacacbbbbcacaabaaabbccbbcbbbacca"
        "accbaaaaaabacbbcccbccbcbacbbaaccbaccaccbcabbcaccbbcacbcbccaccbcccabbcacaaccbbabcaabcccbcacbcbccbccabccbababbcc"
        "caccacccbbbbcaccbacbbbabaacababaaaaaaacaccaabbabaabccaaccbabcbcccabcacaacbabaacacbcbccbbbacabccacccabcbabcabab"
        "babcacacaacbbcabcbbcbabacbccbaaacabbbabcabbacbaaabbaacbccaaabbcbbcbcaaabbccabaacabcaabcbcbaaabbcbcbbccbbcbbcab"
        "acbbbcaaccaacacbbbbcaabaccabcbbabcaccbacbcabbabccbbabbcbababccbbbbabbbabbcbcbcabaacabaccbabacccbaabacbcbcacaab"
        "acbaacbccabbcaaabbcccabbbaabbccbcacccabcbcaacbacbcbabababaacbbcbbabababcaaacbcaccbacbbabaccaaaccccbcccaabcacac"
        "bcaacbcbaaaacbccbccbaccbbacbcbcaccbbccbccaaccaaabacbaaccacabbbacbbaaacbbbbbbcabbbbcacbabaabababbabbacccbbbbbcc"
        "bacbbbaacacbbcbcbababcaaacbbacaacacbbcbabcbcaacacaaabcaabbaabccaaacacbbaaaacbabcbacabaaacaaacccacbacbabcbaccbb"
        "ccccaaccabcbbabccbbccaaabcbaccbcbbabacbcbcaacabacacabcacbbcabaccabcbcababbbacaacacbaacbbbcbacccbbacaccacacbaab"
        "cabaabcbcacaacbbbaacbabaaaaccbccbbcccaabacaacbaccabcabcacacabccbbcabbabbabacbbcaabbbcabccacbbaaaacacbbcabccbac"
        "caaabbbbababcbaaccbcbaaabcabacacccaabacccbaaaccaaacbbbaacaabcbcbbcabbbbbbbababacabaaacbacaacbccbaccbacaaabbaac"
        "aabccbcabcbaacabacbcabbaaaccbbbbcbbccccaabbccbbcabbaabbccaabcccaacbacabccaacccbcabbaabbcbcbacbacccabbaccbccaac"
        "aaabaaccccbcbaaaaccacacaaacbabbcaabbbcacacbaccbbbccbbbbbcacccacabaaacaabaababbbbcccccacbbacaabccbacbbacccbbcba"
        "ababbbbbaccccaacbbabacaccbbbcaaccaacacccbcbbbaacbbcccbbcbabacbcbbccbbbbaabbccbcacbaaabcabacbbaaaaabccbabcbbaba"
        "acbbccbcbcacccaaacbbaabcbbabbabbccabcbabcbcacaaabbbbababaccccabcbaccbaaccabababcabbcbaaabbbbccabbccbaababaabba"
        "ccbcaacbaabaacbccabcbcbbbcccbacaaabaccaaacabaabccbbcccbcccccbbbbaccababcabaabbccabcacabcccbbacccaccbcaaaacaaac"
        "baabbcbcbacabababbbcaacaabccaaacabcabccbcbabaabaacbaabaabccbbaaabacaacaaccbaaacbccabaababbcababcabcaabbcaabbca"
        "bcbbbaabcaccccaabccacbbaaaabacaabbcbbbbccccccbbaacbaccababaaccaacbabbcbaacacbbaccaabcaccbbbcaacbaaaaabacbbcbaa"
        "cbcbbcbcbbaabbbaccbbabbcbcbcccaacabbabacacabbcbccaabacbcabbaabcaababccbccabaccbbbaccbbabcabbbcaacaabcaabcbcaac"
        "bcabbcabbcbcbbcacaacaacccbbcaacabaabcccbcbcbbbbbbbbbccbaacbbccbbcbcabcbbbabaccbaabaccccbabcbbbacacbbabbcbbabbb"
        "cabaacbaababccbcabaaacbbccbbbabaaacbbbabbbbbccbacbabaccaccbabbabbbcbbabaabbbabcaabaababbacccacacbbccbbbbbbaaba"
        "bacbcccbbaaabbbbbbcabcbcccaccabacababccaaacccaaacbaccccbbcbabcbbcbbbcccabcbbabbcabcaaaccaabbaabbcabccbacbaaaac"
        "bcbbabcaccacaacacaaabcbbbcbcabacbbcacbacabbacbccbbacccacbbbbbccbbbcaabbaaabacacbaaabcaacbbcbaaabcbccbcbaabbaaa"
        "abababccbcabbcabcbaaccabcabbabbbaaabacaacabbaccacacaaaabaabbabccbcbcacccaaabbacbacbabcbbaaabcaabaaaabaacbbcccc"
        "bbcaaabccabababbbbccaaaaaacbcbaaccbacbcbaacbabaaababacabbccccbbaacbbbcbacbacbbcacacbbbacaabbcbcaacbabbcabbcaba"
        "babbaababaccabababbccbcaccaccaabbbcbbcacccccbabccbaacbabacbbabacaabbcccbbccbabaacbccaaacacbaaabacbccbbccbabbaa"
        "babcbabcbbbabbcabccacbbabcbbbcaacacaabbacabbbcaccabcbbcccbbcbbaaacbcbabccaababbccbbcbabacabacbccaaababaaabaacb"
        "aaabacbbbbacbccacaccccbaacccaabaabcbcacbbbabbabbacccabcaccbabaccaaabcbcbcaabbcbacaabcabcccbaabbbbcbcbcbcccaaac"
        "aaccbbcaaaacbacacacacaabcbcccbbbbaaccbaabaaabbabcaabccabcbaacacaaabacbcbaccaacabcababbbbaccacacabaccbccbcabbba"
        "bcccbaaacabacabbcbcbaaabaccabcccccccbbcabccbcbbabccaaaaabcbcabcbabbbbbaabaaabcccccbccbbcbbcbbabbcbacacaccaabac"
        "cbbbabbabaababcccaccbaaababcccabbcaaabacbabbacacababbcacbcccbaaaabbcaacabbcabaabcacbbcacacaacbbbcbacbaababbaac"
        "bbbbbccccacaabcaabbcbbcbabcbaabbabccbaccbccaacbbbbbaacbaaabbacccaaabbbbabaaabbaaaabcbbbbacbabbbccbababbcccaabb"
        "aabbbaaccccbbbbaabbacabacbcbabacbacbbcacaacccbcccaaacbbccbbcbcbcbcaababcbcbccaacbbcabbbcaaccccaacccbbaccaccaac"
        "cbccbccacbcaaaaaabbbaaabaaababbccabccacbbcababcabccbabcbabbbbaabcbcacabaabbbabbbcabaccaaacbbbaaaaabaababbabcab"
        "acaccaacabcbcaaacccccbcbcbcbbcccacbabaaaaaacbbcacaccabcccacccabbbcacbcbaacbaccbacbabccbcaccabaaccaacaccaaacbba"
        "cccccabbccabbbabaaacacbaccaababccbcaccccacbabacacbcbcccbbbcbcbcabcbacbacbcabccccbcbacbbaabccabcabacbababbaaabb"
        "bbaccbababcccbccaabaacababcbbaccacbcacabbcbbbabcacccaccbcccaababccaaccbccbcacabaaabbccbabccbabaccbabbbccccacab"
        "abbaacbabcbbccccababbcbbbaccacaabbaaccbabcbbabaabcbacacacbbacabcababacbcbaccbbabaaccccbccbbbababababaaaaaaabbb"
        "cccbabccbaccacabcbacacccbbbcccaabaacacbabbbcacbccabaccbacccabacaabbacabcabbbcaacbccbccbbbabccccbabacbabacabccc"
        "ccbacbcabcaaacabaabacababcacbcbabcaacaacbaaabaacaaccaacbcacbbabbcbaccababbcaaacbbaaaaccaaaccbccaccabaaabacbcaa"
        "abaccabcabbcccabcaacabbcacabbcbcaccaabbaababccbbccabaccacacbccbaaccbaacbbccabcababcbbacabbacabcbbacaabcbbcacca"
        "bcbcccbaccbbcbbbaaaccbcbaaabbbaccbcccbcbccacaabbbcbaabaaabaabcaacabbaacacbcaabcbabccaccaabccaacbabcccbaaccccbb"
        "cbbabbabbcbababbabcacabbbbcbabccaccaccababccccaacccabacbbccacacaacbaacaaaccaccccccacbbcacacacabbaaccbbbabbbbbb"
        "bccabacccbbcaabababcccbaacacabbccccaaaccbaccbaaacbbaacbbacaabbcacbcbbbccacaccaccacabaabaabacbccbccaccbacbbacac"
        "abacbbcaabbacbcbabbaabcacacabbcabbccaccbbcccccbbbbaaccaaabcabbcaabcbaaacacaabaabbbcacabbcaccaacbaaaccabcacaacc"
        "acbccbcabbaccbcccbaccbabccabaabbaccbbcaacbbbabbbaabbbacbbbabccaccbbaacaacabbbcababbacbbbbcbccaccabbcaacbcbaacc"
        "caacaaaaccaabcbaccabccaacacaaababccacbbbacbbbcbaaacbabbbcccbacaabbcbcabcbbccbaacaccacacbbbbcccccbbbbabcbacabcc"
        "acaaabbbcbabcacacbbcabaaaabbccabaccaabaccbaccaacaccbaccaabcabacccbbaaccbabcbaacaaaccbcacbaacababacacbaaabcbbcc"
        "cacacbccaacccbcbcacabcabccbccbbbbbacaaabaaccccacbacbbacabccbccbcaababbbacabcbaaccaaccacacccccaaabbabbbcabaaaaa"
        "aabcbbbacababcbbaccbccccaabbbaaabbbccbbcccaccacababbccaababcabbcababbaacacaaabcacbbccbccbbbbcbaaccbcacbbbcacaa"
        "bcabaccaacacbcacbbccbabcbaccbccacbbcbaababaccaaccababbcbacabaabbaacccaaccaaaabcabcbbbabbccbcabbaaacabcaabccbca"
        "bcbabaac"};
    constexpr int expected_result{45830534};
    EXPECT_EQ(expected_result, number_of_substrings(input));
}
