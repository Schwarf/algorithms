//
// Created by andreas on 12.03.22.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool is_palindrome(std::string &input)
{
	if (input.empty())
		return true;
	if (input.size() == 1)
		return true;

	std::vector<bool> appeared(26, true);
	for_each(input.begin(), input.end(), [](char & character){character = std::tolower(character);});

	for(const auto & element : input)
	{

		if(std::isalpha(element)) {
			std::cout << element << std::endl;
			appeared[element] = !appeared[element];
		}
	}
	int counter = 0;
	for(const auto & element : input)
	{
		if(!element)
			counter++;
	}
	return counter < 2;

}

int main()
{
	std::string even_reference = "helhel";
	std::string uneven_reference = "helohel";
	std::string even_reference_bad = "helohhel";
	std::string even_reference_upper = "Helhel";
	std::string even_reference_comma = "hel,hel";
	std::cout << "Shall be 1 : " << is_palindrome(even_reference) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(uneven_reference) << std::endl;
	std::cout << "Shall be 0 : " << is_palindrome(even_reference_bad) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_upper) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_comma) << std::endl;
	return 0;
}
