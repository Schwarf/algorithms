//
// Created by andreas on 26.05.25.
//

#ifndef ARE_TWO_STRINGS_ONE_EDIT_AWAY_H
#define ARE_TWO_STRINGS_ONE_EDIT_AWAY_H
// There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.
#include <string>

bool are_one_edit_away(const std::string& first, const std::string& second)
{
    int len1 = first.size();
    int len2 = second.size();
    if (std::abs(len1 - len2) > 1)
        return false;

    // Identify shorter/longer
    const std::string& shorter = (len1 < len2) ? first : second;
    const std::string& longer = (len1 < len2) ? second : first;

    bool found_difference{};
    int short_index{};
    int long_index{};
    while (short_index < shorter.size() && long_index < longer.size())
    {
        if (shorter[short_index] != longer[long_index])
        {
            if (found_difference)
                return false;
            found_difference = true;
            // If same length, advance both pointers (replace case).
            // If different, only advance the longer one (insert/remove case).
            if (shorter.size() == longer.size())
            {
                ++short_index;
            }
        }
        else
        {
            ++short_index;
        }
        ++long_index; // always advance pointer for longer string
    }
    return true;
}

#endif //ARE_TWO_STRINGS_ONE_EDIT_AWAY_H
