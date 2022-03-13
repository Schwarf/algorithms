//
// Created by andreas on 12.03.22.
//

#include <iostream>
#include <string>
#include <algorithm>

bool are_two_strings_permutations_of_each_other(std::string &string1, std::string &string2)
{
	if (string1.empty() && string2.empty())
		return true;
	if (string1.empty() && !string2.empty())
		return false;
	if (!string1.empty() && string2.empty())
		return false;
	if (string1.size() != string2.size())
		return false;

	std::sort(string1.begin(), string1.end());
	std::sort(string2.begin(), string2.end());
	for (auto index = 0; index < string1.size(); ++index) {
		if (string1[index] != string2[index])
			return false;
	}
	return true;
}

int main()
{
	std::string test = "hello";
	std::string test2 = "elloh";
	std::string test3 = "hoell";
	std::string test4 = "hoel";
	std::string test5;
	std::string test6;
	std::cout << "Ergebnis " << are_two_strings_permutations_of_each_other(test, test2) << std::endl;
	std::cout << "Ergebnis " << are_two_strings_permutations_of_each_other(test, test3) << std::endl;
	std::cout << "Ergebnis " << are_two_strings_permutations_of_each_other(test2, test3) << std::endl;
	std::cout << "Ergebnis " << are_two_strings_permutations_of_each_other(test2, test4) << std::endl;
	std::cout << "Ergebnis " << are_two_strings_permutations_of_each_other(test5, test6) << std::endl;
	return 0;
}
