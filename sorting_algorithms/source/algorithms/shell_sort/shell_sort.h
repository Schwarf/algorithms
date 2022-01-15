//
// Created by andreas on 15.01.22.
//

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class ShellSort final: public ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	~ShellSort() override = default;
private:
	static void sort_3_N_plus_1_(std::vector<int64_t> &array);
	static void sort_sedgewick_sequence_(std::vector<int64_t> &array);
	static void sort_tokuda_sequence_(std::vector<int64_t> &array);
	static void sort_ciura_sequence_(std::vector<int64_t> &array);
	int64_t sedgewick_sequence_[20]
		{1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305, 260609, 587521, 1045505,
		 2354689, 4188161};
	int64_t tokuda_sequence_[20]
		{1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301, 68178, 153401, 345152, 776591, 1747331,
		 3931496, 8845866};
	int64_t ciura_sequence_[9] = {	1, 4, 10, 23, 57, 132, 301, 701, 1750 };
};


#endif //SHELL_SORT_H
