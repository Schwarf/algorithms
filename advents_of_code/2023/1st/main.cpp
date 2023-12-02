//
// Created by acn2abt on 01.12.23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int count{};
std::unordered_map<std::string, int> list{{"one" , 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six",6},
            {"seven", 7}, {"eight", 8}, {"nine", 9}};

void counter(const std::string & line)
{
    /// find left
    constexpr int max{100000};
    constexpr int min{0};
    int min_left_position{max};
    int string_number_left{};
    for(const auto & [number, i]: list)
    {
        int position = static_cast<int>(line.find(number));
        if(position != std::string::npos && position < min_left_position)
        {
            min_left_position = position;
            string_number_left = i;
            std::cout << " left " << min_left_position << ", " << i <<  std::endl;
        }

    }

    int max_right_position{min};
    int string_number_right{};
    for(const auto & [number, i]: list)
    {
        int position = static_cast<int>(line.rfind(number));
        if(position != std::string::npos && position > max_right_position)
        {
            max_right_position = position;
            string_number_right = i;
            std::cout << " right  " << max_right_position << ", " << position << ", " << i <<  std::endl;
        }
    }


    int left{};
    int right = line.length()-1;
    int left_val{};
    int right_val{};
    bool left_found{false};
    bool right_found{false};
    int left_pos{max};
    int right_pos{min};
    while(left < line.length())
    {
        //std::cout << "G  " << line[left] <<", " << line[right] << std::endl;
        if(!left_found && std::isdigit(line[left]))
        {
            left_found =true;
            left_val = line[left] - '0';
            left_pos = left;
        }
        if(!right_found && std::isdigit(line[right]))
        {
            right_found =true;
            right_val = line[right] - '0';
            right_pos = right;
        }
        left++;
        right--;
    }

    int val{};
    left_val = min_left_position < left_pos ? string_number_left : left_val;
    right_val = max_right_position > right_pos ? string_number_right : right_val;

    val = left_val*10 + right_val;
    std::cout << val << ", " << left_val << ", " << right_val << std::endl;
    count += val;

}

int main() {
    std::ifstream file("/media/linux_data/projects/cpp/algorithms/advents_of_code/2023/1st/input.txt	");
    if (!file)
    {
        std::cerr << "Error oipening file" << std::endl;
        return 1;
    }
    std::string line{};
    while(std::getline(file, line))
    {
        counter(line);
    }
    std::cout << count << std::endl;

}
