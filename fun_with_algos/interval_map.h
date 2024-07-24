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
class IntervalMap {
private:
    struct FloatComparator {
        template<typename FloatType>
        bool operator()(const FloatType &lhs, const FloatType &rhs) const {
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

    IntervalMap() {
        interval_map_[std::numeric_limits<KeyType>::min()] = ValueType{};
    };

    ValueType const &operator[](const KeyType &key) const {
        return (--interval_map_.upper_bound(key))->second;
    }

    void add2(const KeyType &intervalBegin, const KeyType &intervalEnd, const ValueType &mappedValue) {
        if (intervalEnd <= intervalBegin)
            return;
        // End of the input interval-range
        auto iteratorPositionIntervalEnd = interval_map_.find(intervalEnd);
        // lowerbound can never point to start since a default value should be always there (constructor)
        auto lowerbound = interval_map_.lower_bound(intervalEnd);
        // [min, 1, 2] insert 5, lowerbound points to end -> [min, 1, 2, 5] and value of key 2 is now set to key 5
        // [min, 1, 10] insert 5, lowerbound points to 10 -> [min, 1, 5, 10] and value of key 10 is now set to key 5
        if (iteratorPositionIntervalEnd == interval_map_.end()) {
            iteratorPositionIntervalEnd = interval_map_.insert(interval_map_.end(),
                                                               std::make_pair(intervalEnd, (--lowerbound)->second));
        }

        // Beginning of the input range
        auto iteratorPositionIntervalBegin = interval_map_.insert_or_assign(intervalBegin, mappedValue).first;

        // Cleanup between interval start and end
        interval_map_.erase(std::next(iteratorPositionIntervalBegin), iteratorPositionIntervalEnd);

        // Merge intervals
        auto iteratorRight = iteratorPositionIntervalEnd;
        auto iteratorLeft = iteratorPositionIntervalBegin != interval_map_.begin() ? --iteratorPositionIntervalBegin
                                                                                   : iteratorPositionIntervalBegin;
        while (iteratorRight != iteratorLeft) {
            auto currentIterator = iteratorRight;
            auto previousIterator = --currentIterator;
            if (iteratorRight->second == previousIterator->second)
                interval_map_.erase(iteratorRight);
            iteratorRight = currentIterator;
        }
    }

    void add(const KeyType &intervalBegin, const KeyType &intervalEnd, const ValueType &mappedValue) {
        // invalid interval
        if (intervalEnd <= intervalBegin)
            return;

        auto intervalEndPosition = interval_map_.find(intervalEnd);
        auto lowerbound = interval_map_.lower_bound(intervalEnd);
        if (intervalEndPosition == interval_map_.end()) {
            intervalEndPosition = interval_map_.insert(std::make_pair(intervalEnd, lowerbound->second)).first;
        }

        auto intervalBeginPosition = interval_map_.insert_or_assign(intervalBegin, mappedValue).first;
        interval_map_.erase(std::next(intervalBeginPosition), intervalEndPosition);

        if (intervalBeginPosition != interval_map_.begin())
            intervalBeginPosition--;
        while (intervalBeginPosition != intervalEndPosition) {
            auto next = std::next(intervalBeginPosition);
            if (next->second == intervalBeginPosition->second)
                interval_map_.erase(intervalBeginPosition);
            intervalBeginPosition = next;
        }

    }

    void assign(const KeyType &keyBegin, const KeyType &keyEnd, const ValueType &val) {
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
            } else {
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
