//
// Created by andreas on 19.03.24.
//

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H
// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n.
// Each cycle or interval allows the completion of one task. Tasks can be completed in any order,
// but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
// Return the minimum number of intervals required to complete all tasks.
#include <vector>
#include <queue>

int time_needed_for_scheduling_tasks(const std::vector<char> &tasks, int minimum_interval_between_identical_tasks) {
    std::vector<int> frequencies(26, 0);
    for (const auto &c: tasks) {
        frequencies[c - 'A']++;
    }
    std::priority_queue<int> q;
    for (const auto &freq: frequencies) {
        if (freq > 0)
            q.push(freq);
    }
    int time{};
    while (!q.empty()) {
        int cycle = minimum_interval_between_identical_tasks + 1;
        std::vector<int> store{};
        int task_count{};
        // Go through all jobs and reduce their number by one (as long as the cycle-space is large enough)
        while (cycle-- && !q.empty()) {
            if (q.top() > 1)
                store.push_back(q.top() - 1);
            q.pop();
            task_count++;
        }
        // Re-enter the by-one-reduced jobs to the queue
        for (auto x: store)
            q.push(x);
        // if the queue is empty we add the task_count if not we just add the maximum
        time += (q.empty() ? task_count : minimum_interval_between_identical_tasks + 1);
    }
    return time;
}

int time_needed_for_scheduling_tasks_via_sort(const std::vector<char> &tasks,
                                              int minimum_interval_between_identical_tasks) {
    std::vector<int> frequencies(26);
    for (const auto &c: tasks) {
        frequencies[c - 'A']++;
    }
    std::sort(frequencies.begin(), frequencies.end());
    auto gaps_between_max_tasks = frequencies.back() - 1;
    auto idle_slots = gaps_between_max_tasks * minimum_interval_between_identical_tasks;
    // Fill gaps using tasks other than the most frequent one (at index 25)
    for (int i{24}; i >= 0 && frequencies[i] > 0; --i) {
        idle_slots -= std::min(gaps_between_max_tasks, frequencies[i]);
    }
    return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}


#endif //TASK_SCHEDULER_H
