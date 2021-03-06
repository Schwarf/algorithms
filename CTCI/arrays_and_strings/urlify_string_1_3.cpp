//
// Created by andreas on 12.03.22.
//
#include <iostream>
#include <string>
#include <algorithm>

std::string urlify(std::string &input, size_t true_size)
{
	char space = ' ';
	std::string result;
	size_t count = 0;
	for (size_t index = 0; index < true_size; ++index) {
		if (space == input[index]) {
			result.append("%20");
			continue;
		}
		result.append(1, input[index]);
		count++;
	}
	return result;
}

std::string optimized_urlify(std::string &input, size_t true_size)
{
	char space = ' ';
	if(true_size == input.size())
		return input;
	size_t back_index = input.size() - 1;
	for (size_t index = true_size ; index--;) {
		if(input[index] == space)
		{
			input[back_index--] = '0';
			input[back_index--] = '2';
			input[back_index--] = '%';
		}
		else
		{
			input[back_index--] = input[index];
		}
		if(back_index == 0)
			break;
	}
	return input;
}


int main()
{
	std::string test = "hello its me    ";
	size_t test_size{12};
	std::string test2 = "hello its me. Who are you          ";
	size_t test2_size{25};
	auto result = urlify(test, test_size);
	auto result2 = urlify(test2, test2_size);
	std::cout << result << std::endl;
	std::cout << result2 << std::endl;
	std::cout << (result.size() == test.size()) << std::endl;
	std::cout << (result2.size() == test2.size()) << std::endl;
	auto result_new = optimized_urlify(test, test_size);
	std::cout << result_new << std::endl;
	return 0;
}
