//
// Created by andreas on 25.02.24.
//
#include "gtest/gtest.h"
#include "greatest_common_divisor.h"

TEST(TestGreatestCommonDivisor, simpl1)
{
	constexpr int a{100};
	constexpr int b{15};
	constexpr int expected_gcd{5};
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}
TEST(TestGreatestCommonDivisor, PositiveInputs) {
	constexpr int a = 100;
	constexpr int b = 15;
	constexpr int expected_gcd = 5;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, NegativeInputs) {
	constexpr int a = -100;
	constexpr int b = -50;
	constexpr int expected_gcd = 50;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, MixedSignInputs) {
	constexpr int a = 35;
	constexpr int b = -5;
	constexpr int expected_gcd = 5;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, ZeroAndPositive) {
	constexpr int a = 0;
	constexpr int b = 20;
	constexpr int expected_gcd = 20;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, PositiveAndZero) {
	constexpr int a = 45;
	constexpr int b = 0;
	constexpr int expected_gcd = 45;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, LargeNumbers) {
	constexpr long long a = 1234567890LL;
	constexpr long long b = 987654321LL;
	constexpr long long expected_gcd = 9LL;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, UnsignedTypes) {
	constexpr unsigned int a = 100u;
	constexpr unsigned int b = 10u;
	constexpr unsigned int expected_gcd = 10u;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, SmallNumbers) {
	constexpr short a = 8;
	constexpr short b = 2;
	constexpr short expected_gcd = 2;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, PrimeNumbers) {
	constexpr int a = 13;
	constexpr int b = 17;
	constexpr int expected_gcd = 1;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}

TEST(TestGreatestCommonDivisor, SameNumbers) {
	constexpr int a = 42;
	constexpr int b = 42;
	constexpr int expected_gcd = 42;
	EXPECT_EQ(expected_gcd, greatest_common_divisor(a, b));
}