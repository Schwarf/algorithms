//
// Created by andreas on 25.05.25.
//

#ifndef ARE_PERMUTATIONS_H
#define ARE_PERMUTATIONS_H
// Given two strings, write a method to decide if one is permutation of the other
#include <string>
#include <algorithm>
#include <unordered_map>
bool are_permutations(std::string & input1, std::string & input2)
{
  if(input1.size() != input2.size())
    return false;
  std::sort(input1.begin(), input1.end());
  std::sort(input2.begin(), input2.end());
  return std::equal(input1.begin(), input1.end(), input2.begin());
}

bool are_permutations_faster_but_memory(std::string & input1, std::string & input2)
{
  if(input1.size() != input2.size())
      return false;
  std::unordered_map<char, int> map1;
  std::unordered_map<char, int> map2;
  for(int i{}; i < input1.size(); i++)
  {
    ++map1[input1[i]];
    ++map2[input2[i]];
  }
  for(const auto & [c, frequency]: map1)
  {
      if(map2[c] != frequency)
        return false;
  }
  return true;
}

#endif //ARE_PERMUTATIONS_H

