//
// Created by andreas on 03.02.25.
//

#ifndef DECODE_STRING_H
#define DECODE_STRING_H
// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated
// exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces,
// square brackets are well-formed, etc. Furthermore, you may assume that the original data does
// not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.
#include <string>
#include <stack>

std::string decode_string(const std::string& input)
{
    std::stack<char> stack;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ']')
        {
            std::string decoded_string = "";
            // get the encoded string
            while (stack.top() != '[')
            {
                decoded_string += stack.top();
                stack.pop();
            }
            // pop [ from stack
            stack.pop();
            int base{1};
            int factor{};
            // get the number k
            while (!stack.empty() && isdigit(stack.top()))
            {
                factor += (stack.top() - '0') * base;
                stack.pop();
                base *= 10;
            }

            // decode k[decodedString], by pushing decodedString k times into stack
            while (factor != 0)
            {
                for (int j = decoded_string.size() - 1; j >= 0; j--)
                {
                    stack.push(decoded_string[j]);
                }
                factor--;
            }
        }
        else
        {
            stack.push(input[i]);
        }
    }
    // get the result from stack
    std::string result{};
    result.reserve(stack.size());
    for (int i = stack.size() - 1; i >= 0; i--)
    {
        result = stack.top() + result;
        stack.pop();
    }
    return result;
}

#endif //DECODE_STRING_H
