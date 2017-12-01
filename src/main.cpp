#include <iostream>
#include "./Includes/quick_sort.h"
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
  const int SIZE = 10000000;
  std::vector<wrapper<int>> test;

  for(int k = 0; k < SIZE; k++)
    test.push_back(wrapper<int>(rand() % 10000000));

  nonstd::quick_sort(test);

  int numWrong = 0;
  for(int k = 0; k < SIZE-1; k++)
    if(test[k] > test[k+1])
      numWrong++;
  std::cout << "Num Wrong: " << numWrong << std::endl;


  return 0;

}
