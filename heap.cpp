//file for declaration of template class heap

#include<iostream>
#include<vector>
#include "heap.h"

template <typename T>
class heap {

 //variables and functions only used by this class
    private:

    int smallest;
    int biggest;
    int parent;

    vector<T> lump[size];
    int makeheap(const vector<T>){
        if (lump.left() > lump.right())
        {
            smallest = lump[1];
            biggest = lump[2];
        }
        else
        {
            biggest = lump[1];
            smallest = lump[2];
        }
        parent = lump.parent();
        lump[3] = {smallest, biggest, parent}; 
    }

    int parentFun(int){
        return (smallest -1 )/2;
    }

    int left(int){
        return 2*smallest +1;
    }

    int right(int){
        return 2*smallest +2;
    }

    int getItem(int n){
        size = vect.size();
        int n = n;
        initMaxHeap(vect , n, size);
        maxHeapify(vect, n, size);
        buildMaxHeap(vect, n, size);
        heapSort(vect);
        return vect.search(n);
    }


    public:
    //variables used in the public functions
    int left; 
    int right;
    int size;
    int smallest;
    int biggest;
    int parent;
   
    //max-heap functions
    int initMaxHeap(std::vector<int>& vect, int i, int size){
        left = vect.left(i);
        right = vect.right(i);
        size = vect.size();
    }

    int maxHeapify(std::vector<int>& vect, int i, int size){
        initMaxHeap(vect[size], i, size)

        if(left < size && vect[left] > vect[right]){
            biggest = left;
        }
        else{
            biggest = right;
        }
        if(right < size && vect[right] > vect[biggest]){
            biggest = right;
        }
        else{
            biggest = left;
        }
        if(biggest != i){
            std::swap(vect[i], vect[biggest]);
            maxHeapify(vect, biggest, size);
        }

    }

    int buildMaxHeap(std::vector<int>& vect){
        for(int i = (vect.size())/2); i >= 0; i--) {
            maxHeapify(vect, i, vect.size());
        }
    }

    //min-heap functions
    int initMinHeap(std::vector<int>& vect, int i, int size){
        left = vect.left(i);
        right = vect.right(i);
        size = vect.size();
    }

    int minHeapify(){
        left = vect.left(i);
        right = vect.right(i);

        if(left > size && vect[left] < vect[right]){
            biggest = left;
        }
        else{
            biggest = right;
        }
        if(right > size && vect[right] < vect[biggest]){
            biggest = right;
        }
        else{
            biggest = left;
        }
        if(biggest != i){
            std::swap(vect[i], vect[biggest]);
            minHeapify(vect, biggest, size);
        }
    }

    int buildMinHeap(){
        for(int i = (vect.size())/2); i >= 0; i--) {
            minHeapify(vect, i, vect.size());
    }

    //main sorting algo for heap
    int HeapSort(std::vector<int>& vect){
        buildMaxHeap(vect);
        int size = vect.size();
        for(int 1 = vect.size() -1; i > 0; i --){
            std::swap(vect[0], vect[i]);
            size --;
            maxHeapify(vect, 0, size);
        }
    }

   
}