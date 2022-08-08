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

// O(N*logN) ???
int size_of_longest_increasing_subsequence2(const std::vector<int>& sequence) {

	std::vector<int> sub_sequence;

	const int n = sequence.size();

	for(int i = 0; i < n; i++) {
		auto it = lower_bound(sub_sequence.begin(), sub_sequence.end(), sequence[i]);
		if(it != sub_sequence.end()) {
			*it = sequence[i];
		} else {
			sub_sequence.push_back(sequence[i]);
		}
	}
	return sub_sequence.size();
}


#endif //LONGEST_INCREASING_SUBSEQUENCE_H
