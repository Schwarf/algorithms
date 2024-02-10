//
// Created by andreas on 30.01.24.
//

#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H
#include <map>
#include <iterator>
#include <utility>
#include <cmath>
template<typename KeyType, typename ValueType>
class IntervalMap
{
private:
	struct FloatComparator
	{
		template<typename FloatType>
		bool operator()(const FloatType &lhs, const FloatType &rhs) const
		{
			if (rhs == FloatType{})
				return lhs < rhs;
			if (std::fabs(static_cast<FloatType>(1) - lhs / rhs) < std::numeric_limits<FloatType>::epsilon()) {
				return false;
			}
			return lhs < rhs;
		}
	};


public:
	std::map<KeyType, ValueType> interval_map_;
	std::map<KeyType,
			 ValueType,
			 std::conditional_t<std::is_floating_point_v<KeyType>, FloatComparator, std::less<KeyType>>> m_map;

	IntervalMap()
	{

		interval_map_.insert(interval_map_.end(),
							 std::make_pair<KeyType, ValueType>(std::numeric_limits<KeyType>::min(), ValueType{}));
	};

	ValueType const &operator[](const KeyType &key) const
	{
		return (--interval_map_.upper_bound(key))->second;
	}

	void add2(const KeyType &intervalBegin, const KeyType &intervalEnd, const ValueType &mappedValue)
	{

		// End of the input range
		auto itEnd = interval_map_.find(intervalEnd);
		if (auto l = interval_map_.lower_bound(intervalEnd); itEnd != interval_map_.end())
			itEnd->second = l->second;
		else
			itEnd = interval_map_.insert(interval_map_.end(), std::make_pair(intervalEnd, (--l)->second));

		// Beginning of the input range
		auto itBegin = interval_map_.insert_or_assign(intervalBegin, mappedValue).first;

		// Cleanup the new range
		interval_map_.erase(std::next(itBegin), itEnd);

		// Make canonical
		auto itRight = itEnd;
		auto itLeft = (itBegin != interval_map_.begin() ? std::prev(itBegin) : itBegin);
		while (itRight != itLeft) {
			auto itNext = std::prev(itRight);
			if (itRight->second == itNext->second)
				interval_map_.erase(itRight);
			itRight = itNext;
		}
	}

	void add(const KeyType &intervalBegin, const KeyType &intervalEnd, const ValueType &mappedValue)
	{
		// invalid interval
		if (intervalEnd <= intervalBegin)
			return;

		auto end = interval_map_.find(intervalEnd);

		auto beforeEnd = interval_map_.lower_bound(intervalEnd);
		if (end != beforeEnd)
			auto x = 1;
		if (end == interval_map_.end()) {
			end = interval_map_.insert(std::make_pair(intervalEnd, beforeEnd->second)).first;
		}
		else {
			end->second = beforeEnd->second;
		}

		auto begin = interval_map_.insert_or_assign(intervalBegin, mappedValue).first;
		interval_map_.erase(std::next(begin), end);

		if (begin != interval_map_.begin())
			begin--;
		while (begin != end) {
			auto next = std::next(begin);
			if (next->second == begin->second)
				interval_map_.erase(begin);
			begin = next;
		}

	}

	void assign(const KeyType &keyBegin, const KeyType &keyEnd, const ValueType &val)
	{
		if (!(keyBegin < keyEnd))
			return;
		if (m_map.empty()) {
			m_map[keyBegin] = val;
			return;
		}
		auto nextInterval = --m_map.upper_bound(keyEnd);
		auto inserted1 = m_map.end();
		auto inserted2 = m_map.end();
		if (nextInterval->second == val)
			++nextInterval;
		else if (nextInterval->first < keyEnd) {
			const ValueType &nextValue = nextInterval->second;
			++nextInterval;
			inserted1 = nextInterval = m_map.emplace_hint(nextInterval, keyEnd, nextValue);
		}
		auto prevInterval = nextInterval;
		--prevInterval;
		if (keyBegin < prevInterval->first)
			prevInterval = --m_map.upper_bound(keyBegin);
		if (!(prevInterval->second == val)) {
			if (prevInterval->first < keyBegin) {
				++prevInterval;
				inserted2 = prevInterval = m_map.emplace_hint(prevInterval, keyBegin, val);
			}
			else {
				auto beforePrev = prevInterval;
				--beforePrev;
				if (beforePrev != m_map.end() && beforePrev->second == val)
					prevInterval = beforePrev;
				else {
					auto hint = m_map.erase(prevInterval);
					inserted2 = prevInterval = m_map.emplace_hint(hint, keyBegin, val);
				}
			}
		}
		m_map.erase(++prevInterval, nextInterval);

	}

};

#endif //INTERVAL_MAP_H
