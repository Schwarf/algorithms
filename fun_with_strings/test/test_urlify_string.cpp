//
// Created by andreas on 25.05.25.
//
#include "./../urlify_string.h"
#include "gtest/gtest.h"

TEST(TestUrlifyString, NoSpaces) {
    std::string input = "HelloWorld      ";
    constexpr size_t true_size = 10;
    const std::string expected_result = "HelloWorld";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

TEST(TestUrlifyString, SingleSpaceInMiddle) {
    std::string input = "Hello World      ";
    constexpr size_t true_size = 11;
    const std::string expected_result = "Hello%20World";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

TEST(TestUrlifyString, LeadingAndTrailingSpaces) {
    std::string input = " Hello World  ";
    constexpr size_t true_size = 12;
    const std::string expected_result = "%20Hello%20World";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

TEST(TestUrlifyString, AllSpaces) {
    std::string input = "     ";
    constexpr size_t true_size = 5;
    const std::string expected_result = "%20%20%20%20%20";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

TEST(TestUrlifyString, MixedWithMultipleSpaces) {
    std::string input = "Mr  John Smith    ";
    constexpr size_t true_size = 14;
    const std::string expected_result = "Mr%20%20John%20Smith";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

TEST(TestUrlifyString, EmptyInput) {
    std::string input = "";
    constexpr size_t true_size = 0;
    const std::string expected_result = "";
    EXPECT_EQ(urlify_string(input, true_size), expected_result);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/*
TEST(TestUrlifyStringInPlace, NoSpaces) {
    std::string input = "HelloWorld      ";
    constexpr size_t true_size = 10;
    const std::string expected_result = "HelloWorld";
    urlify_string_in_place(input, true_size);
    EXPECT_EQ(input, expected_result);
}

TEST(TestUrlifyStringInPlace, SingleSpaceInMiddle) {
    std::string input = "Hello World      ";
    constexpr size_t true_size = 11;
    const std::string expected_result = "Hello%20World";
    urlify_string_in_place(input, true_size);
    EXPECT_EQ(input, expected_result);
}

TEST(TestUrlifyStringInPlace, LeadingAndTrailingSpaces) {
    std::string input = " Hello World  ";
    constexpr size_t true_size = 12;
    const std::string expected_result = "%20Hello%20World";
    urlify_string_in_place(input, true_size);
    EXPECT_EQ(input, expected_result);
}

TEST(TestUrlifyStringInPlace, AllSpaces) {
    std::string input = "     ";
    constexpr size_t true_size = 5;
    const std::string expected_result = "%20%20%20%20%20";
    urlify_string_in_place(input, true_size);
EXPECT_EQ(input, expected_result);
}

TEST(TestUrlifyStringInPlace, MixedWithMultipleSpaces) {
    std::string input = "Mr  John Smith    ";
    constexpr size_t true_size = 14;
    const std::string expected_result = "Mr%20%20John%20Smith";
    urlify_string_in_place(input, true_size);
EXPECT_EQ(input, expected_result);
}

TEST(TestUrlifyStringInPlace, EmptyInput) {
    std::string input = "";
    constexpr size_t true_size = 0;
    const std::string expected_result = "";
    urlify_string_in_place(input, true_size);
EXPECT_EQ(input, expected_result);
}
*/