//
// Created by andreas on 30.05.24.
//
#include "gtest/gtest.h"
#include "./../logger_rate_limiter.h"

TEST(LoggerRateLimiter, simple1) {
    auto logger = Logger();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(2, "bar"));
    EXPECT_FALSE(logger.shall_print_message(3, "foo"));
    EXPECT_FALSE(logger.shall_print_message(8, "bar"));
    EXPECT_FALSE(logger.shall_print_message(10, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
}


TEST(LoggerRateLimiter, simple2) {
    auto logger = Logger();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(1, "foo"));
    EXPECT_FALSE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(2, "foo"));
    EXPECT_TRUE(logger.shall_print_message(21, "foo"));
}

TEST(LoggerRateLimiter, simple3) {
    auto logger = Logger();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
    EXPECT_TRUE(logger.shall_print_message(22, "foo"));
}

TEST(LoggerRateLimiter, simple4) {
    auto logger = Logger();
    EXPECT_TRUE(logger.shall_print_message(1, "foo1"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo2"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo3"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo4"));
}

TEST(LoggerRateLimiter10Seconds, simple1) {
    auto logger = LoggerOnly10Seconds();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(2, "bar"));
    EXPECT_FALSE(logger.shall_print_message(3, "foo"));
    EXPECT_FALSE(logger.shall_print_message(8, "bar"));
    EXPECT_FALSE(logger.shall_print_message(10, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
}


TEST(LoggerRateLimiter10Seconds, simple2) {
    auto logger = LoggerOnly10Seconds();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(1, "foo"));
    EXPECT_FALSE(logger.shall_print_message(1, "bar"));
    EXPECT_FALSE(logger.shall_print_message(2, "foo"));
    EXPECT_TRUE(logger.shall_print_message(21, "foo"));
}

TEST(LoggerRateLimiter10Seconds, simple3) {
    auto logger = LoggerOnly10Seconds();
    EXPECT_TRUE(logger.shall_print_message(1, "foo"));
    EXPECT_TRUE(logger.shall_print_message(11, "foo"));
    EXPECT_TRUE(logger.shall_print_message(22, "foo"));
}

TEST(LoggerRateLimiter10Seconds, simple4) {
    auto logger = LoggerOnly10Seconds();
    EXPECT_TRUE(logger.shall_print_message(1, "foo1"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo2"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo3"));
    EXPECT_TRUE(logger.shall_print_message(1, "foo4"));
}
