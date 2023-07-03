//
// Created by andreas on 03.07.23.
//

#ifndef LONGEST_VALID_PARENTHESES_STRING_H
#define LONGEST_VALID_PARENTHESES_STRING_H

#include <string>
#include <stack>
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed)
//	parentheses substring


int longest_valid_paratheses_string(const std::string &input)
{
	std::stack<int> s{{-1}};
	int max{};
	for (int i{}; i < input.size(); ++i) {
		// We push the indices to the stack
		if (input[i] == '(')
			s.push(i);
		else {
			s.pop();
			// if stack is empty a ')' will not help so we just push its index
			if (s.empty())
				s.push(i);
			else
				max = std::max(max, i - s.top());
		}
	}
	return max;
}

#endif //LONGEST_VALID_PARENTHESES_STRING_H
