//
// Created by andreas on 18.08.24.
//
#include "gtest/gtest.h"
#include "./../nth_ugly_number.h"

TEST(TestNthUglyNumberBruteForce, simple1) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, nth_ugly_number_recursive(n));
}

TEST(TestNthUglyNumberBruteForce, simple2) {
    constexpr int n{10};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, nth_ugly_number_recursive(n));
}

TEST(TestNthUglyNumberBruteForce, simple4) {
    constexpr int n{31};
    constexpr int expected_result{81};
    EXPECT_EQ(expected_result, nth_ugly_number_recursive(n));
}

TEST(TestNthUglyNumberBruteForce, simple5) {
    constexpr int n{49};
    constexpr int expected_result{240};
    EXPECT_EQ(expected_result, nth_ugly_number_recursive(n));
}

TEST(TestNthUglyNumberBruteForce, simple6) {
    constexpr int n{999};
    constexpr int expected_result{51018336};
    EXPECT_EQ(expected_result, nth_ugly_number_recursive(n));
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
TEST(TestNthUglyNumber, simple1) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}

TEST(TestNthUglyNumber, simple2) {
    constexpr int n{10};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}

TEST(TestNthUglyNumber, simple4) {
    constexpr int n{31};
    constexpr int expected_result{81};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}

TEST(TestNthUglyNumber, simple5) {
    constexpr int n{49};
    constexpr int expected_result{240};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}

TEST(TestNthUglyNumber, simple6) {
    constexpr int n{999};
    constexpr int expected_result{51018336};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}

TEST(TestNthUglyNumber, simple7) {
    constexpr int n{1690};
    constexpr int expected_result{2123366400};
    EXPECT_EQ(expected_result, nth_ugly_number(n));
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
TEST(TestNthUglyNumberSet, simple1) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}

TEST(TestNthUglyNumberSet, simple2) {
    constexpr int n{10};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}

TEST(TestNthUglyNumberSet, simple4) {
    constexpr int n{31};
    constexpr int expected_result{81};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}

TEST(TestNthUglyNumberSet, simple5) {
    constexpr int n{49};
    constexpr int expected_result{240};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}

TEST(TestNthUglyNumberSet, simple6) {
    constexpr int n{999};
    constexpr int expected_result{51018336};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}

TEST(TestNthUglyNumberSet, simple7) {
    constexpr int n{1690};
    constexpr int expected_result{2123366400};
    EXPECT_EQ(expected_result, nth_ugly_number_set(n));
}