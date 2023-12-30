#include <iostream>
#include <fstream>
#include "split.h"
#include <unordered_set>
#include <numeric>

void read_cards(const std::string& fileName, int size) {
	std::ifstream file(fileName);
	std::vector<long> all_cards(size+1, 1);
	all_cards[0] =0;
	std::string line;
	int total{};
	int card_index{0};
	while (getline(file, line)) {
		card_index++;
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
		int matches{0};
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
				matches++;
			}
		}
		for(int i{card_index+1}; i <= card_index+matches ; i++)
		{
			if(i <= size)
				all_cards[i] += all_cards[card_index];
		}
	}
	std::cout << std::accumulate(all_cards.begin(), all_cards.end(), 0) << std::endl;
}

int main()
{
	read_cards("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/4th/input.txt", 199);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
