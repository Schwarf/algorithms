#include <iostream>
#include <fstream>
#include "split.h"
#include <unordered_set>

void read_cards(const std::string& fileName) {
	std::ifstream file(fileName);

	std::string line;
	int total{};
	while (getline(file, line)) {
		auto line_parts = split(line, ':');
		auto cards = split(line_parts[1], '|');
		auto winning_cards = cards[0];
		auto my_cards = cards[1];

		// Extract colors and their counts
		auto winning_numbers = split(winning_cards, ' ');
		auto my_numbers = split(my_cards, ' ');
		std::unordered_set<int> help;
		for (const auto &number: winning_numbers) {
			int num{};
			for (const auto &c: number) {
				if (!std::isdigit(c))
					break;
				num *= 10;
				num += c - '0';
			}
			help.insert(num);
		}
		int points{};
		for (const auto &number: my_numbers) {
			int num{};
			for (const auto &c: number) {
				if (!std::isdigit(c))
					break;
				num *=10;
				num += c - '0';
			}
			if(help.find(num) != help.end() && num != 0)
			{
				if(points == 0)
					points++;
				else
					points <<= 1;
			}

		}
		total += points;
	}
	std::cout << total << std::endl;
}

int main()
{
	read_cards("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/4th/test.txt");
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
