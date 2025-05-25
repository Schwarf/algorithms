//
// Created by andreas on 25.05.25.
//

#ifndef HAS_ONLY_UNIQUE_CHARACTERS_H
#define HAS_ONLY_UNIQUE_CHARACTERS_H
// Implement an algorithm to determineif a string has all but unique charactesrs. What if you cannot use additional data
// structures?
#include <string>
#include <unordered_map>
#include <algorithm>

bool has_unique_chars(const std::string & input)
{
  std::unordered_map<char, int> frequence_counter;
  for (const auto & c : input)
  {
    if(frequence_counter.contains(c))
      return false;
    ++frequence_counter[c];
  }
  return true;
}

bool has_unique_chars_no_additional_memory(const std::string & input)
{
  for (auto & c : input)
  {
    c = std::tolower(c);
  }
  std::sort(input.begin(), input.end());
  for(int i{1}; i < input.length(); ++i)
  {
    if(input[i] == input[i - 1])
      return false;
  }
  return true;
}

#endif //HAS_ONLY_UNIQUE_CHARACTERS_H
