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

    T& pivot( vec[(end-begin)/2 + begin] );  //Placeholder

    // Pivot is median of begin, end, and middle between them
    if((vec[begin] < vec[end-1]) != (vec[begin] < vec[(end-begin)/2 + begin]))
      pivot = vec[begin];
    else if((vec[(end-begin)/2 + begin] < vec[begin]) != (vec[(end-begin)/2 + begin] < vec[end-1]))
      pivot = vec[(end-begin)/2 +begin];
    else
      pivot = vec[end-1];


    int sPoint = begin;
    int ePoint = end-1;
    while(sPoint <= ePoint)
    {
      if(!(pivot < vec[sPoint])) 
      {
        sPoint++;
      }
      else
      {
        std::swap(vec[sPoint], vec[ePoint]);
        ePoint--;
      }
    }
    quick_sort( vec, begin, ePoint );
    quick_sort( vec, ePoint-1, end );
  }

}

#endif

