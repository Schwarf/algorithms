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
	for (int k{2}; k <= Size; k <<= 1) {
		for (int j = k >> 1; j > 0; j >>= 1) {
			for (int i = {}; i < Size; ++i) {
				auto l = i ^ j;
				if (l > i)
					if (((i & k) == 0 && (container[i] > container[l]))
						|| ((i & k) != 0 && (container[i] < container[l])))
						std::swap(container[i], container[l]);
			}
		}
	}
}

#endif //BITONIC_SORT_H
