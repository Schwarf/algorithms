//
// Created by andreas on 15.06.25.
//
#include "gtest/gtest.h"
#include "./../insert_bits.h"

TEST(TestInsertBits, BasicInsertion)
{
    // Example from problem description
    int target = 1024;  // 10000000000
    int source = 19;    //      10011
    int result = insert_bits(target, source, 2, 6);
    EXPECT_EQ(result, 1100);  // binary: 10001001100
}

TEST(TestInsertBits, InsertZero)
{
    int target = 1024;
    int source = 0;
    int result = insert_bits(target, source, 2, 6);
    EXPECT_EQ(result, 1024);
}

TEST(TestInsertBits, FullOverwrite)
{
    int target = 0b11111111111111111111111111111111;  // all ones
    int source = 0b0;
    int result = insert_bits(target, source, 0, 31);
    EXPECT_EQ(result, 0);
}

TEST(TestInsertBits, InsertAtBitZero)
{
    int target = 0b10000000000000000000000000000000;
    int source = 0b1011;
    int result = insert_bits(target, source, 0, 3);
    EXPECT_EQ(result, 0b10000000000000000000000000001011);
}

TEST(TestInsertBits, InsertAtTopBits)
{
    int target = 0;
    int source = 0b101;
    int result = insert_bits(target, source, 29, 31);
    EXPECT_EQ(result, 0b10100000000000000000000000000000);
}
