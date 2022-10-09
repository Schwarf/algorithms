#include <iostream>
#include "sum_longest_subarray_with_unique_elements.h"
#include "minimal_operations_to_get_zero.h"
#include "longest_common_substring.h"
#include "count_words_that_are_subsequences_in_given_string.h"
#include "three_sum_closest.h"

int main()
{
	std::vector<int> test1{4, 2, 4, 5, 6};
	std::vector<int> test2{5, 2, 1, 2, 5, 2, 1, 2, 5};
	std::vector<int> test3{5, 5, 5, 5};
	std::vector<int> test4{2, 3, 4, 5, 6, 7, 8, 4, 15};
	std::vector<int> test5{4, 1, 4, 2, 4, 3, 4, 5, 6, 4, 4, 7, 8};
	int result1 = 17, result2 = 8, result3 = 5, result4 = 45, result5 = 19;
	std::cout << "Sum longest subarray" << std::endl;

	std::cout << sum_longest_subarray_with_unique_elements(test1) - result1 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test2) - result2 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test3) - result3 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test4) - result4 << std::endl;
	std::cout << sum_longest_subarray_with_unique_elements(test5) - result5 << std::endl;
	// minimal operations
	test1 = {1, 1, 4, 2, 3};
	int target1 = 5;
	result1 = 2;
	test2 = {5, 6, 7, 8, 9};
	int target2 = 4;
	result2 = -1;
	test3 = {3, 2, 20, 1, 1, 3};
	int target3 = 10;
	result3 = 5;
	std::cout << "Minimal operations" << std::endl;
	std::cout << minimal_operations_to_get_zero(test1, target1) - result1 << std::endl;
	std::cout << minimal_operations_to_get_zero(test2, target2) - result2 << std::endl;
	std::cout << minimal_operations_to_get_zero(test3, target3) - result3 << std::endl;

	std::cout << "Longest common substring" << std::endl;
	std::string s1{"Hallo"};
	std::string s2{"Hallo"};

	std::cout << longest_common_substring(s1, s2) << std::endl;
	s1 = "HalloaIOPP";
	s2 = "asbnaHalloa";

	std::cout << longest_common_substring(s1, s2) << std::endl;
	s1 = "1";
	s2 = "2";

	std::cout << longest_common_substring(s1, s2) << std::endl;
	s1 = "";
	s2 = "";

	std::cout << longest_common_substring(s1, s2) << std::endl;


	s1 = "abcdef";
	auto words1 = std::vector<std::string>{"a", "bb", "acd", "ace", "acf"};
	s2 = "dsahjpjauf";
	auto words2 = std::vector<std::string>{"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax", "jau", "hjau", "pjau"};
	std::cout << "#1 = " << count_words_that_are_subsequences_in_given_string(s1, words1) << std::endl;
	std::cout << "#2 = " << count_words_that_are_subsequences_in_given_string(s2, words2) << std::endl;

	auto three_sum_closest_input1 = std::vector<int>{-1, 2, 1, -4};
	auto target_value1{1};
	auto three_sum_closest_input2 = std::vector<int>{1, 2, 3, 4, -10, 6, 7, 8};
	auto target_value2{3};
	std::cout << (three_sum_closest(three_sum_closest_input1, target_value1)==2) << std::endl;
	std::cout << (three_sum_closest(three_sum_closest_input2, target_value2)==3) << std::endl;
}
