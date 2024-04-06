//
// Created by andreas on 03.04.24.
//

#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H
#include <concepts>
#include <vector>
#include <stdexcept>

template<typename T>
concept Orderable = requires(T a, T b)
{
	{ a < b } -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

template<typename T, class Container = std::vector<T>, class Comparator = std::less<T>> requires Orderable<T>
class min_max_heap
{


private:
	Container container_;
	Comparator comparator_;

	// In min-max heaps, the required ordering must be established between an element, its children, and its grandchildren.
	void trickle_down(int index)
	{
		const auto level = log2int(1 + index); // We add 1 since we can not deal with the zero (min) level in the log
		if (level & 1) {
			trickle_down_<!is_max_level>(index);
		}
		else {
			trickle_down_<is_max_level>(index);
		}
	}

	int parent(int index)
	{
		return (index - 1) / 2;
	}

	int left_child(int index)
	{
		return 2 * index + 1;
	}

	int right_child(int index)
	{
		return 2 * index + 2;
	}

	template<bool is_max_level>
	void trickle_down_(int index)
	{
		if (index >= heap_.size()) {
			throw std::invalid_argument("Index value " + std::to_string(index) + "does not exist!");
		}
		auto leftChild = left_child(index);
		auto rightChild = right_child(index);
		// Determine the child to compare
		auto childToCompare = index;
		if (leftChild < heap_.size() && (is_max_level ^ comparator_(container_[leftChild], container_[index])))
			childToCompare = leftChild;
		if (rightChild < heap_.size() && (is_max_level ^ comparator_(container_[rightChild], container_[index])))
			childToCompare = rightChild;
		// Determine the grandchild to compare. All grandchildren lie next to each other in memory.
		auto leftLeftGrandChild = left_child(leftChild);
		bool grandChildWasChosen{false};
		for (int i{}; i < 4 && leftLeftGrandChild + i < heap_.size(); ++i)
			if (compare_(heap_[leftLeftGrandChild + i], heap_[childToCompare]) ^ is_max_level) {
				childToCompare = leftLeftGrandChild + i;
				grandChildWasChosen = true;
			}
		// Are we already at the right position?
		if (index == childToCompare)
			return;
		std::swap(heap_[childToCompare], heap_[index]);

		if (grandChildWasChosen) {
			if (comparator_(heap_[parent(childToCompare)], heap_[childToCompare]) ^ is_max_level)
				std::swap(heap_[parent(childToCompare)], heap_[childToCompare]);
			trickle_down_<is_max_level>(childToCompare);
		}
	}

	// Compute the level for index i in the min-max-heap by using floor(log2int(i))
	int log2int(int n)
	{
		if (n == 0)
			throw std::domain_error("log2 of 0 is undefined!");
		int result{0};
		while (n > 1) {
			n >>= 1;
			result++;
		}
		return result;
	}
	static constexpr bool is_max_level{true};
	std::vector<T> heap_;
};

#endif //MIN_MAX_HEAP_H
