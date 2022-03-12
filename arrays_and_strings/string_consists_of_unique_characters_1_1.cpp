#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

bool has_all_unique_characters_1(std::string & input)
{
	if(input.empty())
		return true;
	std::unordered_map<char, int> dictionary;
	std::for_each(input.begin(), input.end(), [](char & c) {
		c = std::toupper(c);
	});

	for (const auto & character : input) {
		dictionary[character] += 1;
		//std::cout << dictionary[character] << std::endl;
	}
	for(const auto & element : dictionary)
	{
		if(element.second > 1)
			return false;
	}
	return true;
}


bool has_all_unique_characters_2(std::string & input)
{
	if(input.empty())
		return true;
	std::for_each(input.begin(), input.end(), [](char & c) {
		c = std::toupper(c);
	});
	std::sort(input.begin(), input.end());
	for(size_t index = 1; index < input.size(); ++index)
	{
		if(input[index-1] == input[index])
			return false;
	}
	return true;
}

int main()
{
	std::string test="Hello";
	std::string test2="Helo1234567";
	std::string test3="1Helo1234567";
	std::string test4="1";
	std::string test5="";
	std::cout << "Ergebnis " << (has_all_unique_characters_1(test) == has_all_unique_characters_2(test)) << std::endl;
	std::cout << "Ergebnis " << (has_all_unique_characters_1(test2) == has_all_unique_characters_2(test2)) << std::endl;
	std::cout << "Ergebnis " << (has_all_unique_characters_1(test3) == has_all_unique_characters_2(test3)) << std::endl;
	std::cout << "Ergebnis " << (has_all_unique_characters_1(test4) == has_all_unique_characters_2(test4)) << std::endl;
	std::cout << "Ergebnis " << (has_all_unique_characters_1(test5) == has_all_unique_characters_2(test5)) << std::endl;
	return 0;
}
