//
// Created by andreas on 10.08.24.
//
#include "union_find_disjoint_set/regions_cut_by_slashes.h"
#include "gtest/gtest.h"

TEST(TestRegionsCutBySlashes, simple1)
{
    std::vector<std::string> input{"/"};
    constexpr int expected_result{2};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, simple2)
{
    std::vector<std::string> input{"\\"};
    constexpr int expected_result{2};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, simple3)
{
    std::vector<std::string> input{" "};
    constexpr int expected_result{1};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, simple4)
{
    std::vector<std::string> input{" /", "/ "};
    constexpr int expected_result{2};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, simple5)
{
    std::vector<std::string> input{" /", "  "};
    constexpr int expected_result{1};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, simple6)
{
    std::vector<std::string> input{"/\\", "\\/"};
    constexpr int expected_result{5};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}


TEST(TestRegionsCutBySlashes, medium1)
{
    std::vector<std::string> input{"\\ //\\", " \\\\  ", "///\\/", "/\\ \\/", "// \\\\"};
    constexpr int expected_result{6};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, medium2)
{
    std::vector<std::string> input{"\\/\\\\\\/", "\\/\\\\/\\", "\\/// /", " \\ ///", " \\/\\ /", "//\\//\\"};
    constexpr int expected_result{9};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}

TEST(TestRegionsCutBySlashes, complex1)
{
    std::vector<std::string> input{
        "\\\\/// \\\\\\\\ //\\ \\\\ \\/\\\\// \\/\\//",
        "/\\\\/ \\//////\\  \\///\\ /\\/\\/\\/\\\\",
        "\\/ /\\\\//\\\\//\\//// /\\ ///\\/\\\\ \\",
        "\\\\// / \\\\ \\\\/\\ /\\\\\\/\\\\/  \\\\/\\\\",
        " /// \\\\\\\\ //\\ \\\\\\/\\//// \\\\\\/  ",
        "\\/\\\\\\//\\ /\\ \\\\\\/\\   \\/ //\\ \\//",
        "/\\//\\\\// /\\\\\\\\\\// \\\\ //\\/\\\\ /\\",
        "/\\/  /\\\\  \\\\//\\/ //\\\\///\\\\ \\\\/",
        "//\\ //\\ \\/\\\\/\\/\\/ ///\\\\\\\\\\\\\\//",
        "\\/\\/// \\\\\\//\\\\// \\//\\/\\\\/ \\ / ",
        "\\ / \\\\//\\\\ \\\\/\\//\\// \\/  \\/\\\\\\",
        "\\\\ /\\\\\\// \\/// / ///\\/// /  \\ ",
        "/\\\\\\  /\\/\\ \\\\//// \\\\/ /\\\\/\\\\//",
        " \\\\\\/ \\\\/ /\\\\//\\/\\\\\\\\\\ \\//// \\",
        "\\// //\\/\\////// \\\\/ / \\\\///\\\\/",
        " //\\\\ \\\\  /\\\\\\/\\  \\\\ \\\\/ \\/\\ \\",
        "////\\/\\\\ //\\/\\ /\\///\\///\\ \\\\//",
        " /\\ \\\\\\\\\\ \\  //\\/\\\\/\\\\\\/\\\\/\\\\/",
        "/\\//\\ / / ///\\/ \\\\/\\/\\\\//\\/ \\\\",
        "\\\\\\/\\/////\\/ ///// //  \\\\/ \\\\ ", "//\\\\ / /  ///// //// \\\\\\\\//\\/\\",
        "////\\ ///\\///\\\\/\\\\ \\\\\\/\\ /\\\\/ ",
        "/\\//\\\\/ /\\ \\ \\\\/\\ \\/\\// \\\\/\\/ ",
        "/\\// /\\\\ \\ \\ /\\\\\\ \\////\\ \\\\\\/\\",
        "/\\/ \\//\\\\\\\\\\//\\/ \\  //\\ \\// //", "//   /\\  \\\\ / / //// \\// /\\ \\/",
        "\\/\\ /\\/\\\\// \\\\\\ \\ / \\///\\// /\\",
        "/ /\\\\\\// \\ ///\\ \\ \\\\ \\/\\\\ /\\/ ",
        "\\\\\\ ///\\\\\\\\\\\\\\ /\\ \\/\\\\/ /  \\\\\\",
        " / /\\  \\  //\\//// \\/\\\\ / /\\/\\/"
    };
    constexpr int expected_result{51};
    EXPECT_EQ(count_regions_by_slahes(input), expected_result);
}
