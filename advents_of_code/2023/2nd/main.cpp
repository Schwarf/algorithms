#include <iostream>


#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

struct ColorCount {
	std::string color;
	int count;
};

struct GameData {
	int id;
	std::vector<ColorCount> colors;
};

std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

std::vector<GameData> read_game_data(const std::string& fileName) {
	std::vector<GameData> games;
	std::ifstream file(fileName);

	std::string line;
	while (getline(file, line)) {
		auto line_parts = split(line, ':');


		// Extract game ID
		GameData game;
		game.id = std::stoi(line_parts[0].substr(5));

		// Extract colors and their counts
		auto color_sets = split(line_parts[1], ';');
		for(const auto & color_set : color_sets)
		{
			auto colors = split(color_set, ',');
			for(const auto & color : colors)
			{
				std::istringstream iss(color);
				int count;
				std::string name;
				iss >> count >> name;
				game.colors.push_back({name, count});
			}
		}
		games.push_back(game);
	}
	return games;
}
int main() {
	auto games = read_game_data("/media/linux_data/projects/cpp/algorithms/advqents_of_code/2023/2nd/input.txt");

	// Display the extracted data
	int total_count{};
	for (const auto& game : games) {
		std::cout << "Game " << game.id << ":\n";
		bool is_valid{true};
		std::unordered_map<std::string, int> constraints{{"red", 0}, {"green", 0}, {"blue", 0}};
		for (const auto& color_count : game.colors) {
			//std::cout << color_count.color << " " << color_count.count << "\n";
			if(constraints[color_count.color] < color_count.count)
			{
				constraints[color_count.color] = color_count.count;
			}
		}
		int result{1};
		for(const auto & [color, count] : constraints)
		{
			result *=count;
		}
		total_count +=result;
	}
	std::cout << total_count << std::endl;

	return 0;
}

int main1() {
	auto games = read_game_data("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/2nd/input.txt");
	std::unordered_map<std::string, int> constraints{{"red", 12}, {"green", 13}, {"blue", 14}};
	// Display the extracted data
	int total_count{};
	for (const auto& game : games) {
		std::cout << "Game " << game.id << ":\n";
		bool is_valid{true};
		for (const auto& color_count : game.colors) {
			//std::cout << color_count.color << " " << color_count.count << "\n";
			if(constraints[color_count.color] < color_count.count)
			{
				is_valid = false;
				break;
			}
		}
		if(is_valid)
			total_count+=game.id;
	}
	std::cout << total_count << std::endl;

	return 0;
}
