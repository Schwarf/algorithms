//
// Created by andreas on 26.05.25.
//

#ifndef STRING_COMPRESSION_H
#define STRING_COMPRESSION_H
// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z)
#include <string>
std::string compression(const std::string& input) {
  int n = input.size();
  char last = input[0];
  std::string result{};
  for(int i{1}; i < n; i++) {
      int count{1};
      while(input[i] == last && i < n) {
        count++;
          i++;
      }
      result += std::to_string(count)+last;
      last = input[i];
  }
   return result.size() < n ? result : input;
}

#endif //STRING_COMPRESSION_H
