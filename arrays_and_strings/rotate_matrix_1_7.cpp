//
// Created by andreas on 13.03.22.
//
#include <vector>
#include <stdexcept>
#include <iostream>

template <class matrix_type, size_t dimension>
class SymmetricMatrix{
public:
	SymmetricMatrix(){
		data_ = std::vector<matrix_type>(dimension*dimension, matrix_type{});
	};

	matrix_type & operator()(size_t row, size_t column ){
		if(row > dimension - 1 || column > dimension -1)
		{
			throw std::out_of_range("Invalid matrix access!");
		}
		return data_[row + column*dimension];
	}

	void print_matrix()
	{

		for(size_t row_index = 0; row_index < dimension; ++row_index)
		{
			for(size_t column_index = 0; column_index < dimension; ++column_index)
			{
				std::cout << data_[row_index + column_index*dimension] <<", ";
			}
			std::cout << std::endl;
		}
	}
private:
	std::vector<matrix_type> data_;
};


int main()
{
	SymmetricMatrix<int, 3> dim3;
	dim3.operator()(0,0) = 2;
	dim3(2,2) = 1;
	dim3.print_matrix();

	return 0;
}