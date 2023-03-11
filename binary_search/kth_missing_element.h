//
// Created by andreas on 07.03.23.
//

#ifndef KTH_MISSING_ELEMENT_H
#define KTH_MISSING_ELEMENT_H
#include "used_concepts.h"
// Given array/vector of positive elements find the kth missing element

template<typename Container>
requires IndexedContainerWithUnsignedIntegralElements<Container> && NoPointerElement<typename Container::value_type>
int find_kth_missing_positive_element(const Container & container, int k)
{
	int n = container.size();
	int left {};
	int right = n-1;
	while(left <= right)
	{
		int mid = (left + right)/2;
		if(container[mid] - (mid+1) < k)
			left = mid +1;
		else
			right = mid -1;
	}
	return left + k;
}




#endif //KTH_MISSING_ELEMENT_H
