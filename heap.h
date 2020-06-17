//file for declaration of template class heap

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class heap {

    //variables and functions only used by this class
    private:

    vector<T> lump;

    int makeheap(const vector<T>);

    int parent(int);

    int left(int);

    int right(int);

    int getitem(int n);

    public:
    //variables used in the public functions
    int left; 
    int right;
    int size;
    int smallest;
    int biggest;
    int parent;
    //max-heap functions
    int initMaxHeap();

    int maxHeapify();

    int buildMaxHeap();

    //min-heap functions
    int initMinHeap();

    int minHeapify();

    int buildMinHeap();

    //main sorting algo for heap
    int HeapSort();
};
