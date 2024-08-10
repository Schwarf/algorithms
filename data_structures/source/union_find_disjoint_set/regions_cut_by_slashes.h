//
// Created by andreas on 10.08.24.
//

#ifndef DATA_STRUCTURES_REGIONS_CUT_BY_SLASHES_H
#define DATA_STRUCTURES_REGIONS_CUT_BY_SLASHES_H
// Imagine a n x n grid and an input-vector of strings where each vector-string-index pair represent one
// cell in the n x n grid. Each cell may contain one of three characters '\\', '/' or ''.
// Now the slashes '\\' (escaped) and '/' represent lines in the grid that might divide the original grid into
// different regions. For example in 1 x 1 grid both '\\' and '/' divide the grid into 2 regions.
// Given the input how many regions are there. Return that number.
#include <vector>
#include <string>

// We use union-find and for that we decompose each grid cell into four triangles:
// -----------
// |\0 /|\ 0/|              The triangles in the upper-left cell have indices: 0,1,2,3
// | \/1|3\/1|              The triangles in the upper-right cell have indices: 4,5,6,7
// |3/\ | /\ |              The triangles in the lower-left cell have indices: 8,9,10,11
// |/ 2\|/ 2\|              The triangles in the lower-right cell have indices: 12,13,14,15
// -----------
// |\0 /|\ 0/|              Connecting upper-triangle 8 with lower-triangle 2 and upper-triangle 12 with lower-triangle 6 yields the formula:
// | \/1|3\/1|              union_set(upper-triangle-index (=grid_index + 0), upper-triangle-index - 4*n + 2 (=grid_index + 0 -4*n +2)) with n = 2, since 2 x 2 grid.
// |3/\ | /\ |
// |/ 2\|/ 3\|              Connecting left-triangle 7  with right-triangle 1 and left-triangle 15 with right-triangle 9 yields the formula:
// -----------              union_set(left-triangle-index (=grid_index + 3), right-triangle-index+1(=grid_index-3))

class UnionFind {

public:
    explicit UnionFind(int size) : parents(size), rank(size) {
        // each parent points to itself
        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find_parent(int element) {
        if (parents[element] != element) {
            parents[element] = find_parent(parents[element]);  // Path compression
        }
        return parents[element];
    }

    void union_set(int element1, int element2) {
        auto root_element1 = find_parent(element1);
        auto root_element2 = find_parent(element2);
        if (root_element1 != root_element2) {
            // Union by rank
            if (rank[root_element1] > rank[root_element2]) {
                parents[root_element2] = root_element1;
            } else if (rank[root_element1] < rank[root_element2]) {
                parents[root_element1] = root_element2;
            } else {
                parents[root_element2] = root_element1;
                rank[root_element1] += 1;
            }
        }


    }

private:
    std::vector<int> parents;
    std::vector<int> rank;
};

int count_regions_by_slahes(std::vector<std::string> &grid) {
    int n = grid.size();
    int number_of_triangles = n * n * 4;
    UnionFind union_find(number_of_triangles);

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int grid_index = 4 * (r * n + c);
            char val = grid[r][c];

            if (val == ' ') {
                // Connect all four triangles if it's a blank space
                union_find.union_set(grid_index, grid_index + 1);
                union_find.union_set(grid_index + 1, grid_index + 2);
                union_find.union_set(grid_index + 2, grid_index + 3);
            } else if (val == '/') {
                // Connect top left to bottom right
                union_find.union_set(grid_index, grid_index + 3);
                union_find.union_set(grid_index + 1, grid_index + 2);
            } else if (val == '\\') {
                // Connect top right to bottom left
                union_find.union_set(grid_index, grid_index + 1);
                union_find.union_set(grid_index + 2, grid_index + 3);
            }

            // Connect with the adjacent cells
            if (r > 0) {
                union_find.union_set(grid_index,
                                     grid_index - 4 * n +
                                     2); // Connect top triangle to the bottom triangle of above cell
            }
            if (c > 0) {
                union_find.union_set(grid_index + 3,
                                     grid_index - 3); // Connect left triangle to the right triangle of the left cell
            }
        }
    }

    // Count unique parents
    int count{};
    for (int i = 0; i < number_of_triangles; ++i) {
        if (union_find.find_parent(i) == i) {
            count++;
        }
    }
    return count;
}

#endif //DATA_STRUCTURES_REGIONS_CUT_BY_SLASHES_H
