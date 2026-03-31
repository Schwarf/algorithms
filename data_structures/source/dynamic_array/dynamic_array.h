//
// Created by andreas on 31.03.26.
//

#ifndef ALGORITHMS_DYNAMIC_ARRAY_H
#define ALGORITHMS_DYNAMIC_ARRAY_H
// Design a Dynamic Array (aka a resizable array) class, such as an ArrayList in
// Java or a vector in C++.
//
// Your DynamicArray class should support the following operations:
//
//     DynamicArray(int capacity) will initialize an empty array with a capacity
//     of capacity, where capacity > 0. int get(int i) will return the element
//     at index i. Assume that index i is valid. void set(int i, int n) will set
//     the element at index i to n. Assume that index i is valid. void
//     pushback(int n) will push the element n to the end of the array. int
//     popback() will pop and return the element at the end of the array. Assume
//     that the array is non-empty. void resize() will double the capacity of
//     the array. int getSize() will return the number of elements in the array.
//     int getCapacity() will return the capacity of the array.
//
// If we call void pushback(int n) but the array is full, we should resize the
// array first.
#include <stdexcept>
#include <concepts>

template <typename T>
requires std::is_default_constructible_v<T>;
class DynamicArray {
  T *array;
  int size{};
  int capacity{};

public:
  explicit DynamicArray(int capa) : size(), capacity(capa) {
    if (capa <= 0)
      throw std::invalid_argument("capacity must be > 0");
    array = new T[capacity];
  }

  DynamicArray(const DynamicArray &other) = delete;
  DynamicArray &operator=(const DynamicArray &other) = delete;
  ~DynamicArray() { delete[] array; }

  T &get(int i) {
    if (i < 0 || i >= size)
      throw std::out_of_range("index out of range");
    return array[i];
  }

  const T &get(int i) const {
    if (i < 0 || i >= size)
      throw std::out_of_range("index out of range");
    return array[i];
  }

  void set(int i, const T &value) {
    if (i < 0 || i >= size)
      throw std::out_of_range("index out of range");
    array[i] = value;
  }

  void pushBack(const T &value) {
    if (size == capacity)
      resize();
    array[size] = value;

    size++;
  }

  T popBack() {
    if (size == 0)
      throw std::out_of_range("popBack on empty DynamicArray");
    T val = array[size - 1];
    --size;
    return val;
  }

  void resize() {
    capacity *= 2;
    T *new_array = new T[capacity];

    for (int i{}; i < size; ++i) {
      new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
  }

  int getSize() const { return size; }

  int getCapacity() const { return capacity; }
};

#endif // ALGORITHMS_DYNAMIC_ARRAY_H
