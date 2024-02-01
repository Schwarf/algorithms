//
// Created by andreas on 01.02.24.
//

#ifndef STACK_POLISH_NOTATION_H
#define STACK_POLISH_NOTATION_H
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
//Note that:
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
//     	The division between two integers always truncates toward zero.
//		There will not be any division by zero.
//		The input represents a valid arithmetic expression in a reverse polish notation.
//		The answer and all the intermediate calculations can be represented in a 32-bit integer.
#include <string>
#include <vector>
#include <stack>

int eval_polish_notation(std::vector<std::string> &tokens)
{
	std::stack<int> s;
	for (const auto &token: tokens) {

		if (token != "*" && token != "/" && token != "+" && token != "-") {
			s.push(std::stoi(token));
		}
		else {
			auto operand2 = s.top();
			s.pop();
			auto operand1 = s.top();
			s.pop();
			int result{};
			if (token == "/")
				result = operand1 / operand2;
			else if (token == "*")
				result = operand1 * operand2;
			else if (token == "+")
				result = operand1 + operand2;
			else if (token == "-")
				result = operand1 - operand2;

			s.push(result);
		}
	}
	return s.top();
}
#endif //STACK_POLISH_NOTATION_H
