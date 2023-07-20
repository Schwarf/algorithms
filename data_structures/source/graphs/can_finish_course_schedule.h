//
// Created by andreas on 20.07.23.
//

#ifndef DATA_STRUCTURES_CAN_FINISH_COURSE_SCHEDULE_H
#define DATA_STRUCTURES_CAN_FINISH_COURSE_SCHEDULE_H
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [a_i, b_i] indicates that you
// must take course b_i first if you want to take course a_i.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

#include <vector>
#include <queue>
#include <concepts>
template <typename T>
requires std::is_unsigned_v<T>
bool can_finish_course_schedule(const std::vector<std::vector<T>> & prerequisites, int number_of_courses)
{
    std::vector<T> in_degree(number_of_courses);
    std::vector<std::vector<T>> graph(number_of_courses);
    for(const auto & prerequisite: prerequisites )
    {
        graph[prerequisite[1]].push_back(prerequisite[0]);
        in_degree[prerequisite[0]]++;
    }
    
}
#endif //DATA_STRUCTURES_CAN_FINISH_COURSE_SCHEDULE_H
