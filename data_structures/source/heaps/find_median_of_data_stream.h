//
// Created by andreas on 06.04.25.
//

#ifndef FIND_MEDIAN_OF_DATA_STREAM_H
#define FIND_MEDIAN_OF_DATA_STREAM_H
#include <concepts>
#include <queue>
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
//
//    For example, for arr = [2,3,4], the median is 3.
//    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
//
// Implement the MedianOfDataStream class:
//
//    MedianOfDataStream() initializes the MedianFinder object.
//    void add_element(T element) adds the element from the data stream to the data structure.
//    double find_median() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

template <typename T>
requires std::is_arithmetic_v<T>
class MedianOfDataStream {
  std::priority_queue<T, std::vector<T>, std::less<T>> max_heap;
  std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap;
  public:
    void add_element(T element) {
      if(max_heap.empty() || max_heap.top() >= element) {
        max_heap.push(element);
      }
      else {
          min_heap.push(element);
      }

      if(max_heap.size() == min_heap.size()+2) {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
      if(min_heap.size() == max_heap.size()+2) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
    }

    double find_median()
    {
      if(max_heap.size() == min_heap.size()) {
          return (static_cast<double>(max_heap.top()) + static_cast<double>(min_heap.top()))/2.0;
      }
      else if(max_heap.size() > min_heap.size())
      {
        return static_cast<double>(max_heap.top());
      }
      return static_cast<double>(min_heap.top());
    }
};
#endif //FIND_MEDIAN_OF_DATA_STREAM_H
