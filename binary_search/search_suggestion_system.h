//
// Created by andreas on 19.04.25.
//

#ifndef SEARCH_SUGGESTION_SYSTEM_H
#define SEARCH_SUGGESTION_SYSTEM_H
// You are given an array of strings products and a string searchWord.
// Design a system that suggests at most three product names from products after each character of searchWord is typed.
// Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix
// return the three lexicographically minimums products.
// Return a list of lists of the suggested products after each character of searchWord is typed.
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
    std::sort(products.begin(), products.end());
    int n = products.size();
    std::vector<std::vector<std::string>> result;
    std::string prefix{};
    int start{};
    int binary_search_start{};
    for(const auto c: searchWord)
    {
        prefix += c;
        start  = lower_bound(products.begin()+ binary_search_start, products.end(), prefix) - products.begin();
        result.push_back({});
        for(int i = start; i < std::min(start+3, n) && products[i].compare(0, prefix.size(), prefix) ==0 ; ++i)
        {
            result.back().push_back(products[i]);
        }
        binary_search_start = start;
    }
    return result;

}
#endif //SEARCH_SUGGESTION_SYSTEM_H
