#include <iostream>
#include "queens_problem.h"
#include "search_word_in_character_grid.h"

int main() {
/*
	auto r = solve_queen_problem(6);
	for(const auto & element : r)
	{
		for(const auto & e : element)
			std::cout << e << std::endl;
		std::cout << std::endl;
	}
*/
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'},
                                         {'S', 'F', 'C', 'S'}};
    std::string word{"ABCCED"};

    std::cout << exist(board, word) << std::endl;


    return 0;
}
