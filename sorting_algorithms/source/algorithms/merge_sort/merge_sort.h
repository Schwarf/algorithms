//
// Created by andreas on 14.01.22.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class MergeSort final : public ISort
{
public:
	void enable_non_recursive_version(bool enable);
	void sort(std::vector<int64_t> &array) final;

	~MergeSort() final = default;
private:
	bool non_recursive_version_is_enabled_{};
	void static merge_(std::vector<int64_t> &array, std::vector<int64_t> &help, size_t start, size_t middle, size_t end);
	void sort_recursive_(std::vector<int64_t> &array, std::vector<int64_t> &help, size_t start, size_t end);
	void sort_non_recursive_(std::vector<int64_t> &array) ;
};


#endif //MERGE_SORT_H
