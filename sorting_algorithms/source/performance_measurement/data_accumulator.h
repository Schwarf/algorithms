//
// Created by andreas on 16.01.22.
//

#ifndef DATA_ACCUMULATOR_H
#define DATA_ACCUMULATOR_H
#include "i_data_accumulator.h"

template<typename T>
class DataAccumulator: public IDataAccumulator<T>
{
public:
	void add_data_vector(const std::shared_ptr<std::vector<T>> data_vector) final
	{
		vector_of_data_.push_back(data_vector);
		maximum_index_++;
	}
	std::shared_ptr<std::vector<T>> get_data_vector(size_t index) const final
	{
		if (index <= maximum_index_)
			return vector_of_data_.at(index);
		return nullptr;
	}
	size_t number_of_entries() const
	{
		return maximum_index_;
	}
private:
	std::vector<std::shared_ptr<std::vector<T>>> vector_of_data_{};
	size_t maximum_index_{};

};


#endif //DATA_ACCUMULATOR_H
