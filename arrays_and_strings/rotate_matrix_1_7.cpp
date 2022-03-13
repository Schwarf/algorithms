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
		return data_[column + row*dimension];
	}

	void print_matrix()
	{

		for(size_t row_index = 0; row_index < dimension; ++row_index)
		{
			for(size_t column_index = 0; column_index < dimension; ++column_index)
			{
				std::cout << data_[column_index + row_index*dimension] <<", ";
			}
			std::cout << std::endl;
		}
	}
private:
	std::vector<matrix_type> data_;
};

template <typename matrix_type, size_t dimension>
void fill_symmetric_matrix(SymmetricMatrix<matrix_type, dimension> & matrix)
{
	for(size_t row_index = 0; row_index < dimension; row_index++)
	{
		for(size_t column_index = 0; column_index < dimension; column_index++)
		{
			matrix(row_index, column_index) = 1 + column_index + row_index*dimension;
		}
	}

}


template <typename matrix_type, size_t dimension>
void rotate_symmetric_matrix(SymmetricMatrix<matrix_type, dimension> & matrix)
{

}



int main()
{
	SymmetricMatrix<int, 2> dim2;
	SymmetricMatrix<int, 3> dim3;
	SymmetricMatrix<int, 4> dim4;

	fill_symmetric_matrix<int, 2>(dim2);
	fill_symmetric_matrix<int, 3>(dim3);
	fill_symmetric_matrix<int, 4>(dim4);

	dim2.print_matrix();
	dim3.print_matrix();
	dim4.print_matrix();

	return 0;
}