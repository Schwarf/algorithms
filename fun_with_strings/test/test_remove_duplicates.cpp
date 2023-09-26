//
// Created by andreas on 26.09.23.
//
#include "gtest/gtest.h"
#include "./../remove_duplicate_letters.h"

TEST(TestRemoveDuplicates, simple1)
{
	const std::string input{"bcabc"};
	const std::string expected_output{"abc"};
	EXPECT_EQ(remove_duplicate_letters(input), expected_output);
}

TEST(TestRemoveDuplicates, simple2)
{
	const std::string input{"cbacdcbc"};
	const std::string expected_output{"acdb"};
	EXPECT_EQ(remove_duplicate_letters(input), expected_output);
}

TEST(TestRemoveDuplicates, medium1)
{
	const std::string input{"thesqtitxyetpxloeevdeqifkz"};
	const std::string expected_output{"hesitxyplovdqfkz"};
	EXPECT_EQ(remove_duplicate_letters(input), expected_output);
}


TEST(TestRemoveDuplicates, complex1)
{
	const std::string input
		{"peymrzknlxtrutjiybqemquchgvtmmtpjvunvekszrkatctcirxwuqknrycpdtcuadblzkkleduezgspoxhhssoipbmdgrqggpfdsanolzczpaggwxrlaleaqtnzxclmxwjucnujsptnbmmjzzjhypnlsoxjveywsufegzlfnyvkcnfevkshbckfropoydkdlblppllgefagjgpajsplvxknvtlgtjyhmnwxcpjjzcizihycvsnhnnmqohivekitxzuo"};
	const std::string expected_output{"abcefghkrdjlmnwpiysqovtxzu"};
	EXPECT_EQ(remove_duplicate_letters(input), expected_output);
}
