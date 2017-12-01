#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "./Includes/merge_sort.h"
#include "./Includes/quick_sort.h"

int main( const int ooga, const char** booga ) {
  if( ooga != 3 ) { std::cerr << "Specify parameters you fucking faggot.\nlength type{ random, reverse, sorted, unique, nunique }\n"; exit(1); }

  srand(time(NULL));

  std::vector<int> dooga;
  const int MAX_ELEMENT_SIZE = 1'000'000;
  const int LENGTH = std::stoi(booga[1]);
  const std::string TYPE = booga[2];
  if(TYPE != "unique" && TYPE != "nunique") dooga.resize(LENGTH);

  if( TYPE == "random" )
    for(int k = 0; k < LENGTH; k++)
      dooga[k] = rand() % MAX_ELEMENT_SIZE+1 ;

  else if( TYPE == "reverse" )
    for (int k = LENGTH; k > 0; k--)
      dooga[LENGTH-k] = k;

  else if( TYPE == "sorted" )
    for (int k = 0; k < LENGTH; k++)
      dooga[k] = k;

  else if( TYPE == "unique" )
    for (; dooga.size() < LENGTH;)
    {
      bool dupe = false;
      int temp = rand() % MAX_ELEMENT_SIZE+1;
      if(dooga.size() == 0) dooga.push_back(temp);
      for(std::vector<int>::iterator iter = dooga.begin(); iter != dooga.end(); iter++)
      {
        if( *iter == temp ) {
          dupe = true;
          break;
        }
      if( !dupe )
        dooga.push_back( temp );
      }
    }

  else if( TYPE == "nunique" )
  {
    for(int k = 0; k < LENGTH/2; k++)
    {
      int temp = rand() % MAX_ELEMENT_SIZE;
      dooga.push_back( temp );
      dooga.push_back( temp );
    }
    random_shuffle( dooga.begin(), dooga.end() );
  }
  else 
  {
    std::cerr << "Wrong type retard." << std::endl;
    exit(2);
  }

  std::vector<int> shooga(dooga);
  std::cout << "====================== B E F O R E ====================================\n";
  for ( int k = 0; k < dooga.size(); k++ )
  {
    std::cout << dooga[k] << ", ";
    if((k+1) % 20 == 0) std::cout << '\n';
  }
  std::cout << std::endl;
  std::cout << "======================= R E S U L T S =================================\n";
  time_t START_TIME = time(NULL);
  nonstd::quick_sort<int>(dooga);
  std::cout << "( " << LENGTH << ", " << time(NULL) - START_TIME << ", QUICK SORT )" << std::endl;

  START_TIME = time(NULL);
  nonstd::merge_sort<int>(shooga);
  std::cout << "( " << LENGTH << ", " << time(NULL) - START_TIME << ", MERGE SORT )" << std::endl;
  std::cout << "======================== A F T E R ====================================\n";
  for ( int k = 0; k < dooga.size(); k++ )
  {
    std::cout << dooga[k] << ", ";
    if((k+1) % 20 == 0) std::cout << '\n';
  }
  std::cout << std::endl << std::endl;


  return 0;
}
