//
// Created by andreas on 07.04.24.
//

#ifndef VALID_PARANTHESIS_STRING_H
#define VALID_PARANTHESIS_STRING_H
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// - Any right parenthesis ')' must have a corresponding left parenthesis '('.
// - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

#include<stack>
#include<string>
bool is_parenthesis_string_with_wildcard_valid(std::string input)
{
	std::stack<int> stackOpen;
	std::stack<int> stackStar;
	for (int i{}; i < input.size(); ++i) {
		if (input[i] == '*')
			stackStar.push(i);
		else if (input[i] == '(') {
			stackOpen.push(i);
		}
		else if (input[i] == ')') {
			if (!stackOpen.empty())
				stackOpen.pop();
			else if (!stackStar.empty())
				stackStar.pop();
			else
				return false;
		}
	}

	while (!stackOpen.empty() && !stackStar.empty()) {
		if (stackOpen.top() > stackStar.top()) {
			return false;
		}
		stackOpen.pop();
		stackStar.pop();

	}

	return stackOpen.empty();
}

bool is_parenthesis_string_with_wildcard_valid_optimized(std::string input)
{
	int openCount{};
	int closeCount{};
	int length = input.length();
	// Traverse the string from both ends simultaneously
	for (int i{}; i < length; i++) {
		// Count open parentheses or asterisks
		if (input[i] == '(' || input[i] == '*') {
			openCount++;
		}
		else {
			openCount--;
		}

		// Count close parentheses or asterisks
		if (input[length - i - 1] == ')' || input[length - i - 1] == '*') {
			closeCount++;
		}
		else {
			closeCount--;
		}

		// If at any point open count or close count goes negative, the string is invalid
		if (openCount < 0 || closeCount < 0) {
			return false;
		}
	}

	// If open count and close count are both non-negative, the string is valid
	return true;
}
#endif //VALID_PARANTHESIS_STRING_H
