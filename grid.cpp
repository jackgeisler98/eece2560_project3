//Grid Class file for Project 3
//Michael Gesuale, Jack Geisler, & Vanessa Hadlock
//June 4th, 2020

#include<iostream>
#include<fstream>
#include<string>
#include "grid.h"
using namespace std;

Grid::Grid() {

    ifstream inFile("input15.txt"); //opens the file of letters

    if (!inFile) {
        
        cout << "Unable to open file the letter text file";
        exit(1);   // call system to stop
    }

//read the first number in the first line in order to get the size of the grid
    int sLine;

    n >> sLine;
    
    column = 0;     //initialize column to 0 to start
    row = 0;        //initialize row to 0 to start
  
    inFile >> column >> row;

    grid[ n ][ n ] = {};        //create a matrix characters called grid of size n x n

    for(int column_counter = 1; column_counter < column; column_counter++) {

        for (int row_counter = 1; row_counter < row; row_counter++) {

            inFile >> grid[column_counter][row_counter];

        }
    }
    
    inFile.close();
}


void Grid::printGrid(const int size) {
  
    for(int i = 0; i < size; i++) {
      
        for(int j = 0; j < size; j++) {
          
        cout<< grid[i][j] << " ";
        
        }
        cout<<endl;
    }
    cout<<endl;
}