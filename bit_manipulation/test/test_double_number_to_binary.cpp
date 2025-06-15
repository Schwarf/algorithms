//
// Created by andreas on 15.06.25.
//
#include "gtest/gtest.h"
#include "./../double_number_to_binary.h"

TEST(double_number_to_binaryTest, SimpleTerminatingFractions) {
    EXPECT_EQ(double_number_to_binary(0.5),   "0.1");      // 1/2
    EXPECT_EQ(double_number_to_binary(0.25),  "0.01");     // 1/4
    EXPECT_EQ(double_number_to_binary(0.125), "0.001");    // 1/8
    EXPECT_EQ(double_number_to_binary(0.625), "0.101");    // 5/8 = .5 + .125
}

TEST(double_number_to_binaryTest, ZeroAndOneAreInvalid) {
    EXPECT_EQ(double_number_to_binary(0.0), "ERROR");
    EXPECT_EQ(double_number_to_binary(1.0), "ERROR");
}

TEST(double_number_to_binaryTest, NonTerminatingFractions) {
    // 0.1 in decimal is indefinite repeating in binary
    EXPECT_EQ(double_number_to_binary(0.1), "ERROR");
    // 1/3 is also non-terminating in base 2
    EXPECT_EQ(double_number_to_binary(1.0/3.0), "ERROR");
}

TEST(double_number_to_binaryTest, ExactEdgeOfLengthLimit) {
    // 1 / 2^30 terminates in exactly 30 bits: "0." + 30 zeros then "1"
    double num30 = 1.0 / (1U << 30);
    std::string expected30 = "0." + std::string(29, '0') + "1";
    EXPECT_EQ(double_number_to_binary(num30), expected30);
}

TEST(double_number_to_binaryTest, ExceedsLengthLimit) {
    // 1 / 2^31 would require 31 bits after the point → error
    double num31 = 1.0 / (1ULL << 31);
    EXPECT_EQ(double_number_to_binary(num31), "ERROR");
}