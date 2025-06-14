//
// Created by andreas on 14.06.25.
//

#ifndef STRING_ROTATION_H
#define STRING_ROTATION_H
// String Rotation; Assume you have a method 'isSubString' which checks if one word is a substring
// of another. Given two strings, si and s2, write code to check if s2 is a rotation of si using only one
// call to `isSubstring` [e.g., " waterbottle" is a rotation o P 'erbottlewat " )
#include <string>

bool isSubstring(const std::string& haystack, const std::string& needle)
{
  return haystack.find(needle) != std::string::npos;
}

bool is_string_rotated(const std::string& input, const std::string& rotated) {

  if(input.size() != rotated.size() || input.empty()) {
    return false;
  }
  std::string concatenated = input + input;
  return isSubstring(concatenated, rotated);
}


#endif //STRING_ROTATION_H
