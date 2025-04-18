//
// Created by andreas on 18.04.25.
//

#ifndef PLATES_BETWEEN_CANDLES_H
#define PLATES_BETWEEN_CANDLES_H
// There is a long table with a line of plates and candles arranged on top of it.
// You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*'
// represents a plate and a '|' represents a candle.
// You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the
// substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between
// candles that are in the substring. A plate is considered between candles if there is at least one candle
// to its left and at least one candle to its right in the substring.
// For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of
// plates between candles in this substring is 2, as each of the two plates has at least one candle
// in the substring to its left and right.
//
//Return an integer array answer where answer[i] is the answer to the ith query.
#include <vector>
#include <string>
std::vector<int> plates_between_candles(std::string & input, std::vector<std::vector<int> > & queries)
{
    int n = input.size();
    std::vector<int> prefix_plates(n, 0);
    std::vector<int> nearest_left_candles(n ,-1);
    std::vector<int> nearest_right_candles(n, -1);
    std::vector<int> result;
    // Compute prefix-sum of plates and nearest-left candle
    int plate_count = 0;
    int last_candle = -1;
    for (int i = 0; i < n; ++i) {
        if (input[i] == '*')
            ++plate_count;
        if (input[i] == '|')
            last_candle = i;
      prefix_plates[i] = plate_count;
      nearest_left_candles[i] = last_candle;
    }
    last_candle = -1;
    for (int i = n-1; i > -1; --i) {
        if (input[i] == '|')
            last_candle = i;
        nearest_right_candles[i] = last_candle;
    }

    for(const auto & query: queries) {
    // the left candle is either on the query index or right of the query index
        auto left_candle = nearest_right_candles[query[0]];
    // the right candle is either on the query index or left of the query index
        auto right_candle = nearest_left_candles[query[1]];
        if (left_candle != -1 && right_candle != -1 && left_candle < right_candle) {
            result.push_back(prefix_plates[right_candle] - prefix_plates[left_candle]);
        } else {
            result.push_back(0);
        }

    }

    return result;
}


#endif //PLATES_BETWEEN_CANDLES_H
