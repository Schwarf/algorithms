//
// Created by andreas on 20.07.23.
//

#include "gtest/gtest.h"
#include "graphs/can_finish_course_schedule.h"

TEST(CanFinishCourseSchedule, simple1) {
    constexpr int number_of_courses{2};
    const std::vector<std::vector<unsigned int>> courses{{0, 1}};
    EXPECT_TRUE(can_finish_course_schedule(courses, number_of_courses));
}

TEST(CanFinishCourseSchedule, simple2) {
    constexpr int number_of_courses{2};
    const std::vector<std::vector<unsigned int>> courses{{0, 1},
                                                         {1, 0}};
    EXPECT_FALSE(can_finish_course_schedule(courses, number_of_courses));
}

TEST(CanFinishCourseSchedule, simple3) {
    constexpr int number_of_courses{8};
    const std::vector<std::vector<unsigned short>> courses{{1, 0},
                                                           {2, 6},
                                                           {1, 7},
                                                           {6, 4},
                                                           {7, 0},
                                                           {0, 5}};
    EXPECT_TRUE(can_finish_course_schedule(courses, number_of_courses));
}

TEST(CanFinishCourseSchedule, simple4) {
    constexpr int number_of_courses{20};
    const std::vector<std::vector<unsigned short>> courses{{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    EXPECT_FALSE(can_finish_course_schedule(courses, number_of_courses));
}
