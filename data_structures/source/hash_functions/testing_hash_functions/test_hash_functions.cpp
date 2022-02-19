//
// Created by andreas on 19.02.22.
//

#include "test_hash_functions.h"


TestHashFunctions::TestHashFunctions()
{
	auto chi_squared = boost::math::chi_squared(65000);
	open_read_file_();
}


void TestHashFunctions::open_read_file_()
{
	datafile_.open(file_name_, std::ios::in);

	if(datafile_.is_open())
	{
		std::string word_string;
		while(std::getline(datafile_, word_string))
		{
			size_t character_sum{};
			for(const auto & single_character : word_string)
			{
				auto x = single_character;
				character_sum += static_cast<std::make_unsigned<char>::type>(single_character);
			}
			words_.push_back(character_sum);
		}
	}

}

