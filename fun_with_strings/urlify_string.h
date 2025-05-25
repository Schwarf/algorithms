//
// Created by andreas on 25.05.25.
//

#ifndef URLIFY_STRING_H
#define URLIFY_STRING_H
// Write a method to replace all spaces n a string with `%20`. You may assume that the string
// has sufficient space at the end to hold additional characters and you are provided with the
// true size of the string.
#include <string>
std::string urlify_string(std::string & input, size_t true_size)
{
    std::string result;
    const char space = ' ';
    for(size_t index{}; index < true_size; ++index ) {
      if(input[index] == space)
        result += "%20";
      else
        result += input[index];
    }
    return result;
}

void urlify_string_in_place(std::string & input, size_t true_size)
{
    std::string result;
    const char space = ' ';
    size_t back_index = true_size - 1;
    for(size_t index{true_size}; index--; ) {
        if(input[index] == space)
        {
            input[back_index--] = '0';
            input[back_index--] = '2';
            input[back_index--] = '%';
        }
        else
            input[back_index--] = input[index];
    }
}

#endif //URLIFY_STRING_H
