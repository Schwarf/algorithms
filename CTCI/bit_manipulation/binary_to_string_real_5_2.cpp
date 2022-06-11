//
// Created by andreas on 11.06.22.
//
#include <string>
#include <iostream>
std::string print_binary(double number)
{
	if(number >=1 || number <=0)
	{
		return "Error";
	}
	std::string result{'.'};
	while(number > 0)
	{
		if(result.size() >31)
			return "Error";
		double r = number*2;
		if(r >=1)
		{
			result.append("1");
			number = r -1;
		}
		else
		{
			result.append("0");
			number = r;
		}
	}
	return result;
}


int main()
{
	double x =0.625;
	std::cout << print_binary(x) << std::endl;
}
