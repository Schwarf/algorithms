//
// Created by andreas on 27.09.23.
//

#ifndef DECODE_STRING_AT_INDEX_H
#define DECODE_STRING_AT_INDEX_H
// You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a
// time and the following steps are taken:
// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
// Given an integer k, return the kth letter (1-indexed) in the decoded string.
#include <string>

std::string decode_at_index(const std::string & input, int k)
{
	int index{};
	long long length{};
	while(length < k)
	{
		std::isdigit(input[index]) ? (length *= (input[index] -'0')) : length++;
		index++;
	}
	for(int j{index-1}; j > -1; --j)
	{
		if(std::isdigit[input[j]])
		{
			length /= input[j] - '0';
			k %= length;
		}
		else
		{
			if(k==0 || k ==length)
				return input.substr(j, 1);
			length--;
		}
	}
	return {};


}

#endif //DECODE_STRING_AT_INDEX_H
