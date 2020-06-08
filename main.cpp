//Main file for Project 3
//Michael Gesuale, Jack Geisler, & Vanessa Hadlock
//June 4th, 2020

#include <iostream>
#include <fstream>
using namespace std;

class Grid {
  
    int n = 15;         //set n equal to the dimensions of the matrix (grid) 
  
    char grid[n][n];    //create a matrix characters called grid of size n x n
  
    ifstream input;     //declare an input file stream (ifstream) variable called input
  
    int column = 0;     //initialize column to 0 to start
    int row = 0;        //initialize row to 0 to start
  
    input.open("File.txt", ios::in);  //opens the file of letters
 
    if (inFile.fail()) {

      cerr << "Error in Uploading the grid of letters!" << endl;
        exit(1);
    }
  
    input >> column >> row;

    for (int column_counter = 0; column_counter < column; column_counter++){

        for (int row_counter = 0; row_counter < row; row_counter++){

            input >> grid[column_counter][row_counter];

        }
    }
  
    input.close();
  
    for(int i = 0; i < n; i++) {
      
      for(int j = 0; j < n; j++) {
          
        cout<< grid[i][j] << " " << endl;
        cout<<endl;
    }
  
};
