//
// Created by andreas on 25.05.25.
//

#ifndef URLIFY_STRING_H
#define URLIFY_STRING_H
// Write a method to replace all spaces n a string with `%20`. You may assume that the string
// has sufficient space at the end to hold additional characters and you are provided with the
// true size of the string.
#include <algorithm>
#include <string>

// true_size is the size of the string without the additional space
std::string urlify_string(const std::string& input, size_t true_size) {
    // 1) Count how many spaces are in the "real" part
    size_t space_count = std::count(
        input.begin(),
        input.begin() + std::min(true_size, input.size()),
        ' '
    );

    // 2) Reserve exact final size: each space adds 2 extra chars ("%20" vs " ")
    std::string result;
    result.reserve(true_size + space_count * 2);

    // 3) Build
    for (size_t i = 0; i < true_size && i < input.size(); ++i) {
        if (input[i] == ' ')
            result += "%20";
        else
            result.push_back(input[i]);
    }

    return result;
}

void urlify_string_in_place(std::string& input, size_t true_size)
{
    std::string result;
    int space_count {};
    const char space = ' ';
    for (size_t i = 0; i < true_size; ++i)
    {
        if (input[i] == space)
            ++space_count;
    }

    // Compute the final length
    size_t new_len = true_size + space_count * 2;
    // (buffer must already be >= new_len)

    // Traverse backward, writing into [0..new_len-1]
    size_t back_index = new_len - 1;
    for (size_t index{true_size}; index--;)
    {
        if (input[index] == space)
        {
            input[back_index--] = '0';
            input[back_index--] = '2';
            input[back_index--] = '%';
        }
        else
            input[back_index--] = input[index];
        if (back_index == 0)
            break;
    }
    input.resize(new_len);
}

#endif //URLIFY_STRING_H
