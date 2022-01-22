//
// Created by andreas on 22.01.22.
//

#ifndef QUICK_SELECT_H
#define QUICK_SELECT_H
#include <vector>
#include <memory>
#include <cstdint>

class QuickSelect
{
public:
	static int64_t select(std::vector<int64_t> &array, size_t kth_element);
private:
	static size_t partition_(std::vector<int64_t> &array, size_t start, size_t end);
};


#endif //QUICK_SELECT_H
