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

void urlify_string_in_place(std::string& input, size_t true_size) {
    // 1) Count spaces in the “real” part [0..true_size)
    size_t space_count = std::count(
        input.begin(),
        input.begin() + std::min(true_size, input.size()),
        ' '
    );

    // 2) Compute the final length after replacing each ' ' with "%20"
    size_t new_len = true_size + space_count * 2;
    input.resize(new_len);

    // 3) Walk backwards, writing into [0..new_len-1]
    //    i points just past the last real character; j just past the final slot
    size_t i = true_size;
    size_t j = new_len;
    while (i-- > 0) {
        if (input[i] == ' ') {
            input[--j] = '0';
            input[--j] = '2';
            input[--j] = '%';
        } else {
            input[--j] = input[i];
        }
    }

    // 4) (Optional) shrink the string down if there’s extra padding
    input.resize(new_len);
}
#endif //URLIFY_STRING_H
