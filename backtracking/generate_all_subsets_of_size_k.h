//
// Created by andreas on 01.08.23.
//

#ifndef GENERATE_ALL_SUBSETS_OF_SIZE_K_H
#define GENERATE_ALL_SUBSETS_OF_SIZE_K_H
#include <vector>
#include <concepts>

template<typename T>
requires std::is_unsigned_v<T>
void dfs(T n, T k, T index, std::vector<T>& current_combination, std::vector<std::vector<T>>& result)
{
	if(current_combination.size() == k)
	{
		result.push_back(current_combination);
		return;
	}
	for(T i{index}; i<=n; ++i)
	{
		current_combination.push_back(i);
		dfs(n, k, T{i+1}, current_combination, result);
		current_combination.pop_back();
	}

}
template<typename T>
requires std::is_unsigned_v<T>
std::vector<std::vector<T>> generate_all_subsets_of_size_k(T n , T k)
{
	std::vector<std::vector<T>> result;
	std::vector<T> combined_result;
	dfs(n, k, T{1}, combined_result, result);
	return result;
}
#endif //GENERATE_ALL_SUBSETS_OF_SIZE_K_H
