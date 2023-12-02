//
// Created by andreas on 02.12.23.
//
#include "gtest/gtest.h"
#include "../count_beautiful_substrings.h"

TEST(CountBeautifulSubStrings, simple1)
{
	const std::string input{"baeyh"};
	constexpr int k{2};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, count_beautiful_substrings(input, k));
}

TEST(CountBeautifulSubStrings, simple2)
{
	const std::string input{"abba"};
	constexpr int k{1};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, count_beautiful_substrings(input, k));
}

TEST(CountBeautifulSubStrings, simple3)
{
	const std::string input{"bcdf"};
	constexpr int k{1};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, count_beautiful_substrings(input, k));
}

TEST(CountBeautifulSubStrings, complex1)
{
	const std::string input
		{"auooubignuoyoaiyoetrezuuucuocemaeefldjqwoioizoyoputaaixrasvuseichoikpsjgeevbwebeoxuejagyoxiuqhgmoapiketuzjnmaaoamceejuujguqafquzaqwhnuiuiofuebaiiwiavetqiiearkuoovukwouauuhipauiguaadojcaaeiicbwaozouihusgzalacbiqbffsdeousaecsvqudjouixoojettoiizaaumeforosgiiiewiouuoouoaqfooyhgacawpeeeowpouhieogstoghvutljmuuvkeenliyyueaeeiooiwhiesamwaowmoehhshedslidnosbnojjrmdoijtaebavgkaizeaeeolcgooyapaofeiuugfzoeuwydouiuoqnaexruhzoyobhujwupoiipaaqwokioooaodfufouuoexcobliunbirebbxqlsuevtntdreooeueedfraqlcoreeilqoeuyczxnadiejvehieiebiykkvpiijeozignatgevuauiihioorqrnlhmzmyoiasiuajlrerinuuxoudbweeoiaajibtikko"};
	constexpr int k{135};
	constexpr int expected_result{112};
	EXPECT_EQ(expected_result, count_beautiful_substrings(input, k));
}

TEST(CountBeautifulSubStringsOptimized, simple1)
{
	const std::string input{"baeyh"};
	constexpr int k{2};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, count_beautiful_substrings_optimized(input, k));
}

TEST(CountBeautifulSubStringsOptimized, simple2)
{
	const std::string input{"abba"};
	constexpr int k{1};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, count_beautiful_substrings_optimized(input, k));
}

TEST(CountBeautifulSubStringsOptimized, simple3)
{
	const std::string input{"bcdf"};
	constexpr int k{1};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, count_beautiful_substrings_optimized(input, k));
}

TEST(CountBeautifulSubStringsOptimized, complex1)
{
	const std::string input
		{"auooubignuoyoaiyoetrezuuucuocemaeefldjqwoioizoyoputaaixrasvuseichoikpsjgeevbwebeoxuejagyoxiuqhgmoapiketuzjnmaaoamceejuujguqafquzaqwhnuiuiofuebaiiwiavetqiiearkuoovukwouauuhipauiguaadojcaaeiicbwaozouihusgzalacbiqbffsdeousaecsvqudjouixoojettoiizaaumeforosgiiiewiouuoouoaqfooyhgacawpeeeowpouhieogstoghvutljmuuvkeenliyyueaeeiooiwhiesamwaowmoehhshedslidnosbnojjrmdoijtaebavgkaizeaeeolcgooyapaofeiuugfzoeuwydouiuoqnaexruhzoyobhujwupoiipaaqwokioooaodfufouuoexcobliunbirebbxqlsuevtntdreooeueedfraqlcoreeilqoeuyczxnadiejvehieiebiykkvpiijeozignatgevuauiihioorqrnlhmzmyoiasiuajlrerinuuxoudbweeoiaajibtikko"};
	constexpr int k{135};
	constexpr int expected_result{112};
	EXPECT_EQ(expected_result, count_beautiful_substrings_optimized(input, k));
}
