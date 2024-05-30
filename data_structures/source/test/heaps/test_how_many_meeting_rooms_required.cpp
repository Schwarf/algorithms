//
// Created by andreas on 30.05.24.
//

#include "gtest/gtest.h"
#include "heaps/how_many_meeting_rooms_required.h"

TEST(SimpleHowManyMeetingRooms, simple1) {
    std::vector<std::vector<int>> meetings{{1, 3},
                                           {4, 6},
                                           {1, 5}};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, how_many_meeting_rooms_required(meetings));
}

TEST(SimpleHowManyMeetingRooms, simple2) {
    std::vector<std::vector<int>> meetings{{1, 3},
                                           {4, 6},
                                           {1, 5},
                                           {1, 2}};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, how_many_meeting_rooms_required(meetings));
}

TEST(SimpleHowManyMeetingRooms, simple3) {
    std::vector<std::vector<int>> meetings{{1, 3},
                                           {4, 6},
                                           {6, 7},
                                           {0, 1}};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, how_many_meeting_rooms_required(meetings));
}

TEST(SimpleHowManyMeetingRooms, simple4) {
    std::vector<std::vector<int>> meetings{{1, 3},
                                           {2, 4},
                                           {3, 5},
                                           {4, 6}};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, how_many_meeting_rooms_required(meetings));
}
