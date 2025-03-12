//
// Created by andreas on 12.03.25.
//

#ifndef MIN_SWAPS_FOR_PALINDROME_H
#define MIN_SWAPS_FOR_PALINDROME_H
// Given a binary string (as an integer array), return the minimum number of swaps needed to make the binary string a palindrome.
#include <vector>
int min_swaps_for_palindrome(std::vector<int> & binary_string)
{
    int n = binary_string.size();
    int swaps = 0;

    int left = 0, right = n - 1;
    while (left < right) {
        if (binary_string[left] == binary_string[right]) {
            left++;
            right--;
        } else {
            // Find the matching character for binary_string[right] by scanning from right to left
            int r = right;
            while (r > left && binary_string[r] != binary_string[left]) {
                r--;
            }
            
            if (r == left) { 
                // No matching character found, it's an odd character
                // Swap it towards the center (brute-force way)
                std::swap(binary_string[left], binary_string[left + 1]);
                swaps++;
            } else {
                // Swap adjacent characters to move binary_string[r] to position right
                while (r < right) {
                    std::swap(binary_string[r], binary_string[r + 1]);
                    swaps++;
                    r++;
                }
                left++;
                right--;
            }
        }
    }
    
    return swaps;
}

#endif //MIN_SWAPS_FOR_PALINDROME_H
