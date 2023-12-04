#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

std::vector<std::vector<bool>> get_symbols(const std::vector<std::string> & content)
{
	std::vector<std::vector<bool>> symbols(content.size(), std::vector<bool>(content[0].size(), false));
	for(int j{}; j < content.size(); ++j)
	{
		const auto & line = content[j];
		for(int i{}; i < line.length(); ++i)
		{
			if(content[j][i] != '.' && !std::isdigit(content[j][i])) {
				for (int x = -1; x < 2; ++x) {
					for (int y = -1; y < 2; ++y) {
						auto new_y = j + y;
						auto new_x = i + x;
						if (new_y >= 0 && new_x >= 0 && new_y < content.size() && new_x < line.length()) {
							symbols[new_y][new_x] = true;
						}
					}
				}
			}
		}
	}
	return symbols;
}

std::vector<std::vector<std::pair<int, int>>> get_gears(const std::vector<std::string> & content)
{
	std::vector<std::vector<std::pair<int, int>>> gears(content.size(), std::vector<std::pair<int, int>>(content[0].size(), {-1, -1}));
	for(int j{}; j < content.size(); ++j)
	{
		const auto & line = content[j];
		for(int i{}; i < line.length(); ++i)
		{
			if(content[j][i] == '*' ) {
				for (int x = -1; x < 2; ++x) {
					for (int y = -1; y < 2; ++y) {
						auto new_y = j + y;
						auto new_x = i + x;
						if (new_y >= 0 && new_x >= 0 && new_y < content.size() && new_x < line.length()) {
							gears[new_y][new_x] = {j, i};
						}
					}
				}
			}
		}
	}
	return gears;
}

void compute(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Unable to open file\n";
	}

	std::string line;
	std::vector<std::string> content;
	while (getline(file, line))
	{
		content.push_back(line);
	}
	auto symbols = get_symbols(content);
	int total{};
	for(int j{}; j < content.size(); ++j) {
		const auto &row = content[j];
		for (int i{}; i < row.length(); ++i) {

			if (std::isdigit(content[j][i])) {
				bool has_symbol{};
				int number{};
				while(std::isdigit(content[j][i]))
				{
					number *= 10;
					has_symbol |= symbols[j][i];
					number += content[j][i]-'0';
					i++;
				}
				if(has_symbol)
					total += number;
			}
			}
		}
	std::cout << total << std::endl;
}

struct PairHash
{
	size_t operator()(const std::pair<int, int> & input) const
	{
		return std::hash<int>{}(input.first) ^ std::hash<int>{}(input.second);
	}
};


void compute_gears(const std::string& fileName)
{
	std::unordered_map<std::pair<int, int>, int, PairHash> hash_map;
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Unable to open file\n";
	}
	std::string line;
	std::vector<std::string> content;
	while (getline(file, line))
	{
		content.push_back(line);
	}
	auto gears = get_gears(content);
	int total{};
	for(int j{}; j < content.size(); ++j) {
		const auto &row = content[j];
		for (int i{}; i < row.length(); ++i) {

			if (std::isdigit(content[j][i])) {
				int number{};
				std::pair<int, int> gear;
				while(std::isdigit(content[j][i]))
				{
					if(gears[j][i].first != -1) {
						gear = gears[j][i];
						std::cout << gear.first << ", " << gear.second << std::endl;
					}
					number *= 10;
					number += content[j][i]-'0';
					i++;
				}
				if(hash_map.find(gear) != hash_map.end())
				{
					total+= number*hash_map[gear];
				}
				else
					hash_map[gear] = number;
			}
		}
	}
	std::cout << total << std::endl;
}


int main()
{
	compute_gears("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/3rd/test.txt");
	return 0;
}
