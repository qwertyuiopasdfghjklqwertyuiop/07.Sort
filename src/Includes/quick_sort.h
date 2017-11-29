#ifndef _quick_sort_h
#define _quick_sort_h

#include <vector>

namespace nonstd {

  template< typename T >
  void quick_sort(std::vector<T>& vec, int begin, int end);

  template< typename T >
  void quick_sort(std::vector<T>& vec);

//==============================================================================
  template< typename T >
  void quick_sort(std::vector<T>& vec)
  {
    srand(time(NULL));
    quick_sort<T>(vec, 0, vec.size());
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

  template< typename T >
  void quick_sort(std::vector<T>& vec, int begin, int end)
  {
    if(end - begin <= 1) return;

    // Check if array is sorted;
    for(int k=begin; ! (vec[k+1]<vec[k]); k++)
      if(k == end-2) return;

    T pivot( vec[rand() % (end-begin) + begin ] );
    int sPoint = begin;
    int ePoint = end-1;
    while(sPoint <= ePoint)
    {
      if(!(pivot < vec[sPoint])) 
      {
        //std::swap(vec[sPoint+1],vec[sPoint]);
        sPoint++;
      }
      else
      {
        std::swap(vec[sPoint], vec[ePoint]);
        ePoint--;
      }
    }
    quick_sort( vec, begin, ePoint+1 );
    quick_sort( vec, ePoint, end );
  }

}

#endif

