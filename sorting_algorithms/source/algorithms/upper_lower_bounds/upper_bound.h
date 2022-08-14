//
// Created by andreas on 14.08.22.
//

#ifndef UPPER_BOUND_H
#define UPPER_BOUND_H
#include <vector>
#include <iostream>
template<typename ForwardIterator, typename T>
ForwardIterator my_upper_bound(ForwardIterator first, ForwardIterator last, const T &value)
{
	ForwardIterator it;
	auto begin = first;
	//typename std::iterator_traits<ForwardIterator>::differenc_type count, step;
	auto count = std::distance(first, last);
	auto print = [begin](ForwardIterator it)
	{ std::cout << it - begin << std::endl; };
	while (count > 0) {
		it = first;
		auto step = count / 2;
		std::advance(it, step);
		if (value >= *it) {
			first = ++it;
			count -= step + 1;
		}
		else
			count = step;
		print(first);
		print(it);
		std::cout << std::endl;
	}
	return first;
}

#endif //UPPER_BOUND_H
