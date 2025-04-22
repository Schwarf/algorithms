//
// Created by andreas on 27.11.22.
//


#include "gtest/gtest.h"
#include "tries/trie.h"


TEST(TestTrie, InsertSearch)
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

TEST(TestTrie, InsertSearch2)
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


TEST(TestTrie, InsertSearchDelete)
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

TEST(TestTrie, PrefixTest)
{
    Trie<128> trie;
    trie.insert("apple");
    trie.insert("app");

    EXPECT_TRUE(trie.prefix("app"));
    EXPECT_TRUE(trie.prefix("ap"));
    EXPECT_FALSE(trie.prefix("b"));
    EXPECT_FALSE(trie.prefix("applepie"));
}

TEST(TestTrie, CaseSensitivity)
{
    Trie<128> trie;
    trie.insert("Hello");
    EXPECT_TRUE(trie.search("Hello"));
    EXPECT_FALSE(trie.search("hello"));  // Different character code
}

TEST(TestTrie, EmptyString)
{
    Trie<128> trie;
    trie.insert("");
    EXPECT_TRUE(trie.search(""));
    EXPECT_TRUE(trie.prefix(""));  // Every string starts with ""
    trie.remove("");
    EXPECT_FALSE(trie.search(""));
}

TEST(TestTrie, SubSuperString)
{
    Trie<128> trie;
    trie.insert("test");
    trie.insert("testing");
    trie.insert("tester");

    EXPECT_TRUE(trie.search("test"));
    EXPECT_TRUE(trie.search("testing"));
    EXPECT_TRUE(trie.search("tester"));

    trie.remove("test");
    EXPECT_FALSE(trie.search("test"));
    EXPECT_TRUE(trie.search("testing"));
    EXPECT_TRUE(trie.search("tester"));
}

TEST(TestTrie, SpecialCharacters)
{
    Trie<128> trie;
    trie.insert("a.b-c_d");
    trie.insert("123_456");

    EXPECT_TRUE(trie.search("a.b-c_d"));
    EXPECT_TRUE(trie.search("123_456"));
    EXPECT_FALSE(trie.search("a.b"));
}

TEST(TestTrie, RemoveNonExistent)
{
    Trie<128> trie;
    trie.insert("apple");
    trie.remove("banana");  // Should not crash
    EXPECT_TRUE(trie.search("apple"));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestTrieMinimal, InsertSearch)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Hello"};
    std::string insert3{"sad!jsaklj&*()(NJSKL438209dnsdnk"};
    std::string not_insert{"09148u9dnion"};
    auto trie = TrieMinimal();
    trie.insert(insert1);
    trie.insert(insert2);
    trie.insert(insert3);
    EXPECT_TRUE(trie.search(insert1));
    EXPECT_TRUE(trie.search(insert2));
    EXPECT_TRUE(trie.search(insert3));
    EXPECT_FALSE(trie.search(not_insert));
}

TEST(TestTrieMinimal, InsertSearch2)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Hallole"};
    auto trie = TrieMinimal();
    trie.insert(insert2);
    EXPECT_TRUE(trie.search(insert2));
    EXPECT_FALSE(trie.search(insert1));
    trie.insert(insert1);
    EXPECT_TRUE(trie.search(insert1));
}


TEST(TestTrieMinimal, InsertSearchDelete)
{
    std::string insert1{"Hallo"};
    std::string insert2{"Haallo"};
    auto trie = TrieMinimal();
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

TEST(TestTrieMinimal, PrefixTest)
{
    TrieMinimal trie;
    trie.insert("apple");
    trie.insert("app");

    EXPECT_TRUE(trie.starts_with("app"));
    EXPECT_TRUE(trie.starts_with("ap"));
    EXPECT_FALSE(trie.starts_with("b"));
    EXPECT_FALSE(trie.starts_with("applepie"));
}

TEST(TestTrieMinimal, CaseSensitivity)
{
    TrieMinimal trie;
    trie.insert("Hello");
    EXPECT_TRUE(trie.search("Hello"));
    EXPECT_FALSE(trie.search("hello"));  // Different character code
}

TEST(TestTrieMinimal, EmptyString)
{
    TrieMinimal trie;
    trie.insert("");
    EXPECT_TRUE(trie.search(""));
    EXPECT_TRUE(trie.starts_with(""));  // Every string starts with ""
    trie.remove("");
    EXPECT_FALSE(trie.search(""));
}

TEST(TestTrieMinimal, SubSuperString)
{
    TrieMinimal trie;
    trie.insert("test");
    trie.insert("testing");
    trie.insert("tester");

    EXPECT_TRUE(trie.search("test"));
    EXPECT_TRUE(trie.search("testing"));
    EXPECT_TRUE(trie.search("tester"));

    trie.remove("test");
    EXPECT_FALSE(trie.search("test"));
    EXPECT_TRUE(trie.search("testing"));
    EXPECT_TRUE(trie.search("tester"));
}

TEST(TestTrieMinimal, SpecialCharacters)
{
    TrieMinimal trie;
    trie.insert("a.b-c_d");
    trie.insert("123_456");

    EXPECT_TRUE(trie.search("a.b-c_d"));
    EXPECT_TRUE(trie.search("123_456"));
    EXPECT_FALSE(trie.search("a.b"));
}

TEST(TestTrieMinimal, RemoveNonExistent)
{
    TrieMinimal trie;
    trie.insert("apple");
    trie.remove("banana");  // Should not crash
    EXPECT_TRUE(trie.search("apple"));
}