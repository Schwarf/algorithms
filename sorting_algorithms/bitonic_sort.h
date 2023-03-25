//
// Created by andreas on 25.03.23.
//

#ifndef BITONIC_SORT_H
#define BITONIC_SORT_H
#include "used_concepts.h"

template<typename Container, std::size_t Size>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type> && PowerOfTwo<Size>
void bitonic_sort(Container &container)
{
	int size = container.size();
	for (int k{2}; k <= size; k <<= 1) {
		std::cout << " k= " << k << std::endl;
		for (int j = k >> 1; j > 0; j >>= 1) {
			std::cout << j << std::endl;
			for (int i = {}; i < size; ++i) {
				auto l = i ^ j;
				if( l > i)
					if( ((i&k) == 0 && (container[i] > container[l])) || ((i&k) != 0 && (container[i] < container[l])))
						std::swap(container[i], container[l]);
			}
		}
	}
}

#endif //BITONIC_SORT_H
