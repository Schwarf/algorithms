//
// Created by andreas on 28.12.23.
//

#include "gtest/gtest.h"
#include "../number_of_string_decodings.h"

TEST(TestNumberOfStringDecodings, simple1) {
    const std::string input{"12"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple2) {
    const std::string input{"226"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple3) {
    const std::string input{"06"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple4) {
    const std::string input{"1372189472892"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, complex1) {
    const std::string input{"1372189438492384923849237289212127819111"};
    constexpr int expected_result{2304};
    EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive1) {
    const std::string input{"12"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_decodings_recursive(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive2) {
    const std::string input{"226"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_decodings_recursive(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive3) {
    const std::string input{"06"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, number_of_decodings_recursive(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive4) {
    const std::string input{"1372189472892"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_decodings_recursive(input));
}

TEST(TestNumberOfStringDecodings, complex_recursive1) {
    const std::string input{"1372189438492384923849237289212127819111"};
    constexpr int expected_result{2304};
    EXPECT_EQ(expected_result, number_of_decodings_recursive(input));
}


TEST(TestNumberOfStringDecodings, simple_recursive21) {
    const std::string input{"12"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_decodings_recursive2(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive22) {
    const std::string input{"226"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_decodings_recursive2(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive23) {
    const std::string input{"06"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, number_of_decodings_recursive2(input));
}

TEST(TestNumberOfStringDecodings, simple_recursive24) {
    const std::string input{"1372189472892"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_decodings_recursive2(input));
}

TEST(TestNumberOfStringDecodings, complex_recursive21) {
    const std::string input{"1372189438492384923849237289212127819111"};
    constexpr int expected_result{2304};
    EXPECT_EQ(expected_result, number_of_decodings_recursive2(input));
}


TEST(TestNumberOfStringDecodings, simple_top_down1) {
    const std::string input{"12"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_decodings_top_down(input));
}

TEST(TestNumberOfStringDecodings, simple_top_down2) {
    const std::string input{"226"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_decodings_top_down(input));
}

TEST(TestNumberOfStringDecodings, simple_top_down3) {
    const std::string input{"06"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, number_of_decodings_top_down(input));
}

TEST(TestNumberOfStringDecodings, simple_top_down4) {
    const std::string input{"1372189472892"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_decodings_top_down(input));
}

TEST(TestNumberOfStringDecodings, complex_top_down1) {
    const std::string input{"1372189438492384923849237289212127819111"};
    constexpr int expected_result{2304};
    EXPECT_EQ(expected_result, number_of_decodings_top_down(input));
}
