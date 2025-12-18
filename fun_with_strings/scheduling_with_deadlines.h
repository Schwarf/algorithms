//
// Created by andreas on 18.12.25.
//

#ifndef ALGORITHMS_SCHEDULING_WITH_DEADLINES_H
#define ALGORITHMS_SCHEDULING_WITH_DEADLINES_H
// You are given a list of freelance jobs. Each job takes exactly 1 day to complete and can be done on any single day up to and including its deadline.
// You have only 7 days available (Day 1 through Day 7), and you can complete at most one job per day.
// Each job is represented as a map with two keys:
// "deadline": an integer deadline (may be greater than 7)
// "payment": an integer payment earned if the job is completed
// A job can be scheduled only if it is assigned to a day d such that:
// 1 <= d <= 7
// d <= deadline
// Your task is to compute the maximum total payment you can earn by choosing and scheduling jobs optimally.
#include <string>
#include <vector>
#include <unordered_map>

int optimal_freelancing(std::vector<std::unordered_map<std::string, int>> jobs)
{
    constexpr int WEEK = 7;
    std::sort(jobs.begin(), jobs.end(), [](std::unordered_map<std::string, int>& m1,
                                           std::unordered_map<std::string, int>& m2)
    {
        return m1["payment"] > m2["payment"];
    });
    std::vector<bool> time_slots(WEEK);
    int total = 0;
    for (auto &job : jobs)
    {
        int max_time_for_job = std::min(job["deadline"], WEEK);
        for (int time = max_time_for_job; time > 0; --time)
        {
            if (!time_slots[time])
            {
                time_slots[time] = true;
                total += job["payment"];
                break;
            }
        }
    }
    return total;
}
#endif //ALGORITHMS_SCHEDULING_WITH_DEADLINES_H
