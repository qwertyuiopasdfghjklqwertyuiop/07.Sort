#ifndef _merge_sort_h
#define _merge_sort_h

#include <vector>
namespace nonstd {

  template< typename T >
  void merge_sort(std::vector<T>& vec);

  template< typename T >
  void mergeSort(int begin, int end, std::vector<T>& orig, std::vector<T>& buffer);

  template< typename T >
  void merge_helper(int begin1, int end1, int begin2, int end2, const std::vector<T>&orig, std::vector<T>& buffer);

//==============================================================================

  template< typename T >
  void merge_sort(std::vector<T>& vec)
  {
    std::vector<T> buffer;
      // Resize without calling default contructor
    buffer.insert( buffer.end(), vec.begin(), vec.end() );

    mergeSort<T>(0,vec.size(),vec,buffer);
  }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  template< typename T >
  void mergeSort(int begin, int end, std::vector<T>& orig, std::vector<T>& buffer)
  {
    int halfSize = (end - begin)/2;
    if(halfSize == 0) return;

    for(int k = begin; !(orig[k+1] < orig[k]); k++)
      if(k == end-2) return;

    mergeSort(begin, end-halfSize, orig, buffer);
    mergeSort(end-halfSize, end, orig, buffer); 

    merge_helper<T>(begin, end-halfSize, end-halfSize, end, orig, buffer);
    for(int k = begin; k < end; k++)
      orig[k] = buffer[k];
  }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  template< typename T >
  void merge_helper(int begin1, int end1, int begin2, int end2, const std::vector<T>&orig, std::vector<T>& buffer)
  {
    int bufferPos = begin1;
    
    // Sort into buffer
    for( ; begin1 < end1 && begin2 < end2; bufferPos++ )
    {
      if(!(orig[begin2] < orig[begin1]))
      {
        buffer[bufferPos] = orig[begin1];
        begin1++;
      }
      else
      {
        buffer[bufferPos] = orig[begin2];
        begin2++;
      }
    }

    // Dump whatever is left over.  Only one loop should run.
    while(begin1 < end1)
    {
      buffer[bufferPos] = orig[begin1];
      bufferPos++;
      begin1++;
    }
    while(begin2 < end2)
    {
      buffer[bufferPos] = orig[begin2];
      bufferPos++;
      begin2++;
    }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  }

}



#endif

