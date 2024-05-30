//
// Created by andreas on 30.05.24.
//
#include "../can_attend_all_meetings.h"
#include "gtest/gtest.h"

TEST(CanAttendAllMeetings, simple1) {
    std::vector<std::vector<int>> meetings{{0, 1},
                                           {2, 4},
                                           {1, 2}};
    EXPECT_TRUE(can_attend_all_meetings(meetings));
}

TEST(CanAttendAllMeetings, simple2) {
    std::vector<std::vector<int>> meetings{{0, 1},
                                           {0, 4},
                                           {1, 2}};
    EXPECT_FALSE(can_attend_all_meetings(meetings));
}

TEST(CanAttendAllMeetings, simple3) {
    std::vector<std::vector<int>> meetings{{0, 1}};
    EXPECT_TRUE(can_attend_all_meetings(meetings));
}

TEST(CanAttendAllMeetings, simple4) {
    std::vector<std::vector<int>> meetings{{0, 1},
                                           {1, 4},
                                           {4, 6},
                                           {5, 7}};
    EXPECT_FALSE(can_attend_all_meetings(meetings));
}
