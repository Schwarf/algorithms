//
// Created by andreas on 28.06.25.
//

#ifndef BASIC_CALCULATOR_H
#define BASIC_CALCULATOR_H
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Constraints:
//    1 <= s.length <= 3 * 105
//    s consists of digits, '+', '-', '(', ')', and ' '.
//    s represents a valid expression.
//    '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
//    '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
//    There will be no two consecutive operators in the input.
//    Every number and running calculation will fit in a signed 32-bit integer.
#include <string>
#include <stack>
int calculate(const std::string & input)
{
  std::stack<int> stack;
  int result = 0;
  int sign = 1;
  int n = input.size();
  for(int i{}; i < n; ++i)
  {
    char c= input[i];
    if(std::isdigit(c))
    {
        long number = c - '0';
        while( i + 1 < n && std::isdigit(input[i + 1])){
          i++;
          number = number * 10 + (input[i] - '0');
        }
        result += sign *number;
    }
    else if(c == '+')
      sign = 1;
     else if(c == '-')
       sign = -1;
     else if(c == '(')
     {
       stack.push(result);
       stack.push(sign);
       result = 0;
       sign = 1;
     }
     else if(c == ')')
     {
       int previous_sign = stack.top();
       stack.pop();
       int previous_result = stack.top();
       stack.pop();
       result = previous_result + previous_sign *result;
     }
  }
  return result;
}
#endif //BASIC_CALCULATOR_H

