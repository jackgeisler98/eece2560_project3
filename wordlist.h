//header file for the class wordlist in project 3

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

//define wordlist header
#ifndef WORDLIST_H
#define WORDLIST_H

class Wordlist
{
private:
	//vector of strings to hold the words
	 
	//value to record number of elements in the wordlist vector
	int k;
	//array of char to store words as program is reading in from file
	char word[50];

public:
	vector<string> list;
	//default constructor
	Wordlist();
	//function to import word list from a txt file
	void get_words();
	//function to print list of words
	void print_wordlist();
	//function that sorts the list using inssertion sort
	void insertion_sort();
	//function used by mergesort to merge two halves of a vector
	void merge(vector<string> vec, int low, int mid, int high);
	//function that sorts the list using mergesort
	void merge_sort(vector<string> vec, int low, int high);
	//function paritition used in the recursive call of quick sort
	int paritition();
	//function that sorts the list using quicksort
	void quick_sort(vector<string> vec, int s, int e);
	//function that looks up a word using binary sort function will return the int index if word is found
	//and return -1 if not found
	int lookup();
	//deconstructor
	~Wordlist();
};

#endif