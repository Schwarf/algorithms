//
// Created by andreas on 13.01.22.
//
#include "swap.h"
void swap(std::vector<int64_t> & array, size_t index1, size_t index2){
	auto help = array[index1];
	array[index1] = array[index2];
	array[index2] = help;
}

