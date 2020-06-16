//File for functions and classes related to searching
#include <iostream>
#include <list>
#include "findMatches.h"
#include "wordlist.h"
#include "grid.h"
using namespace std;


int findMatches(class Wordlist, class Grid) {   //inputs type class for wordlist and grid
    int row = row; int col = col; 
    int i =0; int j = 0; int k =0;                      //various loop counters 
    int rowCount = 0; int colCount = 0;
    bool found;                                          //boolean type to check if word from the grid is found in the list
    int grid[row][col];                                  //n x n grid aka matrix, search in all 8 directions, use vectors?
    string wordn;
    Wordlist Wordlist= Wordlist;                             //have wordlist to compare to
    string newWord;                                      //creating a word from grid
    string newLetter;                                    //pulling a letter from grid
    std::list<string> gridlist;                          //initialize list to store words from grid in
    std::list<string>::iterator itr = gridlist.begin();  //initialize iterator for gridlist to allow insertion

    if (row > col){int wordlength = row;}                //set the stored word length 
    else {int wordlength = col;}

    while(i<row) {                                        //checks each column iteratively 
        while(j<col){                                     //checks each row for every column

            //find all the words horizonall from start 
            while(rowCount <= row) {
                newLetter = grid[rowCount][col];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add the new string to the new word list 
                rowCount = rowCount + 1;        
                //if statement to allow for wrapping around
                if (rowCount > row){rowCount = 0;}
            }

            //find all the words vertically from start
            while(colCount <= col){
                newLetter = grid[row][colCount];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add new word to new list
                colCount = colCount + 1;
                //if statment to allow for wrapping around
                if (colCount > row){colCount = 0;}
            }

            //find all the words diagonally from start 
            while(rowCount <= row && colCount < col) {
                newLetter = grid[rowCount][colCount];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add new word to new list 
                rowCount = rowCount + 1;
                colCount = colCount + 1;
                //if statement to allow for wrapping around
                if (rowCount > row){rowCount = 0;}
                if (colCount > row){colCount = 0;}
            }
            j = j +1;
        }
        i = i+1;
    }
    while(k < gridlist.length()){                   //compare to the wordlist
        wordn = gridlist(k);
        found = Wordlist.lookup(wordn);      //check to see if the word in gridlist is found in wordlist
        if(!found){
        gridlist.remove(wordn);                         //remove any words not found in wordlist from gridlist
        }
        k = k+1;                                    //next word to look up
    }

    //output girdlist                                          
    cout << "List of words from WrodList found in Grid:";
    for(list<string>::iterator it = gridlist.begin(); it != gridlist.end(); it ++)
        cout << *it << " ";
    cout << endl;                                                                                          
}