//header file grid.h

#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <string>
using namespace std;

class Grid {

private: 
  const int n;
  int column;
  int row;
  
public:
  
  Grid(char grid [ n ][ n ]);   //constructor that initializes the grid matrix
  
  void printGrid();

  ~Grid();  //deconstructor
  
};

#endif
