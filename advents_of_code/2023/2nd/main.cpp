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

std::vector<GameData> read_game_data(const std::string& fileName) {
	std::vector<GameData> games;
	std::ifstream file(fileName);

	std::string line;
	while (getline(file, line)) {
		std::istringstream iss(line);
		std::string temp;
		int gameId;

		// Extract game ID
		iss >> temp >> gameId;
		GameData game;
		game.id = gameId;

		// Extract colors and their counts
		while (iss >> temp) {
			std::istringstream colorStream(temp);
			int count;
			std::string color;

			if (colorStream >> count) {
				getline(colorStream, color, ',');
				color.erase(color.begin()); // remove leading space
				game.colors.push_back({color, count});
			}
		}

		games.push_back(game);
	}

	return games;
}
int main() {
	auto games = read_game_data("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/2nd/input.txt");
	std::unordered_map<std::string, int> constraints{{"red", 12}, {"green", 13}, {"blue", 14}};
	// Display the extracted data
	for (const auto& game : games) {
		std::cout << "Game " << game.id << ":\n";
		for (const auto& color_count : game.colors) {
			std::cout << color_count.color << " " << color_count.count << "\n";
		}
		std::cout << "\n";
	}

	return 0;
}
