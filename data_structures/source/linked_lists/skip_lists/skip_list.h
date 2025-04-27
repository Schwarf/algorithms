//
// Created by andreas on 27.04.25.
//

#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <vector>
#include <random>

template <typename KeyType, typename ValueType, int MaxLevel>
class SkipList{
  private:
    struct Node{
      KeyType key;
      ValueType value;
      std::vector<Node*> forward;
      Node(int level, const KeyType & key, const ValueType & value) :
         key(key), value(value), forward(level + 1, nullptr)
      {}
    };

    std::mt19937 generator;
    std::bernoulli_distribution distribution;
};
#endif //SKIP_LIST_H
