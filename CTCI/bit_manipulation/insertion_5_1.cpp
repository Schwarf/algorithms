//
// Created by andreas on 07.06.22.
//
#include <iostream>
bool get_bit(int number, int index)
{
	return (number & 1 << index) !=0;
}

int set_bit(int number, int index, bool value)
{
	return value ==1 ? (number | (1 << index)) : number & ~(1 << index);
}

int insert(int N, int M, int start, int end)
{
	int N_index = start;
	bool value{};
	while(N_index <= end)
	{
		int M_index = N_index - start;
		value = get_bit(M, M_index);
		std::cout <<"Index: "<< M_index << ":  " << value << std::endl;
		N = set_bit(N, N_index, value);
		std::cout <<"N: "<< N << std::endl;
		N_index++;
	}
	return N;
}

int main()
{
	int N = 1 << 11;
	int M{19};
	std::cout << N << std::endl;
	std::cout << M << std::endl;
	auto result = insert(N,M, 2, 6);
	auto expected = 2124;

	std::cout << result << std::endl;
	return 0;
}