//
// Created by andreas on 29.05.22.
//
#include <iostream>

bool has_bit(int number, int bit_index)
{
	return (number & (1 << bit_index)) != 0;
}

void multiply(int a, int b, int bit_index, int &sum)
{
	if (bit_index == 31)
		return;
	sum += has_bit(b, bit_index) ? (a << bit_index) : 0;

	multiply(a, b, ++bit_index, sum);
}

int recurse_product(int smaller, int bigger)
{
	if(smaller ==0)
		return 0;
	if(smaller ==1)
		return bigger ; // 1 x bigger

	int half = smaller >> 1;
	int half_product = recurse_product(half, bigger);
	if(smaller & 1)
	{
		return  half_product + half_product + bigger;
	}
	else
		return half_product + half_product;
}

int master_solution(int a, int b)
{
	auto smaller = a<b ? a :b;
	auto bigger = a<b ? b :a;
	return recurse_product(smaller, bigger);
}


int main()
{
	int x{570};
	int y{10};
	int sum{};
	multiply(x, y, 0, sum);

	std::cout << sum << std::endl;
	std::cout << master_solution(x, y) << std::endl;
}
