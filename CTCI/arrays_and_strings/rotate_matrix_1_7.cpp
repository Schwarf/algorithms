//
// Created by andreas on 13.03.22.
//
#include <vector>
#include <stdexcept>
#include <iostream>

template<class matrix_type, size_t dimension>
class SymmetricMatrix
{
public:
	SymmetricMatrix()
	{
		data_ = std::vector<matrix_type>(dimension * dimension, matrix_type{});
	};

	matrix_type &operator()(size_t row, size_t column)
	{
		if (row > dimension - 1 || column > dimension - 1) {
			throw std::out_of_range("Invalid matrix access!");
		}
		return data_[column + row * dimension];
	}

	void print_matrix()
	{

		for (size_t row_index = 0; row_index < dimension; ++row_index) {
			for (size_t column_index = 0; column_index < dimension; ++column_index) {
				std::cout << data_[column_index + row_index * dimension] << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
private:
	std::vector<matrix_type> data_;
};

template<typename matrix_type, size_t dimension>
void fill_symmetric_matrix(SymmetricMatrix<matrix_type, dimension> &matrix)
{
	for (size_t row_index = 0; row_index < dimension; row_index++) {
		for (size_t column_index = 0; column_index < dimension; column_index++) {
			matrix(row_index, column_index) = 1 + column_index + row_index * dimension;
		}
	}

}

template<typename matrix_type, size_t dimension>
void rotate_symmetric_matrix(SymmetricMatrix<matrix_type, dimension> &matrix)
{
	if (dimension < 2)
		return;
	for (size_t layer_index = 0; layer_index < dimension / 2; ++layer_index) {
		auto first_index = layer_index;
		auto last_index = dimension - 1 - layer_index;
		for (size_t index = layer_index; index < last_index; ++index) {
			auto off_set = index - first_index;
			auto top_element = matrix(first_index, index);
			// move left column to top row
			matrix(first_index, index) = matrix(last_index - off_set, first_index);
			// move bottom row to left column
			matrix(last_index - off_set, first_index) = matrix(last_index, last_index - off_set);
			// move right column to bottom row
			matrix(last_index, last_index - off_set) = matrix(index, last_index);
			// move top row to right column
			matrix(index, last_index) = top_element;
		}
	}
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

	rotate_symmetric_matrix<int, 2>(dim2);
	rotate_symmetric_matrix<int, 3>(dim3);
	rotate_symmetric_matrix<int, 4>(dim4);

	dim2.print_matrix();
	dim3.print_matrix();
	dim4.print_matrix();

	return 0;
}