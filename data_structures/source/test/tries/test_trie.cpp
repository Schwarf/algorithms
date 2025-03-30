//
// Created by andreas on 27.11.22.
//


#include "gtest/gtest.h"
#include "tries/trie.h"


TEST(TrieInsertSearch, Test1)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Hello"};
    std::string insert3{"sad!jsaklj&*()(NJSKL438209dnsdnk"};
    std::string not_insert{"09148u9dnion"};
    auto trie = Trie<128>();
    trie.insert(insert1);
    trie.insert(insert2);
    trie.insert(insert3);
    EXPECT_TRUE(trie.search(insert1));
    EXPECT_TRUE(trie.search(insert2));
    EXPECT_TRUE(trie.search(insert3));
    EXPECT_FALSE(trie.search(not_insert));
}

TEST(TrieInsertSearch, Test2)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Hallole"};
    auto trie = Trie<128>();
    trie.insert(insert2);
    EXPECT_TRUE(trie.search(insert2));
    EXPECT_FALSE(trie.search(insert1));
    trie.insert(insert1);
    EXPECT_TRUE(trie.search(insert1));
}


TEST(TrieInsertDeleteSearch, Test1)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Haallo"};
    auto trie = Trie<128>();
    trie.insert(insert1);
    EXPECT_TRUE(trie.search(insert1));
    trie.remove(insert1);
    EXPECT_FALSE(trie.search(insert1));
    trie.insert(insert2);
    EXPECT_FALSE(trie.search(insert1));
    trie.insert(insert1);
    EXPECT_TRUE(trie.search(insert1));
    trie.remove(insert1);
    EXPECT_FALSE(trie.search(insert1));
    EXPECT_TRUE(trie.search(insert2));
}
