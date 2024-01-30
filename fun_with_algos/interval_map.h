//
// Created by andreas on 30.01.24.
//

#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H
#include <map>
template <typename KeyType, typename ValueType>
class IntervalMap{
private:
	std::map<KeyType, ValueType> interval_map_;
public:
	IntervalMap() = default;

	void add(const KeyType & intervalBegin, const KeyType & intervalEnd, const ValueType & mappedValue)
	{
		// invalid interval
		if(intervalEnd <= intervalBegin)
			return;

		auto greaterEqualIntervalBeginIterator = interval_map_.lower_bound(intervalBegin);
		// Add new interval
		if(greaterEqualIntervalBeginIterator != interval_map_.begin())
		{
			auto previousIterator = std::prev(greaterEqualIntervalBeginIterator);
			if((*previousIterator).first < intervalBegin)
				interval_map_.insert(std::pair<ValueType, KeyType>{intervalBegin, mappedValue});
		}

		// Merge intervals
		auto currentIterator = greaterEqualIntervalBeginIterator;
		while(currentIterator != interval_map_.end() && (*currentIterator).first <= intervalEnd)
		{
			// Case: Current interval has same mappedValue as incoming mappedValue
			if(currentIterator->second == mappedValue)
			{
				currentIterator++;
			}
			else
			{   // Given  begin = 3, end = 8 and [1,3,5,7,9] --> need to erase 5 and 7
				// we start at 3
				auto nextIterator = std::next(currentIterator);
				if(nextIterator != interval_map_.end() && nextIterator->first <= intervalEnd)
				{
					interval_map_.erase(currentIterator);
					currentIterator = nextIterator;
				}
				else if(currentIterator->first < intervalEnd)
				{
					interval_map_[intervalEnd] = currentIterator->second;
				}
			}
		}
		interval_map_[intervalBegin] = mappedValue;
	}

	ValueType const & operator[](const KeyType & key) const
	{
		return (--interval_map_.upper_bound(key))->second;
	}
};

#endif //INTERVAL_MAP_H
