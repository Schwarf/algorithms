//
// Created by andreas on 19.04.25.
//

#ifndef MINIMUM_SWAPS_TO_MAKE_ALTERNATE_PATTERN_H
#define MINIMUM_SWAPS_TO_MAKE_ALTERNATE_PATTERN_H
// Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
// The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
// Any two characters may be swapped, even if they are not adjacent.
#include <string>
#include <algorithm>
#include <numeric>
int minimum_swaps_to_make_alternate_pattern(std::string& input)
{
  const int n = input.size();
  const int number_of_ones = std::count(input.begin(), input.end(), '1');
  const int number_of_zeros = n - number_of_ones;
  int minimum_count = std::numeric_limits<int>::max();
  int swap_count{};
  if( number_of_ones == (n + 1)/2 && number_of_zeros == n/2)
  {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0 && input[i] != '1')
            swap_count++;
      }
    minimum_count = std::min(minimum_count, swap_count);
  }
  else if(number_of_ones == n/2 && number_of_zeros == (n+1)/2)
  {
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0 && input[i] != '0')
        swap_count++;

      minimum_count = std::min(minimum_count, swap_count);

  }
  return minimum_count;
}

#endif //MINIMUM_SWAPS_TO_MAKE_ALTERNATE_PATTERN_H
