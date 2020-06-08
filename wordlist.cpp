
#include "wordlist.h"
using namespace std; 

Wordlist::Wordlist()
{
	//default construtor for the class wordlist
}

void Wordlist::get_words()
{
	//declare object of class fstream to open file
	ifstream finder;
	string filename = "wordlist.txt";
	k = 0; 

	//open file word.txt
	finder.open(filename);

	//check to see if file is valid
	if (!finder.is_open())
	{
		exit(EXIT_FAILURE);
	}

	//read through file and insert words into the wordlist vector
	while (finder.good())
	{
		k++;
		finder >> word; 
		list.push_back(word); 
		

	}

}

void Wordlist::insertion_sort()
{
	int j;
	for (int i = 1; i < list.size(); i++) 
	{
		//set the temp word to the beginning word of the unsorted part of the vector
		string temp = list[i];
		j = i - 1; 
		//inserts word into the correct part of the sorted vector
		while (j >= 0 && temp.length() < list[j].length())
		{
			list[j + 1] = list[j]; 
			j--; 
		}
		list[j + 1] = temp; 
	}

}
void Wordlist::merge(vector<string> vec, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low; 

	vector<string> temp; 
	while (i <= mid && j <= high)
	{
		if (vec[i].length() <= vec[j].length())
		{
			temp.push_back(vec[i]); 
			i++;
		}
		else 
		{
			temp.push_back(vec[i]);
			i++;
		}
	}
	while (i <= mid)
	{
		temp.push_back(vec[i]);
		i++;
	}
	while (i <= high)
	{
		temp.push_back(vec[i]);
		i++;
	}
	for (int s = 0; s < vec.size(); s++)
	{
		list.clear();
		list.push_back(temp[s]);
	}
}

void Wordlist::merge_sort(vector<string> vec, int low, int high)
{
	if (low < high) 
	{
		int mid = (low + high) / 2; 
		merge_sort(vec, low, mid);
		merge_sort(vec, mid + 1, high);
		merge(vec, low, mid, high);
	}
}

int Wordlist::paritition()
{
	int e = (list.size() - 1); 
	int s = 0; 
	int pivot = list[e].length(); 
	int pindex = s; 
	for (int i = s; i < e; i++)
	{
		if (list[i].length() <= pivot)
		{
			string temp = list[i];
			list[i] = list[pindex];
			list[pindex] = temp; 
			pindex++; 
		}
	}
	string temp = list[e];
	list[e] = list[pindex]; 
	list[pindex] = temp; 

	return pindex; 
}

void Wordlist::quick_sort(vector<string> vec, int start, int end)
{
	if (start < end)
	{
		int p = paritition();
		quick_sort(vec, start, (p - 1));
		quick_sort(vec, (p + 1), end);
	}
}

void Wordlist::print_wordlist()
{
	//increment through list and print out each word
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.at(i) << endl;
	}
	cout << k; 
}

int Wordlist::lookup()
 {
	string x; 
	cout << "Enter a word to be searched for: " << endl; 
	cin >> x; 
	int lower = 0;
	int upper = (list.size() -1);
	while (lower <= upper) {
		int mid = lower + (upper - lower) / 2;
		if (x == (list[mid]))
		{
			return mid;
		}
		if (x.length() > (list[mid].length()))
			lower = mid + 1;
		else
			upper = mid - 1;
	}
	return -1; 
}

Wordlist::~Wordlist()
{
	//deconstructor
}