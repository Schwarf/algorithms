//
// Created by andreas on 14.01.24.
//
#include "gtest/gtest.h"
#include "./../are_two_strings_close.h"

TEST(TestAreStringsClose, simple1)
{
	const std::string input1{"abc"};
	const std::string input2{"cab"};
	EXPECT_TRUE(are_strings_close(input1, input2));
}


TEST(TestAreStringsClose, simple2)
{
	const std::string input1{"abccc"};
	const std::string input2{"cabbb"};
	EXPECT_TRUE(are_strings_close(input1, input2));
}

TEST(TestAreStringsClose, simple3)
{
	const std::string input1{"cabbba"};
	const std::string input2{"abbccc"};
	EXPECT_TRUE(are_strings_close(input1, input2));
}

TEST(TestAreStringsClose, simple4)
{
	const std::string input1{"cabba"};
	const std::string input2{"abbccc"};
	EXPECT_FALSE(are_strings_close(input1, input2));
}


TEST(TestAreStringsClose, simple5)
{
	const std::string input1{"abcdef"};
	const std::string input2{"bcaxyz"};
	EXPECT_FALSE(are_strings_close(input1, input2));
}

TEST(TestAreStringsClose, medium1)
{
	const std::string input1{"idepikndmiddzcdcdahncdcvhnifhbizrdyyicwnijcmscszdgtlnyonishuiiqdxhic"};
	const std::string input2{"axxkhxlphcsycywsigilhsixdiuclqlxzbcexkcllfyocxcjklpnvxxixytixmccyclr"};
	EXPECT_TRUE(are_strings_close(input1, input2));
}
