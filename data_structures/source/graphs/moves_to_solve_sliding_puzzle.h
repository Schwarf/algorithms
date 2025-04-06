//
// Created by andreas on 06.04.25.
//

#ifndef SLIDING_PUZZLE_H
#define SLIDING_PUZZLE_H
// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0.
// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
// Given the puzzle board board, return the least number of moves required so that the state of the board is solved.
// If it is impossible for the state of the board to be solved, return -1.
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

int moves_to_solve_sliding_puzzle(std::vector<std::vector<int>> & board)
{
    // The tirck is to represent the 6-tile 2D board as a linear string by just appending the second row
    // the first row.

    // These directions shows the possible movement on the linearized 1D board with position [0..5]
    std::vector<std::vector<int>> directions{{1,3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {4, 2}};
    std::string target = "123450";

    // construct start-layout
    std::string start{};
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            start += std::to_string(board[i][j]);
        }
    }
    std::unordered_set<std::string> visited;
    std::queue<std::string> queue;
    queue.push(start);
    visited.insert(start);

    int moves{};
    while(!queue.empty())
    {
        int size = queue.size();
        for(int i{}; i < size; ++i)
        {
            auto current = queue.front();
            queue.pop();
            if(current == target)
                return moves;
            // we can only move/swap the empty tile with an another tile
            int zero_position = current.find('0');
            for(const auto new_position : directions[zero_position])
            {
                auto next = current;
                std::swap(next[zero_position], next[new_position]);
                if(visited.count(next))
                    continue;
                visited.insert(next);
                queue.push(next);
            }
        }
        moves++;
    }
    return -1;
}
#endif //SLIDING_PUZZLE_H
