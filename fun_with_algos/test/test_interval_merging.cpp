//
// Created by andreas on 12.09.23.
//
#include "gtest/gtest.h"
#include "interval_merging.h"

TEST(IntervalMerging, simple1) {
    std::vector<std::vector<int>> input{{1,  3},
                                        {2,  6},
                                        {8,  10},
                                        {15, 18}};
    const std::vector<std::vector<int>> expected_output{{1,  6},
                                                        {8,  10},
                                                        {15, 18}};
    EXPECT_EQ(expected_output, merge_intervals(input));
}

TEST(IntervalMerging, simple2) {
    std::vector<std::vector<int>> input{{1, 4},
                                        {4, 5}};
    const std::vector<std::vector<int>> expected_output{{1, 5}};
    EXPECT_EQ(expected_output, merge_intervals(input));
}

TEST(IntervalMerging, simple3) {
    std::vector<std::vector<int>>
            input{{2, 3},
                  {0, 1},
                  {1, 2},
                  {3, 4},
                  {4, 5},
                  {1, 1},
                  {0, 1},
                  {4, 6},
                  {5, 7},
                  {1, 1},
                  {3, 5}};
    const std::vector<std::vector<int>> expected_output{{0, 7}};
    EXPECT_EQ(expected_output, merge_intervals(input));
}

TEST(IntervalMerging, simple4) {
    std::vector<std::vector<int>> input{{2, 3}};
    EXPECT_EQ(input, merge_intervals(input));
}

TEST(IntervalMerging, simple5) {
    std::vector<std::vector<int>> input;
    EXPECT_EQ(input, merge_intervals(input));
}


TEST(IntervalMerging, complex1) {
    std::vector<std::vector<int>>
            input
            {{362, 367},
             {314, 315},
             {133, 138},
             {434, 443},
             {202, 203},
             {144, 145},
             {229, 235},
             {205, 212},
             {314, 323},
             {128, 129},
             {413, 414},
             {342, 345},
             {43,  49},
             {333, 342},
             {173, 178},
             {386, 391},
             {131, 133},
             {157, 163},
             {187, 190},
             {186, 186},
             {17,  19},
             {63,  69},
             {70,  79},
             {386, 391},
             {98,  102},
             {236, 239},
             {195, 195},
             {338, 338},
             {169, 170},
             {151, 153},
             {409, 416},
             {377, 377},
             {90,  96},
             {156, 165},
             {182, 186},
             {371, 372},
             {228, 233},
             {297, 306},
             {56,  61},
             {184, 190},
             {401, 403},
             {221, 228},
             {203, 212},
             {39,  43},
             {83,  84},
             {66,  68},
             {80,  83},
             {32,  32},
             {182, 182},
             {300, 306},
             {235, 238},
             {267, 272},
             {458, 464},
             {114, 120},
             {452, 452},
             {372, 375},
             {275, 280},
             {302, 302},
             {5,   9},
             {54,  62},
             {237, 237},
             {432, 439},
             {415, 421},
             {340, 347},
             {356, 358},
             {165, 168},
             {15,  17},
             {259, 265},
             {201, 204},
             {192, 197},
             {376, 383},
             {210, 211},
             {362, 367},
             {481, 488},
             {59,  64},
             {307, 315},
             {155, 164},
             {465, 467},
             {55,  60},
             {20,  24},
             {297, 304},
             {207, 210},
             {322, 328},
             {139, 142},
             {192, 195},
             {28,  36},
             {100, 108},
             {71,  76},
             {103, 105},
             {34,  38},
             {439, 441},
             {162, 168},
             {433, 433},
             {368, 369},
             {137, 137},
             {105, 112},
             {278, 280},
             {452, 452},
             {131, 132},
             {475, 480},
             {126, 129},
             {95,  104},
             {93,  99},
             {394, 403},
             {70,  78}};
    const std::vector<std::vector<int>> expected_output
            {{5,   9},
             {15,  19},
             {20,  24},
             {28,  38},
             {39,  49},
             {54,  69},
             {70,  79},
             {80,  84},
             {90,  112},
             {114, 120},
             {126, 129},
             {131, 138},
             {139, 142},
             {144, 145},
             {151, 153},
             {155, 168},
             {169, 170},
             {173, 178},
             {182, 190},
             {192, 197},
             {201, 212},
             {221, 239},
             {259, 265},
             {267, 272},
             {275, 280},
             {297, 306},
             {307, 328},
             {333, 347},
             {356, 358},
             {362, 367},
             {368, 369},
             {371, 375},
             {376, 383},
             {386, 391},
             {394, 403},
             {409, 421},
             {432, 443},
             {452, 452},
             {458, 464},
             {465, 467},
             {475, 480},
             {481, 488}};
    EXPECT_EQ(expected_output, merge_intervals(input));
}
