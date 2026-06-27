//
// Created by andreas on 07.04.25.
//

#ifndef WORD_BREAK_H
#define WORD_BREAK_H
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a
// space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.
#include <unordered_set>
#include <vector>
#include <string>

bool word_break(const std::string & input, const std::vector<std::string> & words)
{
  std::unordered_set<std::string> dictionary(words.begin(), words.end());
  int size = input.size();
  std::vector<bool> dp(size+1, false);
  dp[0] = true;
  // Check for each index if substring input[0:i] can be segmented
  for(int i{}; i < size; ++i)
  {
      if(!dp[i])  // skip if s[0:i] is not segmentable
        continue;
      // Try every possible end index j for the word starting at i
      for(int j{i+1}; j <= size; ++j)
      {
          if (dictionary.find(input.substr(i, j - i)) != dictionary.end()) {
              dp[j] = true;
          }
      }
  }
  return dp[size];
}
#endif //WORD_BREAK_H
