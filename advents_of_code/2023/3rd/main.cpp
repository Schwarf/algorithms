#include <iostream>
#include <vector>
#include <fstream>

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
							symbols[new_x][new_y] = true;
						}
					}
				}
			}
		}
	}
	return symbols;
}

void compute(const std::string& fileName)
{
	std::ifstream file(fileName);

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

int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
