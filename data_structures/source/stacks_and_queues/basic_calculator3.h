//
// Created by andreas on 28.06.25.
//

#ifndef BASIC_CALCULATOR3_H
#define BASIC_CALCULATOR3_H
// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Constraints:
//
//    1 <= s <= 104
//    s consists of digits, '+', '-', '*', '/', '(', and ')'.
//    s is a valid expression.
#include <string>
#include <stack>

int apply_opeartion(char operation, int x, int y)
{
    switch (operation)
    {
    case '+': return x;
    case '-': return -x;
    case '*': return x * y;
    case '/': return x / y; // integer division truncates toward zero
    }
    return 0; // should never hit
}

int compute(const std::string& input, int& index)
{
    std::stack<int> stack;
    int current_number = 0;
    char last_operation = '+';
    while (index < input.length())
    {
        char current_char = input[index];
        if (current_char == '(')
        {
            ++index;
            current_number = compute(input, index);
        }
        else if (std::isdigit(current_char))
        {
            current_number = current_number * 10 + (current_char - '0');
        }
        else if (current_char != ' ')
        {
            if (last_operation == '*' || last_operation == '/')
            {
                int value = stack.top();
                stack.pop();
                stack.push(apply_opeartion(last_operation, value, current_number));
            }
            else
                stack.push(apply_opeartion(last_operation, current_number, 0));

            if (current_char == ')')
                break;
            current_number = 0;
            last_operation = current_char;
        }
        index++;
    }

    int sum{};
    while (!stack.empty())
    {
        sum += stack.top();
        stack.pop();
    }
    return sum;
}

int calculated3(std::string input)
{
    input.push_back('@');
    int index = 0;
    return compute(input, index);
}

#endif //BASIC_CALCULATOR3_H
