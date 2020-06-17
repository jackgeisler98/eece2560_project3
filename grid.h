//header file grid.h

#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Grid {

private: 
  unsigned g_colSize;
  unsigned g_rowSize;
  vector<vector<char> > g_grid;
  
public:
  
  Grid(unsigned, unsigned, char);
  Grid(const char *);	
  Grid(const Grid &);	//copy constructor 

  void printGrid() const;

  unsigned getRows() const {return g_rowSize;}
  unsigned getColumns() const {return g_colSize;}

  unsigned setRows(int row);
  unsigned setColumns(int columns);

  void printGrid(unsigned, unsigned);

  ~Grid();  //deconstructor
  
};

#endif