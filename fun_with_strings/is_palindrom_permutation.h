//
// Created by andreas on 25.05.25.
//

#ifndef IS_PALINDROM_PERMUTATION_H
#define IS_PALINDROM_PERMUTATION_H
// Given a string, write a function to check if it is a permutation of a palindrome.

#include <string>
#include <unordered_map>
bool is_palindrome_permutation(std::string &input)
{
    std::unordered_map<char, int> frequency_map;
    for(const auto &c : input) {
      frequency_map[c]++;
    }
    int count_odd{};
    for( const auto &[c, freq] : frequency_map ) {
          if(freq & 1)
            count_odd++;
          if(count_odd >1)
            return false;
    }
    return true;
}

// Ignore casing and non-letter character
bool is_palindrome_permutation_ignore_case(std::string &input)
{
  std::array<int, 26> frequency{};
  for(const auto &c : input) {
    if(std::isalpha(c))
      frequency[std::tolower(c)-'a']++;
  }
  int count_odd{};
  for( const auto freq : frequency) {
    if(freq & 1)
      count_odd++;
    if(count_odd >1)
      return false;
  }
  return true;
}


#endif //IS_PALINDROM_PERMUTATION_H
