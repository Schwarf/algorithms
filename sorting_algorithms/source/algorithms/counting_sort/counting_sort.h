//
// Created by andreas on 14.02.22.
//

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"


class CountingSort: public ISort
{
public:
	CountingSort(int64_t lower_limit, int64_t upper_limit);
	void sort(std::vector<int64_t> &array) final;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
	~CountingSort() override = default;

private:
	int64_t lower_limit_{};
	int64_t upper_limit_{};
	std::vector<int64_t> element_counter_;
	std::vector<int64_t> result_;
};


#endif //COUNTING_SORT_H
