//
// Created by andreas on 08.10.24.
//

#ifndef FUN_WITH_STRINGS_MINIMUM_LENGTH_AFTER_REMOVING_SUBSTRINGS_H
#define FUN_WITH_STRINGS_MINIMUM_LENGTH_AFTER_REMOVING_SUBSTRINGS_H
// You are given a string s consisting only of uppercase English letters.
// You can apply some operations to this string where, in one operation,
// you can remove any occurrence of one of the substrings "AB" or "CD" from s.
// Return the minimum possible length of the resulting string that you can obtain.
// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
#include <string>
#include <stack>
#include <vector>

int minimum_length_stack(std::string &input) {
    std::stack<char> s;
    for (int i{}; i < input.length(); i++) {
        auto current_char = input[i];

        if (s.empty()) {
            s.push(current_char);
            continue;
        }

        if (current_char == 'B' && s.top() == 'A') {
            s.pop();
        } else if (current_char == 'D' && s.top() == 'C') {
            s.pop();
        } else {
            s.push(current_char);
        }
    }

    return s.size();
}

int minimum_length_optimal(std::string &input) {
    int write_index = 0;
    std::vector<char> charArray(input.begin(), input.end());

    for (int read_index{}; read_index < input.length(); read_index++) {
        charArray[write_index] = charArray[read_index];

        // Check if we have a valid pattern to remove
        if (write_index > 0 &&
            (charArray[write_index - 1] == 'A' ||
             charArray[write_index - 1] == 'C') &&
            charArray[write_index] == charArray[write_index - 1] + 1) // This tests if 'B' or 'D' is at write_index
        {
            write_index--;
        } else {
            write_index++;  // No match, so move the write pointer forward
        }
    }

    return write_index;
}


#endif //FUN_WITH_STRINGS_MINIMUM_LENGTH_AFTER_REMOVING_SUBSTRINGS_H
