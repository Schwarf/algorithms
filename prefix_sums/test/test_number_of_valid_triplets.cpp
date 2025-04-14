//
// Created by andreas on 14.04.25.
//
#include "gtest/gtest.h"
#include "./../number_of_valid_triplets.h"

TEST(TestNumberOfValidTriplts, simple1)
{
    const std::string input{"001101"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, number_of_valid_triplets(input));
}

TEST(TestNumberOfValidTriplts, simple2)
{
    const std::string input{"0"};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, number_of_valid_triplets(input));
}

TEST(TestNumberOfValidTriplts, simple3)
{
    const std::string input{"111000"};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, number_of_valid_triplets(input));
}

TEST(TestNumberOfValidTriplts, simple4)
{
    const std::string input{"10101010"};
    constexpr int expected_result{20};
    EXPECT_EQ(expected_result, number_of_valid_triplets(input));
}

TEST(TestNumberOfValidTriplts, complex1)
{
    const std::string input{"1110110010111000010010001101010000010001010001110101100001001111101000101001001101000101100010000110110010101011101000111010010000100111110100110111001101101101000001110010110010111000110100111011011111100011100110110110100010100110001101010011111011110000001100010111000010011010010101111001110010001001011101010111110001011100110000100010101010001111110100100111001000010110010111011001110001000100110011100000010001100110001011010101110000110010111100110001001111010010111001101100011010101010000011111101000010001111001011000110101110000111111100111110010000011101000110010010101011000000001100101001011000010100010011100010011010011000011111100000001010100100111000010011101101001100000010010111101110011101111110101100100100110001011111000101000001100110100100001101000101000100010000010001010010001001000111011011011101111110011100110101011001101010001111111001011111000010100010101011111110100111011001111010111010100100111000110111111000010011011110101100010010101001111010000000100011101011111010010001011101010111001100000000001111000010010110001100100111111110111000100101110101100010001001010000011010100110001010011111111011100101111110001110101011000000110101100000101001110110101011001001010001011100110000011010010001111101111101100001110010010101001100101000101000110101100111001001111111011000101110010010001000011011110111100001111000111110001101111010001110011111000101011011010001111010000010011100001110010010000001011001100000111110000100100100110010110001101000001111010010010110000110111000000111110010000000100110011101101011111011111110100100100100010111111010011001000000101011000101100010001011010011100001011001110011001110111000011011011100100110111110110001010100010111010110011000010010100010110111100011010111011101001000101110101001001010011011110100011011111111010110100001100010101011011001010001100000000100001001100110000110101101101010011011110101111000110000001011001110000101110100001110001110010101011001101110011110000011111011011011110000111101101111001010101011000110001100101011100100111100011101101000000101110000011100000010011110100101110111010011011111100101100010110001100101110110111010010010000101011101011011001001010010000000001010010101011000101110000001100110111001001101011111010011101010110101000110001011001111101001001110110100100110101110010110001110111100100001010011001100011100110110101111010101110011101011101011010000111001000110110110100100011100101111110011111101001110110111101011111001100000001001101111001001010000001100001001001000110101010001101101010001000110011110001000001101110011111101000110010010101010010011101001101101001100100011011011101101111010010100111011000100111110111010111111011110001101100011000000010001110101011010101001100101011101011011001011110101101100111101101011111100011110111110001100010001001001101100101001000101001111111111100111101011100010000111001010010101011001010010101110111101001011100000001001100011110010001011011001010010001111011010011110011111101000010101101111110100100101010010011111000101000101110111010100101111000001111110111100101010010010100011111011001100011110110010010110001010110100100101111111001010001010000000010110111100101010101111011100010011110011010001000010101111000011110010001101000011110011111100011101100101001001111101110111011111000110010101111100010101011100010000001010011011100010100101001001100010101110010111111110001101100000001001110010101101000000110011101100001010101000001100110001000101001111010010110010001111011000101111100000010011010010010010010000100001100101100111011010001011001010011010101111000111000110100110111100111100100100100010000100101000010100100010111010111011100110101011001001100010011011000111001010011111101110011001000110000110010011011101101111000001111110111000110111001111100101001010101001101011000000101100111000000010101101101111010110010011011000111100110100000000000100001000111110110001110111011010010001110101000001010001101100001000100011011010000100101100010100101101101110000101110010110101011110001000000100111101010100010110110000011010001000111100010011111100011100111101100100001111011111111100010100100100110000000100011100000111110011111100110011011101001101101001000110001010110000001111000101011010100101101000010001011111111100011000001001010111011111011000111111001100011110001101011011011010001110111100110101110010001110010101001011111101010011101101100001001010110001111110001000110101110011010110000011101101110001001110110100011110100110101110101001111011001010110110010001110011100100011010111110100110110110001101011110110010000011001110110100111010000000110111101111001110001000110011010111111000011111110101010101000111110101110101011011000000110001100000010111001010001011011000001111010000011111010000010010001111101011100111110001010100111111011101101000000100100101011011110100111100110100011001010100111010111110111111000101111000111110100101101111110001111110101010001011101100110100011001110001000001110001001011111000111100101100110000110100011111000010101111010000010011000110000001110100001100111010000100111010110001010111100001000100110011101111001110101010110010010100110000000100011101001010010110000011110101110111001110110010001101010011010110111111000100101000101010000010101100000110000100011000000100010100101000001010111010011011010011110101100110001001001000100101011110110001100001111101001010011011110001000111101110111010111000100110101111101011000010100001101001100010001110111110111110111000100101100111010101100110011000100101001000101110100010101010101010111000010111101000000010001011010001101111100010001010100000011100101111000010100100100111010011101110000011000100011011111110110101100000001000111001111010110001001100101001000100100100000100100111001000100101000001110000000111101111001101001001110110110111011101111101010010000011011011001110011001110101001000110001101110101110000101101100110001110111110000110101010111111101001100001101011001100011001011101011001011110010111111110000101011101011001011011101111000010110101011000111111011101110011110111000011101011011101011000110110011010100001100011000110111011111110011110001000011011110111111011100001110001100110101110001000100100000010011011011101010001011010001111111011110010001111000000010010001000000101011111010100101001101011100001011010000011110001110100010001111101111101000001111100100010010001101100001111010000001001101100100100100110001111000111000100100011110111101110001011000000101110100000100"};
    constexpr long long expected_result{10981495136};
    EXPECT_EQ(expected_result, number_of_valid_triplets(input));
}


