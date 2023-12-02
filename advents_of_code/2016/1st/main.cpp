//
// Created by acn2abt on 01.12.23.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
std::vector<std::string> read_comma_separated_values(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> values;

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return values; // Return an empty vector if file can't be opened
    }

    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            // Trim leading and trailing spaces if necessary
            size_t start = value.find_first_not_of(" ");
            size_t end = value.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                value = value.substr(start, end - start + 1);
            }

            values.push_back(value);
        }
    }

    file.close();
    return values;
}

struct hasher
{
    std::size_t operator()(const std::pair<int, int> & pos) const
    {
        return std::hash<int>()(pos.first) ^ std::hash<int>()(pos.second);
    }
};

std::pair<int, int> check_locations_x(int start, int end, int y, std::unordered_set<std::pair<int, int>, hasher> & path, bool & found)
{
    for(int  i =start+1; i<= end; ++i)
    {
        if(path.find({i, y}) != path.end())
        {
            found =true;
            return {i, y};
        }
        else
            path.insert({i, y});
    }
}

std::pair<int, int> check_locations_y(int start, int end, int x, std::unordered_set<std::pair<int, int>, hasher> & path, bool & found)
{
    for(int  i =start; i<= end; ++i)
    {
        if(path.find({x, i}) != path.end())
        {
            found =true;
            return {x, i};
        }
        else
            path.insert({x, i});
    }
}


int main(){
    constexpr int axe_size{1000};
    std::vector<std::vector<int>> grid(2*axe_size +1, std::vector<int>(2*axe_size+1));
    constexpr int x_center{axe_size};
    constexpr int y_center{axe_size};
    std::unordered_map<char, char> turning_left{ {'U', 'L'}, {'L', 'D'},  {'D', 'R'},  {'R', 'U'}};
    std::unordered_map<char, char> turning_right{ {'U', 'R'}, {'R', 'D'},  {'D', 'L'},  {'L', 'U'}};
    std::string filename {"/media/linux_data/projects/cpp/algorithms/advents_of_code/2016/1st/test.txt"};
    auto path = read_comma_separated_values(filename);
    auto position_x = x_center;
    auto position_y = y_center;
    char facing = 'U';
    std::unordered_set<std::pair<int, int>, hasher> locations{{x_center, y_center}};
    bool found{};
    for(const auto & turn : path)
    {
        if(turn[0] == 'L')
            facing = turning_left[facing];
        else
            facing = turning_right[facing];
        int number{turn[1]-'0'};
        for(int i{2}; i < turn.length(); ++i)
        {
            number *= 10;
            number += turn[i]-'0';
        }

        if(facing == 'U') {
            auto res = check_locations_x(position_x, position_x+number, position_y, locations, found);
            if(found)
                return std::abs(x_center-res.first) + std::abs(y_center-res.second);
            position_x += number;
        }
        if(facing == 'D') {
            auto res = check_locations_x(position_x-number, position_x, position_y, locations, found);
            if (found)
                return std::abs(x_center - res.first) + std::abs(y_center - res.second);

            position_x -= number;
        }
        if(facing == 'L')
            position_y -= number;
        if(facing == 'R')
            position_y += number;
        if(locations.find({position_x, position_y}) != locations.end())
        {
            std::cout << std::abs(x_center-position_x) + std::abs(y_center-position_y) << std::endl;
            break;
        }
        else
            locations.insert({position_x, position_y});
    }
    std::cout << position_x << ", " << position_y << std::endl;
    std::cout << std::abs(x_center-position_x) + std::abs(y_center-position_y) << std::endl;

    return 0;
}
