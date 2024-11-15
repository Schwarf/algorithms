//
// Created by andreas on 26.04.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP
#define DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP

#include "gtest/gtest.h"
#include "./../longest_ideal_string_subsequence.h"


TEST(TestLongestIdealStringSubsequence, simple1_bottom_up)
{
    std::string input{"acfgbd"};
    constexpr int k{2};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_ideal_string_bottom_up(input, k));
}

TEST(TestLongestIdealStringSubsequence, simple2_bottom_up)
{
    std::string input{"abcd"};
    constexpr int k{3};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_ideal_string_bottom_up(input, k));
}

TEST(TestLongestIdealStringSubsequence, simple3_bottom_up)
{
    std::string input{"a"};
    constexpr int k{3};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, longest_ideal_string_bottom_up(input, k));
}


TEST(TestLongestIdealStringSubsequence, medium1_bottom_up)
{
    std::string input{"dyyonfvzsretqxucmavxegvlnnjubqnwrhwikmnnrpzdovjxqdsatwzpdjdsneyqvtvorlwbkb"};
    constexpr int k{7};
    constexpr int expected_result{42};
    EXPECT_EQ(expected_result, longest_ideal_string_bottom_up(input, k));
}

TEST(TestLongestIdealStringSubsequence, complex1_bottom_up)
{
    std::string input{
        "ksppfqkvtbivirhmgmkbeuyyqowldqnbbgeadpektsixhssubrcsrsoqvngtqfxiknxbogoemmcjohvioyaskmdvshkioqlelwqxjrgidhzvnfsjdbyhccgewcajsjtscjkzbsqpcrtyyroajstexqgxssimkctxddiicrycrmfxkvgnpccpiawmzwefjrnatjbalminnlyjvwmerfiglqysqzsdoktbayhtqsahhzpdzxhrvypyqmsjjdcylyzmelnjhqmiqqvtdvqeecdtpabataedwtommhjlwzdeilmbqsdhsumqavebljocamuweuxoytmzraaiusmesvswmcoqbncsghrihjojrugzcazpgdgjtovhbdytyzntywlfchfyahdsgdovgrdbvdujwdsojqzluxpxcukhsvsbcxeudaezeukfoktamuuieldqqdgbfwtxrfhrsmikkfybwqaaazgruruzvqkzcljufwsqremjoswcgjjctkrwsbfgvarznfhmmdnmdemasuwoshzsprkyawqreyzcjhpuihfpeizjkplyxxqttyeyopvbpzhwllkbgyeykkunogyyevsiglznmyixuimkrbffiiledmdcazrhvdwqjirvyxdtdlovuocobzexdsdxslkrzreaevwywaryeafydjlpccklipyhfwgafihcsimsquckxsnnftaviuumngctfmbrtuxqjwlkwydiislrntqrulmecenrrlnovrwfzxqaagnszvoogwfpwuhkojsxvjambsxszfnwjxckmecmpqaxbwdrqekanoxvoguxfocnxkgoptqxadtpglnlrllaynknfdzbsg"
    };
    constexpr int k{21};
    constexpr int expected_result{833};
    EXPECT_EQ(expected_result, longest_ideal_string_bottom_up(input, k));
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP
