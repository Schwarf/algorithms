//
// Created by andreas on 20.07.22.
//

#ifndef LONGEST_INCREASING_SUBSEQUENCE_H
#define LONGEST_INCREASING_SUBSEQUENCE_H
#include <vector>
#include <algorithm>
// O(N^2)
int size_of_longest_increasing_subsequence(const std::vector<int> &sequence)
{
	const int size = sequence.size();
	std::vector<int> help(size, 1);
	for(int i{1}; i < size; i++)
	{
		for(int j{0}; j < i; j++)
		{
			if(sequence[i] > sequence[j])
			{
				help[i] = std::max(help[i], help[j]+1);
			}
		}
	}
	return *std::max_element(help.begin(), help.end());
}

#endif //LONGEST_INCREASING_SUBSEQUENCE_H
