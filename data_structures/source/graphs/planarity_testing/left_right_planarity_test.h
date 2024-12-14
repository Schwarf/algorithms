//
// Created by andreas on 14.12.24.
//

#ifndef LEFT_RIGHT_PLANARITY_TEST_H
#define LEFT_RIGHT_PLANARITY_TEST_H
#include <optional>

#include "graphs/graph.h"

struct Interval
{
    std::optional<int> start{};
    std::optional<int> end{};
};

class ConflictPair
{
    Interval left{};
    Interval right{};

public:
    explicit ConflictPair(const Interval& left = Interval(), const Interval& right = Interval())
        : left(left), right(right)
    {
    }

    // Accessor for L
    [[nodiscard]] const Interval& getL() const
    {
        return left;
    }

    // Accessor for R
    [[nodiscard]] const Interval& getR() const
    {
        return right;
    }

    // Mutator for L
    void setL(const Interval& interval)
    {
        left = interval;
    }

    // Mutator for R
    void setR(const Interval& interval)
    {
        right = interval;
    }
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
