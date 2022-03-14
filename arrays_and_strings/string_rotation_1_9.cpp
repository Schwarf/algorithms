//
// Created by andreas on 13.03.22.
//
#include <string>
#include <iostream>

bool has_sub_string(std::string & string, std::string & sub_string, size_t start_index2)
{
	return string.substr(0, start_index2).find(sub_string) != std::string::npos;
}


bool are_strings_rotated(std::string & input1, std::string &input2)
{
	if (input1.empty() && input2.empty())
		return true;
	if (input1.size() != input2.size())
		return false;

	size_t index1{};
	size_t index2{};
	int start_index2 = -1;

	while (index2 < input2.size()) {
		if (input1[index1] == input2[index2]) {
			if (start_index2 == -1) {
				start_index2 = index2;
			}
			index1++;
			index2++;
		}
		else {
			if (start_index2 != -1) {
				break;
			}
			index2++;
		}
	}

	int end_index1 = index1;
	if(start_index2 == 0 && end_index1 == input1.size()-1)
		return true;
	auto sub_string = input1.substr(end_index1, input1.size() - end_index1);
	return has_sub_string(input2, sub_string, start_index2);
}

int main()
{
	std::string works_string1 = "abcdefg";
	std::string works_string2 = "fgabcde";

	std::string equal_string1 = "abcdefg";
	std::string equal_string2 = "abcdefg";

	std::string not_string1 = "12345678";
	std::string not_string2 = "12345687";

	std::string wb_string1 = "waterbottle";
	std::string wb_string2 = "erbottlewat";


	std::cout <<  are_strings_rotated(works_string1, works_string2) << std::endl;
	std::cout <<  are_strings_rotated(equal_string1, equal_string2) << std::endl;
	std::cout <<  are_strings_rotated(not_string1, not_string2) << std::endl;
	std::cout <<  are_strings_rotated(wb_string1, wb_string2) << std::endl;
}