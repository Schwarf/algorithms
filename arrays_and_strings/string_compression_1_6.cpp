//
// Created by andreas on 12.03.22.
//
#include <string>
#include <algorithm>
#include <iostream>

std::string compression(std::string &input)
{
	if (input.size() < 2)
		return input;
	std::string result{};
	int counter{1};
	result.append(1, input[0]);
	for (size_t index = 1; index < input.size(); ++index) {
		if (input[index] == input[index - 1])
			counter++;
		else {
			result.append(std::to_string(counter));
			result.append(1, input[index]);
			counter = 1;
		}
	}
	result.append(std::to_string(counter));
	if (result.size() == 2 * input.size())
		return input;

	return result;
}

int main()
{
	std::string reference1 = "haahhyyioo";
	std::string reference2 = "hahyio";
	std::string reference3 = "hahhyio";
	std::cout << compression(reference1) << std::endl;
	std::cout << compression(reference2) << std::endl;
	std::cout << compression(reference3) << std::endl;
	return 0;
}
