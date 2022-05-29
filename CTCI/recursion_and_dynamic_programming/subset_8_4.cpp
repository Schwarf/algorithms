//
// Created by andreas on 29.05.22.
//

#include <iostream>
#include <vector>



void generate_sub_sets(std::vector<std::vector<int>> & sub_sets, int n)
{
	for(int i = sub_sets.size() -1 ; i > -1 ; --i)
	{
		auto new_set = sub_sets[i];
		new_set.push_back(n);
		sub_sets.push_back(new_set);
	}

}


std::vector<std::vector<int>> all_subsets(std::vector<int> set)
{
	auto result = std::vector<std::vector<int>> (1, std::vector<int>());

	for(int i = 0; i < set.size(); ++i)
	{
		generate_sub_sets(result, set[i]);
	}

	return result;

}


int main()
{
	std::vector<int> test{1,2,3, 4, 5, 6};
	auto result = all_subsets(test);
	for(const auto & element: result)
	{
		std::cout << "{ ";
		for(const auto & sub: element)
		{
			std::cout << sub << " ";
		}
		std::cout << "}" << std::endl;
	}
	std::cout << result.size() << std::endl;

}