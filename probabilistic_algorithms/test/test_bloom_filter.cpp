//
// Created by andreas on 24.05.25.
//

#include <gtest/gtest.h>
#include "bloom_filter.h"

TEST(BloomFilterTest, BasicInsertAndContains) {
    BloomFilter<1024, 100, std::string> filter;

    filter.insert("apple");
    filter.insert("banana");
    filter.insert("cherry");

    EXPECT_TRUE(filter.contains("apple"));
    EXPECT_TRUE(filter.contains("banana"));
    EXPECT_TRUE(filter.contains("cherry"));
}

TEST(BloomFilterTest, FalseNegativeCheck) {
    BloomFilter<1024, 100, std::string> filter;
    std::vector<std::string> words = {"alpha", "beta", "gamma", "delta", "epsilon"};

    for (const auto& word : words) {
        filter.insert(word);
    }

    for (const auto& word : words) {
        EXPECT_TRUE(filter.contains(word)) << "False negative for: " << word;
    }
}

TEST(BloomFilterTest, NoFalsePositivesOnEmptyFilter) {
    BloomFilter<1024, 100, std::string> filter;

    EXPECT_FALSE(filter.contains("phantom"));
    EXPECT_FALSE(filter.contains("ghost"));
    EXPECT_FALSE(filter.contains("zombie"));
}

TEST(BloomFilterTest, FalsePositiveProbability) {
    BloomFilter<1024, 100, std::string> filter;

    // Insert 100 known items
    for (int i = 0; i < 100; ++i) {
        filter.insert("word_" + std::to_string(i));
    }

    // Check 100 other items not inserted
    int falsePositives = 0;
    for (int i = 1000; i < 2000; ++i) {
        if (filter.contains("word_" + std::to_string(i)))
            ++falsePositives;
    }

    // Expect some false positives but not too many
    EXPECT_LT(falsePositives, 10);  // <10% false positive rate

    for (int i = 3000; i < 10000; ++i) {
        if (filter.contains("word_" + std::to_string(i)))
            ++falsePositives;
    }

    // Expect some false positives after adding almost 100 times more items
    EXPECT_GT(falsePositives, 10);  // <10% false positive rate
}

TEST(BloomFilterTest, ClearFunctionality) {
    BloomFilter<1024, 100, std::string> filter;

    filter.insert("reset_me");
    EXPECT_TRUE(filter.contains("reset_me"));

    filter.clear();
    EXPECT_FALSE(filter.contains("reset_me"));
}
