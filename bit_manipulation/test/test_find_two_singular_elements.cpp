//
// Created by andreas on 31.05.24.
//

#include "gtest/gtest.h"
#include "./../find_two_singular_elements.h"
#include <ranges>

TEST(TestFindTwoSingularElements, simple1) {
    std::vector<int> input{-2, 1, 2, 1, 2, 4, 4, 6};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2, 6};
    EXPECT_EQ(expected_result, result);
}


TEST(TestFindTwoSingularElements, simple2) {
    std::vector<int> input{-2, 0};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2, 0};
    EXPECT_EQ(expected_result, result);
}

TEST(TestFindTwoSingularElements, simple3) {
    std::vector<int> input{-1638685546, -2084083624, -307525016, -930251592, -1638685546, 1354460680, 623522045,
                           -1370026032, -307525016, -2084083624, -930251592, 472570145, -1370026032, 1063150409,
                           160988123, 1122167217, 1145305475, 472570145, 623522045, 1122167217, 1354460680, 1145305475};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{160988123, 1063150409};
    EXPECT_EQ(expected_result, result);
}

TEST(TestFindTwoSingularElements, simple4) {
    std::vector<int> input{2, 2, -100, 100};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-100, 100};
    EXPECT_EQ(expected_result, result);
}


TEST(TestFindTwoSingularElements, complex1) {
    std::vector<int> input{1, 1, 0, -2147483648};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2147483648, 0};
    EXPECT_EQ(expected_result, result);
}

TEST(TestFindTwoSingularElements, complex2) {
    std::vector<int> input{-2017078396, 1427014140, 987529319, -277720653, -901501327, 461557219, 1531771710,
                           -486222465, 1065241267, -150752724, 279065789, -979167287, -2129000919, 351169793, 987529319,
                           1291943415, -1198652495, -1390807232, -1384211381, 1427014140, -1698470425, -1698470425,
                           -703318677, -1586850882, 1355734673, 734734207, 279065789, -407414062, 552520367,
                           -1634507058, -1390807232, -1171102957, -2017078396, 813133369, 2018595612, 1203433967,
                           -1634507058, -1722143339, 552520367, 83097707, -210227883, -1334100211, 1266014339,
                           431255111, 431255111, 1487644701, 2043227115, -901501327, -1685439676, -2129000919,
                           407483519, -407414062, -1284422899, -1284422899, 734734207, -703318677, 1865535261,
                           -1685439676, 407483519, -210227883, 1355734673, 1754381294, 1065241267, 1801796253,
                           1531771710, 461557219, -1198652495, 2018595612, -232685875, -1655623443, 1217074301,
                           -950274679, 83097707, -277720653, 1291943415, -1705853183, -2003029055, -1334100211,
                           -150752724, 1217074301, -979167287, 1266014339, -1384211381, -232685875, 813133369,
                           1203433967, -2003029055, -1705853183, 1754381294, 1707386140, 2043227115, 1801796253,
                           -1655623443, 1660957712, -486222465, 351169793, 1487644701, -950274679, 1865535261,
                           -1586850882, 1707386140, -1171102957};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-1722143339, 1660957712};
    EXPECT_EQ(expected_result, result);
}
