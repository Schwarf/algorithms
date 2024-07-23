//
// Created by andreas on 10.02.24.
//
#include "gtest/gtest.h"
#include "sort_characters_by_frequency.h"

TEST(SortCharactersByFrequency, simple1)
{
	const std::string input{"tree"};
	const std::string expected_result{"eert"};
	EXPECT_EQ(expected_result, sort_by_frequencies(input));
}

TEST(SortCharactersByFrequency, simple2)
{
	const std::string input{"andreas"};
	const std::string expected_result{"aadenrs"};
	EXPECT_EQ(expected_result, sort_by_frequencies(input));
}

TEST(SortCharactersByFrequency, simple3)
{
	const std::string input{"d"};
	const std::string expected_result{"d"};
	EXPECT_EQ(expected_result, sort_by_frequencies(input));
}

TEST(SortCharactersByFrequency, complex1)
{
	const std::string input{"ajdioajdapiognwdvnefnmeqiofjeiodjkposvgsdovmsalcmsapdgjmsdvmfjvnocndakdjaiodnsjof"};
	const std::string
		expected_result{"ddddddddddooooooooojjjjjjjjaaaaaaannnnnnssssssiiiiimmmmmvvvvvffffeeegggpppcckklqw"};
	EXPECT_EQ(expected_result, sort_by_frequencies(input));
}


TEST(SortCharactersByFrequencySimple, simple1)
{
    const std::string input{"tree"};
    const std::string expected_result{"eert"};
    EXPECT_EQ(expected_result, sort_by_frequencies_simple(input));
}

TEST(SortCharactersByFrequencySimple, simple2)
{
    const std::string input{"andreas"};
    const std::string expected_result{"aadenrs"};
    EXPECT_EQ(expected_result, sort_by_frequencies_simple(input));
}

TEST(SortCharactersByFrequencySimple, simple3)
{
    const std::string input{"d"};
    const std::string expected_result{"d"};
    EXPECT_EQ(expected_result, sort_by_frequencies_simple(input));
}

TEST(SortCharactersByFrequencySimple, complex1)
{
    const std::string input{"ajdioajdapiognwdvnefnmeqiofjeiodjkposvgsdovmsalcmsapdgjmsdvmfjvnocndakdjaiodnsjof"};
    const std::string
            expected_result{"ddddddddddooooooooojjjjjjjjaaaaaaannnnnnssssssiiiiimmmmmvvvvvffffeeegggpppcckklqw"};
    EXPECT_EQ(expected_result, sort_by_frequencies_simple(input));
}