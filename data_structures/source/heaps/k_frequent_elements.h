//
// Created by andreas on 21.06.25.
//

#ifndef K_FREQUENT_ELEMENTS_H
#define K_FREQUENT_ELEMENTS_H
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
#include <vector>
#include <queue>
#include <unordered_map>
std::vector<int> k_frequent_elements(std::vector<int> input, int k) {
     std::unordered_map<int, int> counts;
     for(const auto element: input)
     {
       ++counts[element];
     }
     std::vector<int> result;
     auto compare = [](const std::pair<int, int> & p1, const std::pair<int, int> & p2){
       return p1.second < p2.second;
     };
     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> queue;
     for(const auto & [element, count]: counts)
     {
           queue.emplace(element, count);
     }
     while(k-- && !queue.empty())
     {
       result.push_back(queue.top().first);
       queue.pop();
     }
    return result;
}
#endif //K_FREQUENT_ELEMENTS_H
