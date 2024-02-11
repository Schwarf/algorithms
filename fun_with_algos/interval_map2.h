//
// Created by andreas on 11.02.24.
//

#ifndef INTERVAL_MAP2_H
#define INTERVAL_MAP2_H
#include <map>
#include <limits>
template<typename K, typename V>
class interval_map {
public:
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
		: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if (keyEnd <= keyBegin)
			return;

		if(m_map.empty()) {
			m_map[keyBegin] = val;
			m_map[keyEnd] = m_valBegin;
			return;
		}

		// End of the input interval-range
//		auto iteratorPositionkeyEnd = m_map.find(keyEnd);
//		// lowerbound can never point to start since a default value should be always there (constructor)
//		auto lowerbound = m_map.lower_bound(keyEnd);
//		// [min, 1, 2] insert 5, lowerbound points to end -> [min, 1, 2, 5] and value of key 2 is now set to key 5
//		// [min, 1, 10] insert 5, lowerbound points to 10 -> [min, 1, 5, 10] and value of key 10 is now set to key 5
//		if (iteratorPositionkeyEnd == m_map.end())
//		{
//			iteratorPositionkeyEnd = m_map.insert(m_map.end(),  std::make_pair(keyEnd, (--lowerbound)->second));
//		}

		auto lowerbound = m_map.lower_bound(keyEnd);
		auto iteratorPositionkeyEnd = lowerbound;
		if (lowerbound == m_map.end() || lowerbound->first != keyEnd) {
			// Key does not exist, insert using the value from the immediate predecessor
			auto valueToInsert = lowerbound == m_map.begin() ? m_valBegin : std::prev(lowerbound)->second;
			// Insert at the lowerbound position, which is the correct spot for keyEnd
			auto insertResult = m_map.insert(lowerbound, std::make_pair(keyEnd, valueToInsert));
			// Update iteratorPositionkeyEnd to point to the newly inserted element
			iteratorPositionkeyEnd = insertResult;
		}

		// Beginning of the input range
		auto iteratorPositionkeyBegin = m_map.insert_or_assign(keyBegin, val).first;

		// Cleanup between interval start and end
		auto next = iteratorPositionkeyBegin;
		m_map.erase(++next, iteratorPositionkeyEnd);

		// Merge intervals with same values
		auto iteratorRight = iteratorPositionkeyEnd;
		auto iteratorLeft = iteratorPositionkeyBegin != m_map.begin() ? --iteratorPositionkeyBegin : iteratorPositionkeyBegin;
		while (iteratorRight != iteratorLeft) {
			auto currentIterator = iteratorRight;
			auto previousIterator = --currentIterator;
			if (iteratorRight->second == previousIterator->second)
				m_map.erase(iteratorRight);
			iteratorRight = currentIterator;
		}

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
#endif //INTERVAL_MAP2_H
