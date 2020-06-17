//Grid.cpp for Project 3
//June 4th, 2020

#include<iostream>
#include<fstream>
#include<string>
#include"grid.h"
using namespace std;


/* First Grid constructor that takes in the number of rows, the number of columns,
 * and the initla value of each cell, which is changed later on.
 * @param   unsigned rowSize, unsigned colSize, char initial (the initial value of
 * each cell that is changed later once the file is opened.
 * @return  none
 */
Grid::Grid(unsigned rowSize, unsigned colSize, char initial) {

    g_rowSize = rowSize;    //assign the class member to inputted number of rows
    g_colSize = colSize;    //assign the class member to inputted number of columns
    g_grid.resize(rowSize); //resize the vector's row size with the inputted row size

    //for loop iterates over the vector size and resizes it to the column number
    for (unsigned i = 0; i < g_grid.size(); i++) {

        g_grid[i].resize(colSize, initial);
    }

}

/* Second Grid constructor that pulls values from the txt file and creates a matrix class 
 * out of it.
 * @param   char *fileName, a character pointer that presents the txt file name to open
 * @return  none
 */

Grid::Grid(const char * fileName) {

    ifstream file_A(fileName); //input file stream to open the file_A called fileName

    //Keeps track of the sizes of the Columns and the rows
    int colSize = 0;
    int rowSize = 0;

    //reads the file in as a vector string
    string line_A;
    int idx = 0;
    char element_A;
    char *vector_A = nullptr;

    //checks to see if the file opens sucessfully 
    if (file_A.is_open() && file_A.good()) {
    
        //while loop that reads the file in as a vector spring and separates it into elements
        //using temporary arrays
        while (getline(file_A, line_A)) {
            
            //increases the number of rows by 1
            rowSize += 1;
            stringstream stream_A(line_A);
            colSize = 0;

            while(1) {
            
                stream_A >> element_A;
                
                //breaks the while loop if the element does not set properly
                if (!stream_A)
                    break;
                //increases the number of columns by 1
                colSize += 1;
                
                //creates a temporary character array in order to increase the index of the 
                char *tempArr = new char[idx + 1];
                copy(vector_A, vector_A + idx, tempArr);
                //puts the current index of the temporary array into the element_A position
                tempArr[idx] = element_A;
                
                vector_A = tempArr;
                idx += 1;
            }
        }
    }
    else {
        //if the file fails to open sucessfully
        cout << "Sorry, the file failed to open!" << endl;
    }

    idx = 0;    //index of the vector, initially starts at 0 
    
    g_grid.resize(rowSize); //resizes the grid based on the number of rows
    
    //for loop that iterates through the size of the grid in order to resize based on
    //the number of columns
    for (unsigned i = 0; i < g_grid.size(); i++) {
        g_grid[i].resize(colSize);
    }
    
    //nested for loop that iterates through the rows and the columns in order to push each 
    //character from the vector into the grid based on the vector index 
    for (int i = 0; i < rowSize; i++) {
       
        for (int j = 0; j < colSize; j++) {
            
            this->g_grid[i][j] = vector_A[idx];
            idx++;
        }
    }
    
    //sets the final size of the columns in the grid
    g_colSize = colSize;
    
    //sets the final size of the rows in the grid
    g_rowSize = rowSize;
    
    delete [] vector_A; // Tying up loose ends

    file_A.close(); //closes the file once completed
}

/* function to print the grid that takes in the number of columns and rows and runs a
 * nested for loop in order to print each index of the grid matrix
 * @param   unsigned colSize, unsigned rowSize
 * @return  none
 */
void Grid::printGrid(unsigned colSize, unsigned rowSize) {
  
    for(int i = 0; i < colSize; i++) {
      
        for(int j = 0; j < colSize; j++) {
          
        cout<< g_grid[i][j] << " ";
        
        }

        cout<<endl;
    }

    cout<<endl;
}