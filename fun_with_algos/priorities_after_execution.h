//
// Created by andreas on 14.03.25.
//

#ifndef PRIORITIES_AFTER_EXECUTION_H
#define PRIORITIES_AFTER_EXECUTION_H

// Priorities after Execution
// Several processes are scheduled for execution on the servers.
// On one server, n processes are schedule where the ith process is assigned a priority of priority[i].
// The processes are placed sequentially in a queue and are numbered 1, 2,..,n.
// The server schedules the processes per the following algorithm:
// It finds the maximum priority shared by at least 2 processes. Let that be denoted by p .
// (if there is no such priority or p = 0 , the algorithm is terminated)
// Otherwise, select the two of the processes with the lowest indexes and priority p , call them process1 and process2 .
// The server executes process1 and removes it from the queue.
// To avoid starvation, it reduces the priority of process2 to floor(p/2) .
// Start again from step 1.
// Given the initial priority of the processes, find the final priority of the processes which remain after the algorithm terminates.
// Note that relative the arrangement of remaining processes in the queue remains the same,only their priorities change.
// Function Description
// Complete the function getPrioritiesAfterExecution in the editor.
//getPrioritiesAfterExecution has the following parameter:
//    int priority[n]: the initial prorities of processes
//Returns
//    int[]: the final priorities of the remaining processes
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>
#include <set>

int get_max_shared_priority(const std::vector<int>& priorities) {
    std::unordered_map<int, int> frequency_map;
    int max_shared_priority = 0;

    // Build a frequency map of priorities
    for (int priority : priorities) {
        frequency_map[priority]++;
        if (frequency_map[priority] > 1 && priority > max_shared_priority) {
            max_shared_priority = priority;
        }
    }

    return max_shared_priority; // Return the highest shared priority
}

    std::vector<int> priorities_after_execution_brute_force(std::vector<int> priorities) {
    while (true) {
        // Step 1: Find the maximum shared priority
        int max_shared_priority = get_max_shared_priority(priorities);
        if (max_shared_priority == 0) {
            break; // Terminate if no shared priority is found
        }

        bool first_found = false;
        for (size_t i = 0; i < priorities.size(); i++) {
            if (priorities[i] == max_shared_priority) {
                if (!first_found) {
                    // O(N) operation
                    priorities.erase(priorities.begin() + i);
                    i--; // Adjust the index after removal
                    first_found = true;
                } else {
                    priorities[i] = floor(max_shared_priority / 2.0);
                    break;
                }
            }
        }
    }
    return priorities; // Return the final priorities
}


struct Indices {
    int index1;
    int index2;
    int max_priority_value;
    Indices(int i1, int i2, int max_value) : index1(i1), index2(i2), max_priority_value(max_value) {}
};


Indices get_max_shared_priority(std::unordered_map<int, std::vector<int>> & frequency_map) {
    int max_shared_priority = 0;
    for (const auto& entry : frequency_map) {
        if (entry.second.size() >= 2) {
            max_shared_priority = std::max(max_shared_priority, entry.first);
        }
    }

    if (max_shared_priority == 0) {
        return Indices(-1, -1, max_shared_priority);
    }

    std::vector<int>& indexes = frequency_map[max_shared_priority];
    int index1 = indexes.front();
    indexes.erase(indexes.begin());
    int index2 = indexes.front();
    indexes.erase(indexes.begin());

    return Indices(index1, index2, max_shared_priority);
}

std::vector<int> priorities_after_execution(std::vector<int> priorities) {
    std::unordered_map<int, std::vector<int>> frequency_map;

    for (size_t i = 0; i < priorities.size(); i++) {
        frequency_map[priorities[i]].push_back(i);
    }

    std::vector<int> ans;
    while (true) {
        Indices max_shared_priority_index = get_max_shared_priority(frequency_map);
        int maxSharedPriority = max_shared_priority_index.max_priority_value;
        if (maxSharedPriority == 0) {
            for (int p : priorities) {
                if (p != -1) {
                    ans.push_back(p);
                }
            }
            break;
        }

        int index1 = max_shared_priority_index.index1;
        int index2 = max_shared_priority_index.index2;
        int newPriority = floor(maxSharedPriority / 2.0);
        priorities[index2] = newPriority;
        priorities[index1] = -1;

        frequency_map[newPriority].push_back(index2);
        std::sort(frequency_map[newPriority].begin(), frequency_map[newPriority].end());
    }

    return ans;
}


#endif //PRIORITIES_AFTER_EXECUTION_H
