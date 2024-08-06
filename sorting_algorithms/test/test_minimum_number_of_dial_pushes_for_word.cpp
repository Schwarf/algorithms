//
// Created by andreas on 06.08.24.
//
#include "gtest/gtest.h"
#include "minimum_number_of_dial_pushes_for_word.h"

TEST(MinimumDialPushes, simple1) {
    std::string input{"abcde"};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}

TEST(MinimumDialPushes, simple2) {
    std::string input{"xyzxyzxyzxyz"};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}

TEST(MinimumDialPushes, simple3) {
    std::string input{"aabbccddeeffgghhiiiiii"};
    constexpr int expected_result{24};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}

TEST(MinimumDialPushes, simple4) {
    std::string input{"axltaiwutdykakybdctmgzriejugumjumklfmryvtozdfjbvvo"};
    constexpr int expected_result{79};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}

TEST(MinimumDialPushes, simple5) {
    std::string input{"a"};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}

TEST(MinimumDialPushes, simple6) {
    std::string input{
            "auyfzplvicmalhlnvrlkbrztgxxyrfojtlsdndmmdqleopleanztslmixarfhfwvqxhupsicygtuieheunsxsxrobyganbczfomdnplvcqqncpklsymgffpejakdmbsrxuagbullbndljwdcctqealeqhieibrjljvjeytjhuwkqbzptyurdmcqxtmiyndurqdudvkcoxrpxltljxmqvgbguuakemlkxbngneiiksulodkheztnhlrpjpjuckarlpywxwjcgeqeljdwwgekysgpsbjpvtoutpkqjndvwyyjvuhwaoztumdwkevvpfmzgdtfbotujbapygxbssxjdwifpjbpwvnajrlctcxjxlwlcxoibdhpmialmmhmcwguwbwtxnqjryihcfuuogyodrwxszbkjphkucfkzlhletmlnmszfzuarjdyjknucrhmyrnzpdlkyqsmjwmhiaugsyduhvyorodlrhpirpucwryrrqaqggrdzjvvfhjezzhzqlynhujvksokjekwrpfwzsavaajmwlfdwhqxvotbygjxucceaoawwzhubroqwtpdufsyjqfnugbosvapkwgoaacigoybhxsafhgwvdptultfaykneeuwedevudlnjxymknxtythoxnyucskxknheckgnjxjkhlkfhkcgpmzqghubthbuaexlyeferbgidbkbpfjnzgezqptrlieltooaaasoejrzicqvmfdufgkhqhmowguiupngdznfhtpcqjrhzvgxkilmhhlraxbumdhmulpmxdjaolmoycabxkovvgryrlpimvlswppgtbavirtsfqdwicioctbqadwddkbrtsvipaggajbkqueugrdoreypzmukzcydfqpdfmtuicbrmspyswjgupatkpsglbqyrzqmkzrrilyqfhafeuxfjzuggcetsjcefdttnipbzggsduaiswiahucdkbtumyzvqlgwheyczqzrqwgmflnyw"};
    constexpr int expected_result{2027};
    EXPECT_EQ(expected_result, minimum_dial_pushes(input));
}