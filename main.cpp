//Main file for project 3
#include "wordlist.h"
#include "findMatches.h"
#include "grid.h"
using namespace std;

int main()
{
	Wordlist wordlist; 
	Grid grid;
	wordlist.get_words();
	wordlist.insertion_sort();

	int result = wordlist.lookup();
	if (result == -1)
		cout << ("Element not present");
	else
		cout << ("Element found at index ") << result;

	findMatches(wordlist, grid);

}