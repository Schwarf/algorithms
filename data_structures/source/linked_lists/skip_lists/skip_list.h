//
// Created by andreas on 27.04.25.
//

#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <vector>
#include <random>
// https://en.wikipedia.org/wiki/Skip_list

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
    Node * head;
    float probability{};
    int current_level{};
    std::mt19937 generator;
    std::bernoulli_distribution distribution;

public:
    explicit SkipList(float probability = 0.5) : probability(probability), generator(std::random_device{}()), distribution(probability){
      head = new Node(0, KeyType(), ValueType());
    }

    ~SkipList(){
      Node* current_node = head;
      while(current_node){
        Node* next_node = current_node->forward[0];
        delete current_node;
        current_node = next_node;
      }
    }



};
#endif //SKIP_LIST_H
