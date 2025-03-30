//
// Created by andreas on 30.05.24.
//
#include "gtest/gtest.h"
#include "heaps/find_most_booked_room.h"


TEST(TestFindMostBookedRoom, third_room_wins)
{
    constexpr int number_of_meetings{3};
    std::vector<std::vector<int>> meetings{
        {1, 20},
        {2, 10},
        {3, 5},
        {4, 9},
        {6, 8}
    };
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}

TEST(TestFindMostBookedRoom, tie_first_room_wins)
{
    constexpr int number_of_meetings{2};
    std::vector<std::vector<int>> meetings{
        {0, 10},
        {1, 5},
        {2, 7},
        {3, 4}
    };
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}


TEST(TestFindMostBookedRoom, four_rooms_but_only_two_are_used_second_room_wins)
{
    constexpr int number_of_meetings{4};
    std::vector<std::vector<int>> meetings{
        {19, 20},
        {14, 15},
        {13, 14},
        {11, 20}
    };
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}


TEST(TestFindMostBookedRoom, four_rooms_but_only_first_is_used)
{
    constexpr int number_of_meetings{4};
    std::vector<std::vector<int>> meetings{
        {1, 3},
        {4, 5},
        {7, 10},
        {11, 20}
    };
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}

TEST(TestFindMostBookedRoom, four_rooms_last_one_wins)
{
    constexpr int number_of_meetings{4};
    std::vector<std::vector<int>> meetings{
        {1, 20},
        {2, 20},
        {3, 20},
        {11, 12},
        {13, 15}
    };
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}

TEST(TestFindMostBookedRoom, two_rooms_last_one_wins)
{
    constexpr int number_of_meetings{2};
    std::vector<std::vector<int>> meetings{
        {10, 11},
        {2, 10},
        {1, 17},
        {9, 13},
        {18, 20}
    };
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}

TEST(TestFindMostBookedRoom, hundred_rooms)
{
    constexpr int number_of_meetings{100};
    std::vector<std::vector<int>> meetings{
        {0, 500000},
        {1, 499999},
        {2, 499998},
        {3, 499997},
        {4, 499996},
        {5, 499995},
        {6, 499994},
        {7, 499993},
        {8, 499992},
        {9, 499991},
        {10, 499990},
        {11, 499989},
        {12, 499988},
        {13, 499987},
        {14, 499986},
        {15, 499985},
        {16, 499984},
        {17, 499983},
        {18, 499982},
        {19, 499981},
        {20, 499980},
        {21, 499979},
        {22, 499978},
        {23, 499977},
        {24, 499976},
        {25, 499975},
        {26, 499974},
        {27, 499973},
        {28, 499972},
        {29, 499971},
        {30, 499970},
        {31, 499969},
        {32, 499968},
        {33, 499967},
        {34, 499966},
        {35, 499965},
        {36, 499964},
        {37, 499963},
        {38, 499962},
        {39, 499961},
        {40, 499960},
        {41, 499959},
        {42, 499958},
        {43, 499957},
        {44, 499956},
        {45, 499955},
        {46, 499954},
        {47, 499953},
        {48, 499952},
        {49, 499951},
        {50, 499950},
        {51, 499949},
        {52, 499948},
        {53, 499947},
        {54, 499946},
        {55, 499945},
        {56, 499944},
        {57, 499943},
        {58, 499942},
        {59, 499941},
        {60, 499940},
        {61, 499939},
        {62, 499938},
        {63, 499937},
        {64, 499936},
        {65, 499935},
        {66, 499934},
        {67, 499933},
        {68, 499932},
        {69, 499931},
        {70, 499930},
        {71, 499929},
        {72, 499928},
        {73, 499927},
        {74, 499926},
        {75, 499925},
        {76, 499924},
        {77, 499923},
        {78, 499922},
        {79, 499921},
        {80, 499920},
        {81, 499919},
        {82, 499918},
        {83, 499917},
        {84, 499916},
        {85, 499915},
        {86, 499914},
        {87, 499913},
        {88, 499912},
        {89, 499911},
        {90, 499910},
        {91, 499909},
        {92, 499908},
        {93, 499907},
        {94, 499906},
        {95, 499905},
        {96, 499904},
        {97, 499903},
        {98, 499902},
        {99, 100},
        {101, 102}
    };
    constexpr int expected_result{99};
    EXPECT_EQ(expected_result, most_booked_room(number_of_meetings, meetings));
}
