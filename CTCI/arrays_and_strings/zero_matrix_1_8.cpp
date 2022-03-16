//
// Created by andreas on 13.03.22.
//

#include <vector>
#include <set>
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

	matrix_type &operator()(size_t row_index, size_t column_index)
	{
		if (row_index > row_dimension - 1 || column_index > column_dimension - 1) {
			throw std::out_of_range("Invalid matrix access!");
		}
		return data_[column_index + row_index * column_dimension];
	}

	bool operator==(Matrix<matrix_type, row_dimension, column_dimension> &other)
	{
		for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
			for (size_t column_index = 0; column_index < column_dimension; ++column_index) {
				if (data_[column_index + row_index * column_dimension]
					!= other.data_[column_index + row_index * column_dimension])
					return false;
			}
		}
		return true;
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
	std::vector<bool> row_indices(row_dimension, false);
	std::vector<bool> column_indices(column_dimension, false);
	for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
		for (size_t column_index = 0; column_index < column_dimension; column_index++) {
			if (matrix(row_index, column_index) == 0) {
				row_indices[row_index] = true;
				column_indices[column_index] = true;
			}
		}
	}

	for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
		if (row_indices[row_index]) {
			for (size_t column_index = 0; column_index < column_dimension; column_index++) {
				matrix(row_index, column_index) = 0;
			}
		}
	}

	for (size_t column_index = 0; column_index < column_dimension; ++column_index) {
		if (column_indices[column_index]) {
			for (size_t row_index = 0; row_index < row_dimension; row_index++) {
				matrix(row_index, column_index) = 0;
			}
		}
	}

}

template<typename matrix_type, size_t row_dimension, size_t column_dimension>
void zero_matrix_optimized(Matrix<matrix_type, row_dimension, column_dimension> &matrix)
{
	bool first_row_has_zero{};
	bool first_column_has_zero{};
	for (size_t column_index = 0; column_index < column_dimension; ++column_index) {
		if (matrix(0, column_index) == 0) {
			first_row_has_zero = true;
			break;
		}
	}
	for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
		if (matrix(row_index, 0) == 0) {
			first_column_has_zero = true;
			break;
		}
	}
	for (size_t row_index = 1; row_index < row_dimension; ++row_index) {
		for (size_t column_index = 1; column_index < column_dimension; column_index++) {
			if (matrix(row_index, column_index) == 0) {
				matrix(0, column_index) = 0;
				matrix(row_index, 0) = 0;
			}
		}
	}

	for (size_t row_index = 1; row_index < row_dimension; ++row_index) {
		if (matrix(row_index, 0) == 0) {
			for (size_t column_index = 0; column_index < column_dimension; column_index++) {
				matrix(row_index, column_index) = 0;
			}
		}
	}

	for (size_t column_index = 1; column_index < column_dimension; ++column_index) {
		if (matrix(0, column_index) == 0) {
			for (size_t row_index = 0; row_index < row_dimension; row_index++) {
				matrix(row_index, column_index) = 0;
			}
		}
	}

	if (first_row_has_zero) {
		for (size_t column_index = 0; column_index < column_dimension; column_index++) {
			matrix(0, column_index) = 0;
		}
	}

	if (first_column_has_zero) {
		for (size_t row_index = 0; row_index < row_dimension; ++row_index) {
			matrix(row_index, 0) = 0;
		}
	}
}

int main()
{
	Matrix<int, 3, 2> dim23;
	fill_matrix<int, 3, 2>(dim23);
	dim23.print_matrix();
	dim23(1, 1) = 0;
	dim23.print_matrix();
	zero_matrix<int, 3, 2>(dim23);
	dim23.print_matrix();

	Matrix<int, 20, 30> dim2030;
	fill_matrix<int, 20, 30>(dim2030);
	Matrix<int, 20, 30> dim2030_2;
	fill_matrix<int, 20, 30>(dim2030_2);
	std::cout << "Is equal = " << (dim2030 == dim2030_2) <<std::endl;
	dim2030.print_matrix();
	dim2030(10, 5) = 0;
	dim2030(17, 14) = 0;

	dim2030_2(10, 5) = 0;
	dim2030_2(17, 14) = 0;


	zero_matrix<int, 20, 30>(dim2030);
	zero_matrix_optimized<int, 20, 30>(dim2030_2);
	std::cout << "Is equal = " << (dim2030 == dim2030_2) <<std::endl;
	dim2030.print_matrix();

}