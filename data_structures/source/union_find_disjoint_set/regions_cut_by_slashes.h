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
// |\1 /|\  /|
// | \/2| \/ |
// |4/\ | /\ |
// |/ 3\|/  \|
// -----------
// |\1 /|\  /|
// | \/2| \/ |
// |4/\ | /\ |
// |/ 3\|/  \|
// -----------

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

#endif //DATA_STRUCTURES_REGIONS_CUT_BY_SLASHES_H
