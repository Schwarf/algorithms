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
	if( start> end || start < 0 || end>= 32) return 0;
	int N_index = start;
	bool value{};
	while(N_index <= end)
	{
		int M_index = N_index - start;
		value = get_bit(M, M_index);
		N = set_bit(N, N_index, value);
		N_index++;
	}
	return N;
}

int master_solution(int n, int m, int i, int j)
{
	if( i> j || i < 0 || j>= 32) return 0;
	int allOnes = ~0;
	int left = j < 31 ? (allOnes << (j+1)) : 0;
	int right = (1<<i) - 1;
	int mask = left + right;
	int n_cleared = n & mask;
	int m_shifted = m << i;
	return n_cleared | m_shifted;
}

int main()
{
	int N = 1 << 11;
	int M{19};
	std::cout << N << std::endl;
	std::cout << M << std::endl;
	auto result = insert(N,M, 2, 6);
	auto expected = master_solution(N, M, 2, 6);

	std::cout << result << std::endl;
	std::cout << expected << std::endl;
	return 0;
}