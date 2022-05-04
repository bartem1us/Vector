//
// Created by bartem1us on 3/28/21.
//
#include <Iterator.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#ifndef TEMPLATE_VECTOR_H
#define TEMPLATE_VECTOR_H
namespace vectorCapacity {
double coefficient = 2;
}
template <class T>
class vector {
  size_t capacity_vec = 0;
  size_t size_vec = 0;
  T* vec = nullptr;

 public:
  friend class Iterator<T>;
  vector() = default;
  vector(const vector<T>& vec1)
      : capacity_vec(vec1.capacity_vec),
        size_vec(vec1.size_vec),
        vec(new T[capacity_vec]) {
    std::copy(vec1.begin(), vec1.end(), begin());
  }
  vector(size_t size1, const T elem)
      : capacity_vec(size1), size_vec(size1), vec(new T[size1]) {
    std::fill(begin(), end(), elem);
  }
  ~vector() { delete[] vec; }
  size_t size() const { return size_vec; }

  void reserve(size_t size1) {
    if (size1 > capacity_vec) {
      capacity_vec = size1;
      T* arr2 = vec;
      vec = new T[capacity_vec];
      if (arr2 != nullptr) {
        std::copy(arr2, arr2 + size_vec, vec);
        delete[] arr2;
      }
    }
  }
  bool empty() const { return size_vec == 0; }
  size_t capacity() const { return capacity_vec; }

  void clear() { size_vec = 0; }
  T& operator[](size_t i) { return vec[i]; }
  T operator[](size_t i) const { return vec[i]; }

  T& at(size_t i) {
    if (i >= size_vec) {
      throw std::out_of_range("Vector over");
    }

    return vec[i];
  }
  T at(size_t i) const {
    if (i >= size_vec) {
      throw std::out_of_range("Vector over");
    }

    return vec[i];
  }
  void pop_back() { --size_vec; }
  void push_back(T elem) {
    if(capacity_vec == 0)
    {
      ++capacity_vec;
      vec = new T [capacity_vec];
    }
    if (size_vec == capacity_vec) {
      size_t kf =(size_t)(size_vec * vectorCapacity::coefficient);
      reserve(kf);
    }
    vec[size_vec] = elem;
    ++size_vec;
  }
  void swap(vector<T>& vec2) {
    std::swap(vec2.vec, vec);
    std::swap(size_vec, vec2.size_vec);
    std::swap(capacity_vec, vec2.capacity_vec);
  }

  T front() { return *(begin()); }

  T back() { return *(end()-1); }
  T front() const { return *begin(); }
  T back() const { return *(end() - 1); }
  T* data() { return vec; }
  Iterator<T> begin() { return Iterator(vec); }
  const Iterator<T> begin() const { return Iterator(vec); }
  Iterator<T> end() { return Iterator(vec + size_vec); }
  const Iterator<T> end() const { return Iterator(vec + size_vec); }
};
#endif  // TEMPLATE_VECTOR_H
