//
// Created by andreas on 21.06.25.
//
#include "./../minimum_deletion_to_make_string_special.h"
#include "gtest/gtest.h"

TEST(MinimumDeletionsTest, EmptyString) {
    EXPECT_EQ(minimumDeletions("", 0), 0);
}

TEST(MinimumDeletionsTest, SingleCharacterRepeated) {
    EXPECT_EQ(minimumDeletions("aaaaaaa", 0), 0);
    EXPECT_EQ(minimumDeletions("bbbb", 5), 0);
}

TEST(MinimumDeletionsTest, AlreadyKSpecial) {
    EXPECT_EQ(minimumDeletions("aabbcc", 0), 0);
    EXPECT_EQ(minimumDeletions("aabbcc", 1), 0);
    EXPECT_EQ(minimumDeletions("abcdef", 0), 0);
    EXPECT_EQ(minimumDeletions("abcdef", 2), 0);
}

TEST(MinimumDeletionsTest, SmallDeletionsNeeded) {
    EXPECT_EQ(minimumDeletions("aaabbbcc", 0), 2);
    EXPECT_EQ(minimumDeletions("aabbccddde", 0), 2);
    EXPECT_EQ(minimumDeletions("aaaaabbbcc", 1), 2);
}

TEST(MinimumDeletionsTest, LargerKMakesNoDeletions) {
    EXPECT_EQ(minimumDeletions("aaaabbbcccd", 10), 0);
}

TEST(MinimumDeletionsTest, DiverseFrequencies) {
    EXPECT_EQ(minimumDeletions("aaaabbbbccccddddd", 2), 0);
    EXPECT_EQ(minimumDeletions("aaabbc", 0), 2);
}