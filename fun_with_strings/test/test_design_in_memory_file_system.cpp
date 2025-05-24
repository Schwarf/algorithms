//
// Created by andreas on 24.05.25.
//
#include "./../design_in_memory_file_system.h"
#include "gtest/gtest.h"
TEST(FileSystemMkdirTest, CreateSingleDirectory) {
    FileSystem fs;
    fs.mkdir("/a");
    std::vector<std::string> result = fs.ls("/");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "a");
}

TEST(FileSystemMkdirTest, CreateNestedDirectories) {
    FileSystem fs;
    fs.mkdir("/a/b/c");
    std::vector<std::string> result = fs.ls("/a/b");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "c");
}

TEST(FileSystemMkdirTest, MultipleIndependentDirectories) {
    FileSystem fs;
    fs.mkdir("/a");
    fs.mkdir("/b");
    std::vector<std::string> result = fs.ls("/");
    std::vector<std::string> expected = {"a", "b"};
    EXPECT_EQ(result, expected);
}

TEST(FileSystemMkdirTest, IdempotentDirectoryCreation) {
    FileSystem fs;
    fs.mkdir("/a/b");
    fs.mkdir("/a/b");  // Should not throw or create duplicates
    std::vector<std::string> result = fs.ls("/a");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "b");
}
