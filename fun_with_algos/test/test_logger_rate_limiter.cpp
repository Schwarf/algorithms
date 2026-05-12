//
// Created by andreas on 30.05.24.
//
#include "gtest/gtest.h"
#include "./../logger_rate_limiter.h"

TEST(LoggerRateLimiter, blocks_repeated_message_within_ten_seconds) {
    Logger logger;
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(2, "bar"));
    EXPECT_FALSE(logger.shall_print_message(3, "foo"));
    EXPECT_FALSE(logger.shall_print_message(8, "bar"));
    EXPECT_FALSE(logger.shall_print_message(10, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
}


TEST(LoggerRateLimiter, handles_multiple_messages_at_same_timestamp_independently) {
    Logger logger;
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(1, "foo"));
    EXPECT_FALSE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(2, "foo"));
    EXPECT_TRUE(logger.shall_print_message(21, "foo"));
}

TEST(LoggerRateLimiter, allows_same_message_again_after_ten_seconds) {
    Logger logger;
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
    EXPECT_TRUE(logger.shall_print_message(22, "foo"));
}

TEST(LoggerRateLimiter, allows_different_messages_at_same_timestamp) {
    Logger logger;
    EXPECT_TRUE(logger.shall_print_message(1, "foo1"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo2"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo3"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo4"));
}

TEST(LoggerRateLimiter, supports_timestamp_zero) {
    Logger logger;
    EXPECT_TRUE(logger.shall_print_message(0, "foo"));
    EXPECT_FALSE(logger.shall_print_message(0, "foo"));
    EXPECT_FALSE(logger.shall_print_message(9, "foo"));
    EXPECT_TRUE(logger.shall_print_message(10, "foo"));
}
