//
// Created by andreas on 03.08.23.
//

#ifndef LETTER_COMBINATIONS_OF_PHONE_NUMBERS_H
#define LETTER_COMBINATIONS_OF_PHONE_NUMBERS_H
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
// could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 \
// does not map to any letters.
#include <vector>
#include <string>

void dfs(const std::string &digits,
		 int index,
		 std::string &path,
		 std::vector<std::string> &ans,
		 const std::vector<std::string> &map_digit_to_letters)
{
	if (index == digits.length()) {
		ans.push_back(path);
		return;
	}

	for (const char letter : map_digit_to_letters[digits[index] - '0']) {
		path.push_back(letter);
		dfs(digits, index + 1, path, ans, map_digit_to_letters);
		path.pop_back();
	}
}

}

std::vector<std::string> letter_combinations_of_phone_numbers(const std::string &digits)
{
	if (digits.empty())
		return {};

	const std::vector<std::string> map_digit_to_letters{"", "", "abc", "def", "ghi",
														"jkl", "mno", "pqrs", "tuv", "wxyz"};
	std::vector<std::string> result;
	std::string str;
	dfs(digits, 0, str, result, map_digit_to_letters);
	return result;

}

#endif //LETTER_COMBINATIONS_OF_PHONE_NUMBERS_H
