//
// Created by andreas on 23.09.23.
//
#include "gtest/gtest.h"
#include "longest_string_chain.h"
TEST(TestLongestStringChain, simple1)
{
	std::vector<std::string> words{"a", "b", "ba", "bca", "bda", "bdca"};
	constexpr int expected_result{4};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}

TEST(TestLongestStringChain, simple2)
{
	std::vector<std::string> words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
	constexpr int expected_result{5};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}

TEST(TestLongestStringChain, simple3)
{
	std::vector<std::string> words{"abcd", "dbqca"};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}

TEST(TestLongestStringChain, medium1)
{
	std::vector<std::string> words
		{"ksqvsyq", "ks", "kss", "czvh", "zczpzvdhx", "zczpzvh", "zczpzvhx", "zcpzvh", "zczvh", "gr", "grukmj",
		 "ksqvsq", "gruj", "kssq", "ksqsq", "grukkmj", "grukj", "zczpzfvdhx", "gru"};
	constexpr int expected_result{7};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}

TEST(TestLongestStringChain, medium2)
{
	std::vector<std::string> words
		{"czgxmxrpx", "lgh", "bj", "cheheex", "jnzlxgh", "nzlgh", "ltxdoxc", "bju", "srxoatl", "bbadhiju", "cmpx", "xi",
		 "ntxbzdr", "cheheevx", "bdju", "sra", "getqgxi", "geqxi", "hheex", "ltxdc", "nzlxgh", "pjnzlxgh", "e",
		 "bbadhju", "cmxrpx", "gh", "pjnzlxghe", "oqlt", "x", "sarxoatl", "ee", "bbadju", "lxdc", "geqgxi", "oqltu",
		 "heex", "oql", "eex", "bbdju", "ntxubzdr", "sroa", "cxmxrpx", "cmrpx", "ltxdoc", "g", "cgxmxrpx", "nlgh",
		 "sroat", "sroatl", "fcheheevx", "gxi", "gqxi", "heheex"};
	constexpr int expected_result{9};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}