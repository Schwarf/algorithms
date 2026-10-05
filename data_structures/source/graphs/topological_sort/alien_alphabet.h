//
// Created by andreas on 05.10.26.
//

#ifndef CACHE_LATENCY_BENCHMARK_ALIEN_ALPHABET_H
#define CACHE_LATENCY_BENCHMARK_ALIEN_ALPHABET_H
// Alien Dictionary
//
// Given words sorted according to an unknown alphabet, return one valid
// ordering of the characters.
//
// Compare adjacent words and use the first differing character to derive
// ordering constraints.
//
// Example:
// {"wrt", "wrf", "er", "ett", "rftt"} -> "wertf"
//
/// Examples:
//
// ["z", "o"] -> "zo"
//
// ["hrn", "hrf", "er", "enn", "rfnn"] -> "hernf"
//
// ["abc", "ab"] -> ""
// Return "" if:
// - a longer word appears before its prefix, e.g. {"abc", "ab"}
// - the character dependencies contain a cycle

#include <string>
#include <vector>
#include <queue>

bool add_edge(std::vector<std::vector<int>> & edges, std::vector<int> & indegree, const std::string & w1, const std::string & w2 ) {
    int size = w1.size() > w2.size() ? w2.size() : w1.size();
    for (int i = 0; i < size; ++i) {
        if (w1[i] != w2[i]) {
            ++indegree[w2[i]-'a'];
            edges[w1[i]-'a'].push_back(w2[i]-'a');
            return true;
        }
    }
    return w1.size() <= w2.size();
}

std::string get_alphabet(const std::vector<std::string>& words ) {
    std::vector<int> indegree(26);
    std::vector<bool> exists(26);
    std::vector<std::vector<int>> edges(26);
    for (const auto& word : words) {
        for (const auto c: word) {
            exists[c - 'a'] = true;
        }
    }
    int existing = 0;
    for (bool e: exists) {
        if(e)
            ++existing;
    }
    for (int i{}; i < words.size()-1; ++i) {
        if (!add_edge(edges, indegree, words[i], words[i+1])) {
            return {};
        }
    }

    std::queue<int> q;
    for (int i{}; i < 26; ++i) {
        if (exists[i] && indegree[i] == 0) {
            q.push(i);
        }
    }
    int processed = 0;
    std::string result;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result += static_cast<char>('a'+current);
        ++processed;
        for (int neighbor : edges[current]) {
            --indegree[neighbor];
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return processed == existing ? result : std::string{};
}
#endif //CACHE_LATENCY_BENCHMARK_ALIEN_ALPHABET_H
