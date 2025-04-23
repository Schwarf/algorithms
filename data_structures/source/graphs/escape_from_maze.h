//
// Created by andreas on 23.04.25.
//

#ifndef ESCAPE_FROM_MAZE_H
#define ESCAPE_FROM_MAZE_H
// There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
// We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of
// blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
// Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares.
// We are also not allowed to walk outside of the grid.
// Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.
#include <vector>
#include <unordered_set>
#include <queue>


// Custom hash for a pair of coordinates
struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const noexcept {
        // Combine the two 32-bit values into one 64-bit hash
        return (static_cast<size_t>(p.first) << 20) ^ p.second;
    }
};

bool bfs(const std::vector<int>& start,
         const std::vector<int>& finish,
         const std::unordered_set<std::pair<int,int>, PairHash>& blockedSet,
         int maxSteps) {
    const std::vector<std::pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    constexpr int grid_size{1000000};
    std::queue<std::pair<int,int>> queue;
    std::unordered_set<std::pair<int,int>, PairHash> visited;
    queue.emplace(start[0], start[1]);
    visited.emplace(start[0], start[1]);

    int steps = 0;
    while (!queue.empty() && steps <= maxSteps) {
        auto [row, col] = queue.front();
        queue.pop();

        if (row == finish[0] && col == finish[1]) {
            // We found the target
            return true;
        }

        for (auto & [x, y] : directions) {
            int new_row = row + x;
            int new_col = col + y;
            auto new_pair = std::make_pair(new_row, new_col);
            if (new_row >= 0 && new_row < grid_size && new_col >= 0 && new_col < grid_size
                && !blockedSet.count(new_pair) && !visited.count(new_pair)) {
                visited.insert(new_pair);
                queue.push(new_pair);
                ++steps;
                }
        }
    }
    // If we've explored more than maxSteps without finding target, we're not enclosed
    return steps > maxSteps;
}

bool is_escape_possible(std::vector<std::vector<int>>& blocked,
                      std::vector<int>& source,
                      std::vector<int>& target) {
    // Insert blocked cells into a hash set for O(1) lookup
    std::unordered_set<std::pair<int,int>, PairHash> blockedSet;
    for (auto& b : blocked) {
        blockedSet.emplace(b[0], b[1]);
    }

    // Maximum number of steps to explore before deciding we're not enclosed
    int maxSteps = blocked.size() * (blocked.size() - 1) / 2;

    // We need to ensure neither source nor target is enclosed
    return bfs(source, target, blockedSet, maxSteps)
        && bfs(target, source, blockedSet, maxSteps);
}




// TODO
bool escape_from_maze_custom_lambdas(const std::vector<std::vector<int>>& blocked, std::vector<int> & source, std::vector<int> & target)
{
  auto hash_function =[](const std::pair<int, int> & coordinates){
        // we shift 20 bits since our grid bounds are 10^6 ~= 2^20
      return static_cast<size_t>((coordinates.first) << 20) ^ static_cast<int>(coordinates.second);
  };
  auto equal_function = [](const std::pair<int, int> & coordinates1, const std::pair<int, int> & coordinates2){
    return coordinates1 == coordinates2;
  };

  std::unordered_set<std::pair<int, int>, decltype(hash_function), decltype(equal_function)> blocked_set(0, hash_function, equal_function);
  for(const auto & block: blocked)
  {
      blocked_set.emplace(block[0], block[1]);
  }
  // Maximum number of steps to explore before deciding we're not enclosed
  // This is based on the fact that we have (N-1)*N blocks to form a triangle closure
  // Therefor we need to macke sure that neither sourde nor target are enclosed i such a triangle
  int max_steps = blocked.size() *(blocked.size() - 1)/2 ;

  return false;
}
#endif //ESCAPE_FROM_MAZE_H
