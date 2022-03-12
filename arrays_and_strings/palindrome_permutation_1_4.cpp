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
			appeared[element - 'a'] = !appeared[element - 'a'];
		}
	}
	int counter = 0;
	for(const auto & element : appeared)
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
	std::string even_reference_crap = "hel,!,)hel*";
	std::string even_reference_crap_bad = "cel,!,)hel*";
	std::string even_reference_crap2 = "yyhel,!,)hel*zzp";
	std::cout << "Shall be 1 : " << is_palindrome(even_reference) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(uneven_reference) << std::endl;
	std::cout << "Shall be 0 : " << is_palindrome(even_reference_bad) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_upper) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_comma) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_crap) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_crap_bad) << std::endl;
	std::cout << "Shall be 1 : " << is_palindrome(even_reference_crap2) << std::endl;
	return 0;
}
