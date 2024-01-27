//
// Created by andreas on 27.01.24.
//

#ifndef KNUTH_MORRIS_PRATT_ALGO_CPP
#define KNUTH_MORRIS_PRATT_ALGO_CPP
#include <vector>
#include <string>

// Longest proper prefix which is also a suffix
std::vector<int> compute_LPS_array(const std::string &pattern)
{
	int length_LPS{};
	int index = 1;
	std::vector<int> result(pattern.size(), 0);

	while (index < pattern.size()) {
		if (pattern[index] == pattern[length_LPS]) {
			length_LPS++;
			result[index] = length_LPS;
			index++;
		}
		else {
			if (length_LPS != 0) {
				length_LPS = result[length_LPS - 1];
			}
			else {
				result[index] = 0;
				index++;
			}
		}
	}
	return result;
}

// Knuth-Morris-Pratt algorithm
std::vector<int> find_start_indices_of_pattern(const std::string &text, const std::string &pattern)
{
	std::vector<int> result;
	auto lps_array = compute_LPS_array(pattern);
	int pattern_index{};
	int text_index{};
	while (text_index < text.size()) {
		if (text[text_index] == pattern[pattern_index]) {
			text_index++;
			pattern_index++;
		}
		if (pattern_index == pattern.size()) {
			result.push_back(text_index - pattern_index);
			pattern_index = lps_array[pattern_index - 1];
		}
		else if (text_index < text.size() && pattern[pattern_index] != text[text_index]) {
			if (pattern_index != 0)
				pattern_index = lps_array[pattern_index - 1];
			else
				text_index++;
		}
	}
	return result;
}


#endif //KNUTH_MORRIS_PRATT_ALGO_CPP
