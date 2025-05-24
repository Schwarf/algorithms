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
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
TEST(FileSystemLsTest, ListEmptyDirectory) {
    FileSystem fs;
    fs.mkdir("/docs/empty");
    std::vector<std::string> result = fs.ls("/docs/empty");
    EXPECT_TRUE(result.empty());
}

TEST(FileSystemLsTest, ListDirectoryWithFilesAndDirsSorted) {
    FileSystem fs;
    fs.mkdir("/a");
    fs.mkdir("/a/b");
    fs.addContentToFile("/a/x.txt", "data");
    fs.addContentToFile("/a/y.txt", "data");
    std::vector<std::string> result = fs.ls("/a");
    std::vector<std::string> expected = {"b", "x.txt", "y.txt"};
    EXPECT_EQ(result, expected);
}

TEST(FileSystemLsTest, ListFilePathReturnsFileName) {
    FileSystem fs;
    fs.addContentToFile("/readme.md", "info");
    std::vector<std::string> result = fs.ls("/readme.md");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "readme.md");
}

TEST(FileSystemLsTest, ListNestedFilePath) {
    FileSystem fs;
    fs.mkdir("/projects");
    fs.addContentToFile("/projects/code.cpp", "int main(){}");
    std::vector<std::string> result = fs.ls("/projects/code.cpp");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "code.cpp");
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
TEST(FileSystemAddContentTest, CreatesNewFileWithContent) {
    FileSystem fs;
    fs.addContentToFile("/newfile.txt", "Hello");
    std::string content = fs.readContentFromFile("/newfile.txt");
    EXPECT_EQ(content, "Hello");
}

TEST(FileSystemAddContentTest, AppendsToExistingFile) {
    FileSystem fs;
    fs.addContentToFile("/log.txt", "Line1\n");
    fs.addContentToFile("/log.txt", "Line2\n");
    std::string content = fs.readContentFromFile("/log.txt");
    EXPECT_EQ(content, "Line1\nLine2\n");
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
TEST(FileSystemReadContentTest, ReadSingleWrite) {
    FileSystem fs;
    fs.addContentToFile("/docs/info.txt", "This is a test.");
    std::string content = fs.readContentFromFile("/docs/info.txt");
    EXPECT_EQ(content, "This is a test.");
}

TEST(FileSystemReadContentTest, ReadAfterMultipleAppends) {
    FileSystem fs;
    fs.addContentToFile("/logs/debug.log", "Start\n");
    fs.addContentToFile("/logs/debug.log", "Init complete\n");
    fs.addContentToFile("/logs/debug.log", "Running\n");
    std::string content = fs.readContentFromFile("/logs/debug.log");
    EXPECT_EQ(content, "Start\nInit complete\nRunning\n");
}

TEST(FileSystemReadContentTest, ReadEmptyFile) {
    FileSystem fs;
    fs.addContentToFile("/empty.txt", "");
    std::string content = fs.readContentFromFile("/empty.txt");
    EXPECT_EQ(content, "");
}