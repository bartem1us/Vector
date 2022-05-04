//
// Created by bartem1us on 4/3/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#ifndef TEMPLATE_ITERATOR_H
#define TEMPLATE_ITERATOR_H
template <typename ValueType>
class Iterator : public std::iterator<std::random_access_iterator_tag, ValueType> {
  ValueType* arr;
 public:
  Iterator& operator=(const Iterator rhs) {
    arr = rhs.arr;
    return *this;
  }
  Iterator& operator=(ValueType* rhs) { arr = rhs; return *this; }
  Iterator() : arr(nullptr) {}
  Iterator(const Iterator& it) : arr(it.arr) { }
  explicit Iterator(ValueType* smth) : arr(smth) {}
  Iterator& operator++() {
    ++arr;
    return *this;
  }

  Iterator& operator--() {
    --arr;
    return *this;
  }

  Iterator operator++(int) {
    Iterator arr1(arr);
    ++arr;
    return arr1;
  }

  Iterator operator--(int) {
    Iterator arr1(arr);
    --arr;
    return arr1;
  }

  bool operator<(const Iterator rhs) { return arr < rhs.arr; }

  bool operator<=(const Iterator rhs)
  {
    return arr <= rhs.arr;
  }
  friend size_t operator-(Iterator rhs, Iterator lhs) {
    return rhs.arr - lhs.arr;
  }
  bool operator == ( const Iterator& it) { return arr == it.arr; }

  ValueType& operator*() { return *arr; }

  ValueType& operator+= (size_t c) {
    arr = arr + c;
    return *arr;
  }

  ValueType& operator-= (size_t c) {
    arr = arr - c;
    return *arr;
  }
  ValueType& operator*() const
  {
    return *arr;
  }

};
template <typename ValueType>
Iterator<ValueType> operator-(const Iterator<ValueType>& rhs, const int n)
{
  Iterator<ValueType>it(rhs);
  it -= n;
  return it;

}
template <typename ValueType>
Iterator<ValueType> operator+(const Iterator<ValueType>& rhs, const int n)
{
  Iterator<ValueType>it(rhs);
  it += n;
  return it;

}
template <typename ValueType>
bool operator>(const Iterator<ValueType>& rhs,
               const Iterator<ValueType>& lhs) {
  return !(rhs <= lhs);
}
template <typename ValueType>
bool operator>=(const Iterator<ValueType>& rhs,
                const Iterator<ValueType>& lhs) {
  return !(rhs < lhs);
}
template <typename ValueType>
bool operator!=(Iterator<ValueType>& rhs, Iterator<ValueType>& rhs1) {
  return !(rhs == rhs1);
}


#endif  // TEMPLATE_ITERATOR_H

