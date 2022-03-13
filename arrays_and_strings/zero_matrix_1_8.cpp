//
// Created by andreas on 13.03.22.
//

#include <vector>
#include <stdexcept>
#include <iostream>

template<class matrix_type, size_t row_dimension, size_t column_dimension>
class Matrix
{
public:
	Matrix()
	{
		data_ = std::vector<matrix_type>(row_dimension * column_dimension, matrix_type{});
	};

	matrix_type &operator()(size_t row, size_t column)
	{
		if (row > row_dimension - 1 || column > column_dimension - 1) {
			throw std::out_of_range("Invalid matrix access!");
		}
		return data_[column + row * column_dimension];
	}

	void print_matrix()
	{
		for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
			for (size_t column_index = 0; column_index < column_dimension; ++column_index) {
				std::cout << data_[column_index + row_index * column_dimension] << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
private:
	std::vector<matrix_type> data_;
};

template<typename matrix_type, size_t row_dimension, size_t column_dimension>
void fill_matrix(Matrix<matrix_type, row_dimension, column_dimension> &matrix)
{
	for (size_t row_index = 0; row_index < row_dimension; row_index++) {
		for (size_t column_index = 0; column_index < column_dimension; column_index++) {
			matrix(row_index, column_index) = 1 + column_index + row_index * column_dimension;
		}
	}

}

template<typename matrix_type, size_t row_dimension, size_t column_dimension>
void zero_matrix(Matrix<matrix_type, row_dimension, column_dimension> &matrix)
{
}

int main()
{
	Matrix<int, 3, 2> dim23;
	fill_matrix<int, 3, 2>(dim23);
	dim23.print_matrix();

}