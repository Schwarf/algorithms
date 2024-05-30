//
// Created by andreas on 30.05.24.
//
#include "./../letter_combinations_of_phone_numbers.h"
#include "gtest/gtest.h"

TEST(TestLetterCombinations, simple1) {
    const std::string input{"23"};
    const std::vector<std::string> expected_output{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(letter_combinations_of_phone_numbers(input), expected_output);
}

TEST(TestLetterCombinations, simple2) {
    const std::string input{};
    const std::vector<std::string> expected_output{};
    EXPECT_EQ(letter_combinations_of_phone_numbers(input), expected_output);
}

TEST(TestLetterCombinations, simple3) {
    const std::string input{"2"};
    const std::vector<std::string> expected_output{"a", "b", "c"};
    EXPECT_EQ(letter_combinations_of_phone_numbers(input), expected_output);
}


TEST(TestLetterCombinations, complex1) {
    const std::string input{"2783"};
    const std::vector<std::string> expected_output{"aptd", "apte", "aptf", "apud", "apue", "apuf", "apvd", "apve",
                                                   "apvf", "aqtd", "aqte", "aqtf", "aqud", "aque", "aquf", "aqvd",
                                                   "aqve", "aqvf", "artd", "arte", "artf", "arud", "arue", "aruf",
                                                   "arvd", "arve", "arvf", "astd", "aste", "astf", "asud", "asue",
                                                   "asuf", "asvd", "asve", "asvf", "bptd", "bpte", "bptf", "bpud",
                                                   "bpue", "bpuf", "bpvd", "bpve", "bpvf", "bqtd", "bqte", "bqtf",
                                                   "bqud", "bque", "bquf", "bqvd", "bqve", "bqvf", "brtd", "brte",
                                                   "brtf", "brud", "brue", "bruf", "brvd", "brve", "brvf", "bstd",
                                                   "bste", "bstf", "bsud", "bsue", "bsuf", "bsvd", "bsve", "bsvf",
                                                   "cptd", "cpte", "cptf", "cpud", "cpue", "cpuf", "cpvd", "cpve",
                                                   "cpvf", "cqtd", "cqte", "cqtf", "cqud", "cque", "cquf", "cqvd",
                                                   "cqve", "cqvf", "crtd", "crte", "crtf", "crud", "crue", "cruf",
                                                   "crvd", "crve", "crvf", "cstd", "cste", "cstf", "csud", "csue",
                                                   "csuf", "csvd", "csve", "csvf"};
    EXPECT_EQ(letter_combinations_of_phone_numbers(input), expected_output);
}
