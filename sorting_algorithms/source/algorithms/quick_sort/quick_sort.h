//
// Created by andreas on 17.01.22.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"
class QuickSort final: public ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
	void set_classic_variant(bool use_classic_variant);
	~QuickSort() override = default;
private:
	static void quick_sort_(std::vector<int64_t> &array, int start, int end);
	static void modern_quick_sort_(std::vector<int64_t> &array, int start, int end);
	static int classic_partition_(std::vector<int64_t> &array, int start, int end);

	bool use_classic_variant_{};
};


#endif //QUICK_SORT_H
