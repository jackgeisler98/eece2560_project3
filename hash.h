#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include "wordlist.h"
using namespace std; 

#ifndef HASH_H
#define HASH_H


class Hash
{
private:
	//declare size of hash table
	static const int tablesize = 2310;
	//create node struct for the table buckets
	struct bucket
	{
		string word;
		bucket* next; 
	};

	bucket* HashTable[tablesize];

public:
	//constructor function that sets values of table to null
	Hash(); 
	//function that converts a string var into a integer value
	int Hashkey(string key);
	//function to add word to the table
	void AddItem(string word);
	//function to look up words in the table
	void inList(string word);
	//function to delete word from the table
	void DeleteItem(string word); 

};