//
// Created by andreas on 30.01.24.
//

#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H
#include <map>
#include <iterator>
#include <utility>
template <typename KeyType, typename ValueType>
class IntervalMap{

public:
	std::map<KeyType, ValueType> interval_map_;
	IntervalMap()
	{
		//interval_map_.insert(interval_map_.end(), std::make_pair<KeyType,ValueType >(std::numeric_limits<KeyType>::min(), ValueType{}));
	};

	ValueType const & operator[](const KeyType & key) const
	{
		return (--interval_map_.upper_bound(key))->second;
	}
	void add(const KeyType & intervalBegin, const KeyType & intervalEnd, const ValueType & mappedValue)
	{
		// invalid interval
		if(intervalEnd <= intervalBegin)
			return;

		auto begin = interval_map_.find(intervalBegin);
		auto end = interval_map_.find(intervalEnd);

		// Found both 'begin' and 'end' or endInterval is beyond last element
		if(begin != interval_map_.end() && (end != interval_map_.end() || intervalEnd > std::prev(interval_map_.end())->first))
		{
			std::cout << intervalEnd <<  ", " <<std::prev(interval_map_.end())->first << std::endl;
			// Overwrite all intervals that are between intervalBegin and intervalEnd
			while(begin != end)
			{
				interval_map_.erase(begin++);
			}
			interval_map_[intervalBegin] = mappedValue;
		}
		// Found 'begin' but not 'end', but 'end' is below the highest stored value
		else if(begin != interval_map_.end() && end == interval_map_.end())
		{
			auto oldValue = interval_map_[intervalBegin];
			while(begin->first < intervalEnd)
			{
				interval_map_.erase(begin++);
				if(begin->first < intervalEnd)
					oldValue = begin->second;
			}
			interval_map_[intervalEnd] = oldValue;
			interval_map_[intervalBegin] = mappedValue;

		}
		// Found 'end' but not 'begin'
		else if(begin == interval_map_.end() && end != interval_map_.end())
		{
			begin = interval_map_.lower_bound(intervalBegin);
			interval_map_[intervalBegin] = mappedValue;
			while(begin != end)
			{
				interval_map_.erase(begin++);
			}

		}
		// container empty
		else if (interval_map_.empty()) {
			interval_map_[intervalBegin] = mappedValue;
		}
		// both are not found
		else {
			begin = interval_map_.lower_bound(intervalBegin);
			end = interval_map_.lower_bound(intervalEnd);

			if (begin == end) {
				interval_map_[intervalEnd] = std::prev(begin)->second;
				interval_map_[intervalBegin] = mappedValue;
			}
			else
			{
				interval_map_[intervalEnd] = std::prev(end)->second;
				interval_map_[intervalBegin] = mappedValue;
				while(begin != end)
				{
					interval_map_.erase(begin++);
				}
			}

		}

	}


};

#endif //INTERVAL_MAP_H
