#include "hash.h"
#include "wordlist.h"
using namespace std; 

Hash::Hash()
{
	for (int i = 0; i < tablesize; i++)// initialize all buckets of the array as empty
	{
		HashTable[i] = new bucket; 
		HashTable[i]->word = "empty"; 
		HashTable[i]->next = NULL; 
	}
}

int Hash::Hashkey(string key) 
{
	int hash = 0; 
	int index;

	//for loop that adds up the ASCI values of the string
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	//returns the index as the remainder of hash value by the size of the list
	index = hash % tablesize; 
	return index; 

}

void Hash::AddItem(string name)
{
	int index = Hashkey(name); //create index number for the word passed to the function
	if (HashTable[index]->word == "empty")//handle insertion for no collision
	{
		HashTable[index]->word = name;
	}
	else//if there is a collision add the bucket to the end of the linked list
	{
		bucket* ptr = HashTable[index]; 
		bucket* n = new bucket; 
		n->word = name; 
		n->next = NULL; 
		while (ptr->next != NULL)
		{
			ptr = ptr->next; 
		}
		ptr->next = n; 
	}
}

void Hash::inList(string word) 
{
	int index = Hashkey(word);
	bool foundword = false; 

	bucket* ptr = HashTable[index]; //check to see if word at index matches key
	while (ptr != NULL) //increment through the index linked list
	{
		if (ptr->word == word)
		{
			foundword = true;
		}
		ptr = ptr->next;
	}
	if (foundword = true) //bool statements if the words match/do not match
	{
		cout << "WORD FOUND AT INDEX " << index << endl; 
	}
	else
	{
		cout << "WORD NOT FOUND IN TABLE";
	}
}

void Hash::DeleteItem(string word)
{
	int index = Hashkey(word); //set index equal to the words index we want to delete
	bucket* delptr;


	if (HashTable[index]->word == "empty")//case if bucket index is not filled
	{
		cout << "word not found" << endl; 
	}
	else if (HashTable[index]->word == word && HashTable[index]->next == NULL)//case if bucket matches with word and there is no linked list
	{
		HashTable[index]->word = "empty"; 
	}
	else if (HashTable[index]->word == word)//case if there is linked list at index
	{
		delptr = HashTable[index]; 
		HashTable[index] = HashTable[index]->next;//set index to the next value in the linked list
		delete delptr; //delete the value at the index
	}

}