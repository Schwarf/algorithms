//
// Created by andreas on 15.01.22.
//

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"
#include <iostream>
enum ShellSortVariant
{
	classic, sedgewick, tokuda, ciura, fuchs
};

class ShellSort final: public ISort
{
public:
	ShellSort();
	void sort(std::vector<int64_t> &array) final;
	void set_variant(ShellSortVariant variant);
	~ShellSort() override = default;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
private:
	ShellSortVariant variant_{ShellSortVariant::classic};
	static void sort_3_N_plus_1_(std::vector<int64_t> &array);
	static void hard_coded_sequence_sort(std::vector<int64_t> &array,
										 const size_t sequence[],
										 size_t last_sequence_element);
	static size_t sedgewick_sequence_[20];
	static size_t tokuda_sequence_[20];
	static size_t ciura_sequence_[9];
	static size_t fuchs_sequence_[20];
};


#endif //SHELL_SORT_H
