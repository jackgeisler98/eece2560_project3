//Include global function search(int) and main function

#include "wordlist.h"
#include "findMatches.h"
#include "grid.h"
#include <bits/stdc++.h>
using namespace std;
 
/* Global function search(int algo) which reads the name of the grid file from the keyboard based on user input
 * and calls findMatches(wordlist, grid) to print out all words from the word list that can be found in the grid.
 * The function also prints out the CPU time to sort the words, the CPU time to find the words, and the total
 * time to run the program. The integer parameter is used to select the sorting algorithm that is ran.
 *  
 * @param       int algo - the choice of algorithm to use, chosen by the user
 * @return      none
 */	
 
void search(int algo) { 
  
  clock_t start, end;
  
  //Recording the starting tick of running the whole program
  start = clock(); 
  
  string textFile;
  
 /* clock_t clock(void) returns the number of clock ticks elapsed since the program was launched. To get the number  
    of seconds used by the CPU, you will need to divide by CLOCKS_PER_SEC, where CLOCKS_PER_SEC is 1000000 on typical 
    32 bit system.
  */
  clock_t sortStart, sortEnd, searchStart, searchEnd;
  
  //Reading in the name of the grid file from the user input 
  cout << "What is the name of the grid file like to find words from? Please include the .txt extension: " << endl;
  
  //saving this as the name of the textfile
  cin >> textFile; 

  //Wordlist object 
  Wordlist word;
  
  //Grid object
  Grid grid;
  
  //if the user chose to use algorithm 1, then run the insertion_sort() function on the Wordlist 
  if (algo = 1) { 
      
    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    word.insertion_sort();
    
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  //if the user chose to use algorithm 2, then run the quick_sort() function on the Wordlist 
  else if (algo = 2) { 

    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    word.quick_sort(param);
    
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  //if the user chose to use algorithm 3, then run the merge_sort() function on the Wordlist 
  else {

    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    word.merge_sort(param);
  
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  
  //Recording the starting clock tick for the findMatches() algorithm to search for the matching words in the grid
  searchStart = clock(); 
  
  //prints out all words from the word list that can be found in the grid
  findMatches(word, grid);
  
  //Recording the ending clock tick
  searchEnd = clock(); 
  
  //Recording the ending tick of running the whole program
  end = clock();
  
  // Calculating total time taken by the program to sort 
  double sortTime = double(Sortend - Sortstart) / double(CLOCKS_PER_SEC); 
  
  // Calculating total time taken by the program to search 
  double searchTime = double(searchEnd - searchStart) / double(CLOCKS_PER_SEC);
  
  //Calculating the total time of the whole program
  double totalTime = double(end - start) / double(CLOCKS_PER_SEC); 
    
  cout << "CPU Time to Sort the Words: " << sortTime << setprecision(5) << " sec " << endl;
  cout << "CPU Time to Find the Words: " << searchTime << setprecision(5) << " sec " << endl;
  cout << "The Total Time is: " << totalTime << setprecision(5) << " sec " << endl;
  
};