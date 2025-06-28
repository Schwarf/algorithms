//
// Created by andreas on 28.06.25.
//

#ifndef BASIC_CALCULATOR_2_H
#define BASIC_CALCULATOR_2_H
// Given a string s which represents an expression, evaluate this expression and return its value.
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Constraints:
//
//     1 <= s.length <= 3 * 105
//     s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
//     s represents a valid expression.
//     All the integers in the expression are non-negative integers in the range [0, 231 - 1].
//     The answer is guaranteed to fit in a 32-bit integer.


#include <string>
#include <stack>
#include <cwctype>

int calculated2(const std::string& input)
{
    int n = input.length();
    if (n == 0)
        return 0;
    std::stack<int> stack;
    int current_number = 0;
    char last_operator = '+';
    for (int i = 0; i < n; i++)
    {
        char current_char = input[i];
        if (std::isdigit(current_char))
            current_number = current_number * 10 + (current_char - '0');
        if ((!std::isdigit(current_char) && current_char != ' ') || i == n - 1)
        {
            if (last_operator == '-')
            {
                stack.push(-current_number);
            }
            else if (last_operator == '+')
            {
                stack.push(current_number);
            }
            else if (last_operator == '*')
            {
                int factor = stack.top();
                stack.pop();
                stack.push(factor * current_number);
            }
            else if (last_operator == '/')
            {
                int dividend = stack.top();
                stack.pop();
                stack.push(dividend / current_number);
            }
            last_operator = current_char;
            current_number = 0;
        }
    }
    int result{};
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    return result;;
}
#endif //BASIC_CALCULATOR_2_H
