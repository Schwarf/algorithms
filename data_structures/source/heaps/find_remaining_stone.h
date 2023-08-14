//
// Created by andreas on 24.04.23.
//

#ifndef FIND_REMAINING_STONE_H
#define FIND_REMAINING_STONE_H
#include <vector>
#include "binary_heap.h"
// You are given an array of integers stones where stones[i] is the weight of the ith stone.
// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together.
// Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.
// Return the weight of the last remaining stone. If there are no stones left, return 0.

template<typename T, size_t capacity>
T find_remaining_stone(const std::vector<T> &stones)
{
	auto heap = StackHeap<int, capacity>();
	for (const auto &stone: stones)
		heap.insert(stone);
	//binary_heap <int> p (stones.begin(), stones.end());
	while (heap.size() > 1) {
		auto stone1 = heap.pop();
		auto stone2 = heap.pop();
		if (stone1 != stone2)
			heap.insert(stone1 - stone2);
	}
	return heap.is_empty() ? 0 : heap.pop();
}

#endif //FIND_REMAINING_STONE_H
