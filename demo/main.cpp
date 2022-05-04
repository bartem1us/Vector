
// Copyright 2021 Filkov VA filkovghjynj123@mail.ru
#include "Iterator.h"
#include "vector.h"
int main()
{
  vector<int> vec(5, 5);  // check constructor
  vec[1] = 1;
  vec[2] = 2;
  vec[3] = 3;             // check []
  auto it = vec.begin();  // check begin + iterator const
  std::cout << "Должны получить : " << 5 << " Получили : " << *it << std::endl;
  std::cout << "Должны получить : " << 2 << " Получили : " << vec[2] << std::endl;
  ++it;
  std::cout << "Должны получить : " << 1 << " Получили : " << *it << std::endl;
  it++;
  std::cout << "Должны получить : " << 2 << " Получили : " << *it << std::endl;
  --it;
  std::cout << "Должны получить : " << 1 << " Получили : " << *it << std::endl;
  it--;
  std::cout << "Должны получить : " << 5 << " Получили : " << *it << std::endl;
  auto it2 = it;
  std::cout << "Должны получить : " << 5 << " Получили : " << *it2 << std::endl;
  bool expect = it2 == it;
  bool expect2 = it2 != it;
  std::cout << "Должны получить : " << 1 << " Получили : " << expect << std::endl;
  std::cout << "Должны получить : " << 0 << " Получили : " << expect2 << std::endl;

  vector<int> vec2(4, 4);
  vector<int> vec3(vec2);

  size_t size2 = vec2.size();
  std::cout << "Должны получить : " << 4 << " Получили : " << size2 << std::endl;
  bool empty=vec2.empty();
  std::cout << "Должны получить : " << 0 << " Получили : " << empty << std::endl;
  vec2.push_back(3);
  int rv = vec2[4];
  std::cout << "Должны получить : " << 3 << " Получили : " << rv << std::endl;
  std::cout << "Должны получить : " << 4 << " Получили : " << vec2.front() << std::endl;
  std::cout << "Должны получить : " << 3 << " Получили : " << vec2.back() << std::endl;
  vec2.swap(vec3);
  std::cout << "Должны получить : " << 3 << " Получили : " << vec3.back() << std::endl;
  vector<int> vector(4, 4);
  vector.clear();
  empty = vector.empty();
  std::cout << "Должны получить : " << 1 << " Получили : " << empty << std::endl;
  return 0;
}