//
// Created by andreas on 01.03.25.
//
#include "gtest/gtest.h"
#include "heaps/no_equal_adjacent_chars.h"


TEST(TestNoSameAdjacentChars, simple1)
{
    const std::string input{"aab"};
    const std::string expected_output{"aba"};
    EXPECT_EQ(expected_output, no_equal_adjacent_chars(input));
}

TEST(TestNoSameAdjacentChars, simple2)
{
    const std::string input{"aaab"};
    const std::string expected_output{""};
    EXPECT_EQ(expected_output, no_equal_adjacent_chars(input));
}

TEST(TestNoSameAdjacentChars, simple3)
{
    const std::string input{"kkkkzrkatkwpkkkktrq"};
    const std::string expected_output{"ktkrkzkwktkrkqkpkak"};
    EXPECT_EQ(expected_output, no_equal_adjacent_chars(input));
}

TEST(TestNoSameAdjacentChars, complex1)
{
    const std::string input{
        "snnnnbpngobwznvnnnlnwhvnnnnfjnnlnnnnnnbnknnqkndzefncknnnnnaiqrntnndnnnjninnnunnunqhndnnqnnsjqnnpiqshntnnncnvnnnncnnqenlnninyndnnnljongnnjwnnnngllnnngkbnllnnnnontlbpngjnnenqnsnnnnnjeqqghnfpngepnodnnnnnnvnsrnughbnipvnhqmnzonoonnnjotnnonoennnpnfnnkdnnbmnmnpnqninnxronnnnvnlanlnnnebnnnlnvnfknsnbincnttnmnguqenhnnxunnnntnnnnhnqnzehvunfnvnndvnjnnnbnnpxnqipwnmnonnndlnsnonnninnxnnnjnnnnnesennmyiednnnnnnnnnhimtnnnonjlicnwnwvnntaxmnrntnnnnsnbnanninnecbcfjxncnnkvnnqgnunensanpnngjnzxjnopnnyvnnxskniyytnsnnnnx"
    };
    const std::string expected_output{
        "nqnqnonqnonlnjninenvnqnonlnjninenvnsnqnpnonlnjninenbnvntnsnqnpnonlnjningnenbnvntnsnqnpnonlnjninhngnenbnxnvntnsnqnpnonlnjninhngnendnbnxnvntnsnqnpnonmnlnknjninhngnendncnbnxnvnuntnsnqnpnonmnlnknjninhngnfnendncnbnxnwnvnuntnsnqnpnonmnlnknjninhngnfnendncnbnznynxnwnvnuntnsnqnpnonmnlnknjninhngnfnendncnbnanznynxnwnvnuntnsnrnqnpnonmnlnknjninhngnfnendncnbnanznynxnwnvnuntnsnrnqnpnonmnlnknjninhngnfnendncnbnanznynxnwnvnuntnsnrnqnpnonmnlnknjninhngnfnendncnbnanznynxnwnvnuntnsnrnqnpnonmnlnknjninhngnfnendncnbnan"
    };
    EXPECT_EQ(expected_output, no_equal_adjacent_chars(input));
}
