//
// Created by andreas on 12.03.22.
//

#include <iostream>
#include <string>
#include <algorithm>


bool are_one_edit_away(std::string & shorter, std::string & longer)
{
	for(size_t index =0 ; index < shorter.size() ; ++ index)
	{
		if(shorter[index] != longer[index] && shorter[index] != longer[index+1] ) {
			return false;
		}

	}
	return true;
}


bool are_two_strings_one_edit_away(std::string & input1, std::string & input2)
{
	if (input1 == input2)
		return true;
	if(input1.empty() && input2.size() == 1)
		return true;
	if(input2.empty() && input1.size() == 1)
		return true;

	if(input1.size() + 1 !=  input2.size() &&
	   input1.size() - 1 !=  input2.size() &&
	   input1.size()  !=  input2.size())
		return false;

	if(input1.size() > input2.size())
	{
		return are_one_edit_away(input2, input1);
	}
	else if(input2.size() > input1.size())
	{
		return are_one_edit_away(input1, input2);
	}
	else
	{
		int counter{};
		for(size_t index =0 ; index < input1.size() ; ++ index)
		{
			if(input1[index] != input2[index])
				counter++;
			if(counter > 1)
				return false;
		}
	}
	return true;
}



int main()
{
	std::string reference="hello";
	std::string replace_at_the_end="hella";
	std::string permutation="ohell";
	std::string missing_last_one="hell";
	std::string missing_2nd_one="hllo";
	std::string missing_3rd_one="helo";
	std::string missing_first_one="ello";
	std::string replace_in_the_middle="helgo";
	std::string replace_2_in_the_middle_end="helga";
	std::cout << "Shall be 1 = " << are_two_strings_one_edit_away(reference, replace_at_the_end) << std::endl;
	std::cout << "Shall be 0 = " << are_two_strings_one_edit_away(reference, permutation) << std::endl;
	std::cout << "Shall be 1 = " << are_two_strings_one_edit_away(reference, missing_last_one) << std::endl;
	std::cout << "Shall be 1 = " << are_two_strings_one_edit_away(reference, missing_2nd_one) << std::endl;
	std::cout << "Shall be 1 = " << are_two_strings_one_edit_away(reference, missing_3rd_one) << std::endl;
	std::cout << "Shall be 1 = " << are_two_strings_one_edit_away(reference, missing_first_one) << std::endl;
	std::cout << "Shall be 0 = " << are_two_strings_one_edit_away(reference, replace_2_in_the_middle_end) << std::endl;

	return 0;
}
