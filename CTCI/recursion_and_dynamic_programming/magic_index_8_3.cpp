//
// Created by andreas on 28.05.22.
//
#include <vector>
#include <iostream>

bool has_magic_index(std::vector<int> &A)
{
	if (A.empty())
		return false;
	int start = 0;
	int end = A.size() - 1;
	int mid{};
	while (end > start) {
		mid = start + (end - start) / 2;

		if (A[mid] == mid) {
			std::cout << mid << std::endl;
			return true;
		}

		else if (A[mid] > mid)
			end = mid;
		else if (A[mid] < mid)
			start = mid + 1;
	}
	return false;

}

int main()
{
	auto v1 = std::vector<int>{-1, 0, 2, 4, 6, 110, 1200};
	auto v2 = std::vector<int>{-2, -1, 1, 2, 3, 5, 8};
	auto v3 = std::vector<int>{-3, -2, -1, 0, 10, 20, 30};
	std::cout << has_magic_index(v1) << std::endl;
	std::cout << has_magic_index(v2) << std::endl;
	std::cout << has_magic_index(v3) << std::endl;
	return 0;

}