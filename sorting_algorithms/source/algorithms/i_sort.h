//
// Created by andreas on 12.01.22.
//

#ifndef SORTING_INTERFACE_H
#define SORTING_INTERFACE_H
#include <vector>
#include <cstdint>
class ISort{
public:
	virtual void sort(std::vector<int64_t> & array) = 0;
	virtual ~ISort() =default;
};

#endif //SORTING_INTERFACE_H
