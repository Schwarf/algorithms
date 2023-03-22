//
// Created by andreas on 22.03.23.
//

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <cstddef>
#include "used_concepts.h"
template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void bubble_sort(Container &container)
{
	if(!container.size())
		return;
	size_t size = container.size() - 1;
	bool have_elements_been_swapped{};
	do {
		have_elements_been_swapped = false;
		for (size_t index = 0; index < size; ++index) {
			if (container[index + 1] < container[index]) {
				std::swap(container[index + 1], container[index]);
				have_elements_been_swapped = true;
			}
		}
	}
	while (have_elements_been_swapped);

}

#endif //BUBBLE_SORT_H
