//
// Created by andreas on 05.05.24.
//


#include "gtest/gtest.h"
#include "./../compare_version_numbers.h"

TEST(TestCompareVersionNumbers, simple1) {
    const std::string version1{"1.01"};
    const std::string version2{"1.001"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}


TEST(TestCompareVersionNumbers, simple2) {
    const std::string version1{"1.0.0"};
    const std::string version2{"1.0.0"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}


TEST(TestCompareVersionNumbers, simple3) {
    const std::string version1{"0.1"};
    const std::string version2{"1.1"};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}

TEST(TestCompareVersionNumbers, simple4) {
    const std::string version1{"0.9.9.9.9.9.9.9.9.9.9.9.9"};
    const std::string version2{"1.0"};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}

TEST(TestCompareVersionNumbers, simple5) {
    const std::string version1{"1.0.1.0"};
    const std::string version2{"1"};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}


TEST(TestCompareVersionNumbers, complex1) {
    const std::string version1{
            "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000"};
    const std::string version2{
            "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, compare_versions(version1, version2));
}

