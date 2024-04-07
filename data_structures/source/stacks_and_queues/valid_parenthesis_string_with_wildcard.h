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
bool is_parenthesis_string_with_wildcard_valid(std::string s)
{
	std::stack<int> stackOpen;
	std::stack<int> stackStar;
	for (int i{}; i < s.size(); ++i) {
		if (s[i] == '*')
			stackStar.push(i);
		else if (s[i] == '(') {
			stackOpen.push(i);
		}
		else if (s[i] == ')') {
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

#endif //VALID_PARANTHESIS_STRING_H
