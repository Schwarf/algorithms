//
// Created by andreas on 16.01.22.
//

#ifndef I_DATA_ACCUMULATOR_H
#define I_DATA_ACCUMULATOR_H
#include <vector>
#include <memory>
template <typename T>
class IDataAccumulator{
public:
	virtual void add_data_vector(std::shared_ptr<std::vector<T>>  data_vector) = 0;
	virtual std::shared_ptr<std::vector<T>> get_data_vector(size_t index) = 0;
};

#endif //I_DATA_ACCUMULATOR_H
