//
// Created by andreas on 09.01.24.
//

#ifndef UNIQUE_BINARY_SEARCH_TREES_H
#define UNIQUE_BINARY_SEARCH_TREES_H
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes
// of unique values from 1 to n.
// For n=1,3 the numbers are 1 and 5

int number_of_BST_recursive(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int count{};
	for (int i{1}; i <= n; ++i) {
// The key observation is for a binary search: If yuo pick a number i with 1 <= i <= n as root-value then the left tree
// has i-1 values (1.. i-1) and the right tree has n-i values (i+1..n). Now since each value between 1..n can be the
// root value we multiply the number of left-values and right-values for each i and add them up.
		count += number_of_BST_recursive(i - 1) * number_of_BST_recursive(n - i);
	}
	return count;
}

#endif //UNIQUE_BINARY_SEARCH_TREES_H
