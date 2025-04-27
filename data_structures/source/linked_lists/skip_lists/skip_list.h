//
// Created by andreas on 27.04.25.
//

#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <vector>
#include <random>
// https://en.wikipedia.org/wiki/Skip_list

template <typename KeyType, typename ValueType, int MaxLevel>
class SkipList
{
private:
    struct Node
    {
        KeyType key;
        ValueType value;
        std::vector<Node*> forward;

        Node(int level, const KeyType& key, const ValueType& value) :
            key(key), value(value), forward(level + 1, nullptr)
        {
        }
    };

    Node* header;
    float probability{};
    int current_level{};
    std::mt19937 generator;
    std::bernoulli_distribution distribution;

    // Randomly generate a level for a new node
    int randomLevel()
    {
        int level{};
        while (level < MaxLevel && distribution(generator))
        {
            level++;
        }
        return level;
    }

public:
    explicit SkipList(float probability = 0.5) : probability(probability), generator(std::random_device{}()),
                                                 distribution(probability)
    {
        // create head on all levels
        header = new Node(MaxLevel, KeyType(), ValueType());
    }

    ~SkipList()
    {
        Node* current_node = header;
        while (current_node)
        {
            Node* next_node = current_node->forward[0];
            delete current_node;
            current_node = next_node;
        }
    }



    void insert(const KeyType& key, const ValueType& value)
    {
        std::vector<Node*> update(MaxLevel + 1);
        auto current_node = header;
        // find insertion point by scanning from current top-level to 0.
        // At EACH level we walk forward along the forwrad pointers as long as the next(forward)-key is < key
        // When we can’t move forward without overshooting, we record update[i] = current_node.
        for (int level = current_level; level > -1; level--)
        {
            while (current_node->forward[level] && current_node->forward[level]->key < key)
            {
                current_node = current_node->forward[level];
            }
            update[level] = current_node;
        }
        // After that loop, current_node->forward[0] is either
        // - the node with our key (if it exists)  OR
        // - the first node greater than the provided key. (**)
        current_node = current_node->forward[0];

        // If the key exist we just update the value
        if (current_node && current_node->key == key)
        {
            current_node->value = value;
            return;
        }

        // We decide which levels (all, some, 1) get the new key-value pair
        // for that we make coin-flip(s) and the level is defined by std::max(MaxLevel, consecutive-successful-coin-flips)
        int new_level = randomLevel();
        if (new_level > current_level)
        {
            // for all levels we have to set the header
            for (int level = current_level + 1; level <= new_level; ++level)
            {
                update[level] = header;
            }
            current_level = new_level;
        }

        auto new_node = new Node(new_level, key, value);

        // Splice the new node into each level 0..newLevel
        // At each level i:
        //   Before: update[i]->forward[i] points to oldNext
        //   After:  update[i]->forward[i] points to newNode, and newNode->forward[i] points to oldNext
        // Visual for level i:
        //   [update[i]] --forward[i]--> [oldNext]
        //                  |
        //                  +--> now points to [newNode] --forward[i]--> [oldNext]
        // This loop does exactly that for all levels of the new node.
        for (int level = 0; level <= new_level; ++level)
        {
            new_node->forward[level] = update[level]->forward[level];
            update[level]->forward[level] = new_node;
        }
    }

    bool remove(const KeyType& key)
    {
        std::vector<Node*> update(MaxLevel + 1);
        auto current_node = header;
        for(int level = current_level; level > -1; --level)
        {
            while (current_node->forward[level] && current_node->forward[level]->key < key)
            {
                current_node = current_node->forward[level];
            }
            update[level] = current_node;
        }
        // After that loop, current_node->forward[0] is either
        // - the node with our key (if it exists)  OR
        // - the first node greater than the provided key. (**)
        current_node = current_node->forward[0];

        // key not found
        if (!current_node || current_node->key != key)
            return false;


        for(int level = 0; level <= current_level; ++level)
        {
            // we stop as soon as we hit a level where current_node is not found
            if(update[level]->forward[level] != current_node)
                break;
            update[level]->forward[level] = current_node->forward[level];
        }
        delete current_node;
        // Adjust current_level
        while(current_level > 0 && header->forward[current_level]->key == nullptr)
        {
            --current_level;
        }
        return true;
    }

};
#endif //SKIP_LIST_H
