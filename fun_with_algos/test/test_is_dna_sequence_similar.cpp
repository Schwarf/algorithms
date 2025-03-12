//
// Created by andreas on 12.03.25.
//
#include "./../is_dna_sequence_similar.h"
#include "gtest/gtest.h"

TEST(TestIsDnaSequenceSimilar, simple1)
{
     std::vector<std::vector<std::string>> input{{"aa", "bb"}, {"abc", "bcd"}, {"aa", "aa"}};
     std::vector<bool> expected_result(3, true);
     EXPECT_EQ(are_sequences_similar(input), expected_result);
}


TEST(TestIsDnaSequenceSimilar, simple2)
{
     std::vector<std::vector<std::string>> input{{"ab", ""}, {"abbb", "bbbd"}, {"aa", "ccb"}, {"aabbcc", "bccaaa"}};
     std::vector<bool> expected_result{true, true, false, true};
     EXPECT_EQ(are_sequences_similar(input), expected_result);
}