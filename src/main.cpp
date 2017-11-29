#include <iostream>
#include "./Includes/merge_sort.h"

template< typename T >
struct wrapper {
  wrapper(const T input) : var(input) { }
  T var;
  bool operator<(const wrapper<T>& other)const { return this->var<other.var; }
  bool operator>(const wrapper<T>& other) const { return this->var > other.var; }
  bool operator<=(const wrapper<T>& other) const { return this->var<=other.var; }
};


int main() {
  srand( time(NULL) );
  const int SIZE = 1*1000*1000;
  std::vector<wrapper<int>> test;

  for(int k = 0; k < SIZE; k++)
    test.push_back(wrapper<int>(rand() % 1*1000*100));

  nonstd::sort(test);

  for(int k = 0; k < SIZE-1; k++)
    if(test[k] > test[k+1])
      std::cout << "NO"  << std::endl;


  return 0;

}
