//
// Created by andreas on 11.02.24.
//

#ifndef INTERVAL_MAP2_H
#define INTERVAL_MAP2_H

#include <map>
#include <limits>
#include <utility>

template<typename K, typename V>
class interval_map {
public:
    V m_valBegin;
    std::map<K, V> m_map;
public:
    // constructor associates whole range of K with val
    interval_map(V const &val)
            : m_valBegin(val) {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
//	(I)   Type requirements are met: You must adhere to the specification of the key and value type given above.
//	(II)  Correctness: Your program should produce a working interval_map with the behavior described above. In particular, pay attention to the validity of iterators. It is illegal to dereference end iterators. Consider using a checking STL implementation such as the one shipped with Visual C++ or GCC.
//	(III) Canonicity: The representation in m_map must be canonical.
//
//	(IIII) Running time: Imagine your implementation is part of a library, so it should be big-O optimal. In addition:
//		                Do not make big-O more operations on K and V than necessary because you do not know how fast operations on K/V are; remember that constructions, destructions and assignments are operations as well.
//	                    Do not make more than one operation of amortized O(log N), in contrast to O(1), running time, where N is the number of elements in m_map.

    void assign(K const &keyBegin, K const &keyEnd, V const &val) {
        if (!(keyBegin < keyEnd)) // Requirement (I) nothing else but the < operator is defined
            return;

        if (m_map.empty()) {
            m_map.insert(m_map.end(), std::make_pair(keyBegin, val));
            m_map.insert(m_map.end(), std::make_pair(keyEnd, m_valBegin));
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
        // Requirement (IV) we only make one O(log N) operation
        if (lowerbound == m_map.end() ||
            keyEnd < lowerbound->first) { // Requirement (I) nothing else but the < operator is defined
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
        m_map.erase(++next, iteratorPositionkeyEnd); //

        // Merge intervals with same values in inserted interval range
        auto iteratorRight = iteratorPositionkeyEnd;
        auto iteratorLeft =
                iteratorPositionkeyBegin != m_map.begin() ? --iteratorPositionkeyBegin : iteratorPositionkeyBegin;
        while (iteratorRight != iteratorLeft) {
            auto previousIterator = std::prev(iteratorRight);
            if (iteratorRight->second == previousIterator->second)
                m_map.erase(iteratorRight);
            iteratorRight = previousIterator;
        }

    }

    // look-up of the value associated with key
    V const &operator[](K const &key) const {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
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
