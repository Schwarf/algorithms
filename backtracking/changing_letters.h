//
// Created by andreas on 03.11.26.
//

#ifndef ALGORITHMS_CHANGING_LETTERS_H
#define ALGORITHMS_CHANGING_LETTERS_H
// You are given a string s containing lowercase letters, uppercase letters, and digits.
//
// Generate all possible strings by changing the case of any letter.
// - Each letter can independently be uppercase or lowercase.
// - Digits must remain unchanged.
// - Return all possible strings without duplicates.
// - The order of the results does not matter.
// Example 1
// Input:
// s = "a1b2"
//
// Output:
// {"a1b2", "a1B2", "A1b2", "A1B2"}

#include <cctype>
#include <string>
#include <vector>

namespace changing_letters_detail
{
inline void backtrack(std::vector<std::string> & result, std::string & current, int index)
{
    if (index == current.size())
    {
        result.push_back(current);
        return;
    }

    if (std::isdigit(current[index]))
    {
        backtrack(result, current, index+1);
    }
    else
    {
        // do not change the letter
        backtrack(result, current, index+1);

        // change the letter accordingly
        if (std::islower(current[index]))
        {
            current[index] = static_cast<char>(std::toupper(current[index]));
            backtrack(result, current, index+1);
            current[index] = static_cast<char>(std::tolower(current[index]));
        }
        else
        {
            current[index] = static_cast<char>(std::tolower(current[index]));
            backtrack(result, current, index+1);
            current[index] = static_cast<char>(std::toupper(current[index]));
        }

    }
}
} // namespace changing_letters_detail


inline std::vector<std::string> changing_letters(std::string & s)
{
    std::vector<std::string> result;
    changing_letters_detail::backtrack(result, s, 0);
    return result;
}


#endif // ALGORITHMS_CHANGING_LETTERS_H
