//file for declaration of template class heap

#include<iostream>
#include<vector>
#include "heap.h"

template <typename T>
class heap {

 //variables and functions only used by this class
    private:
    //for itentifying numbers in a tree
    int smallest;                                  
    int biggest;   
    int parent;

    //vector of elements to represent a tree
    vector<T> lump[size];
    int makeheap(const vector<T>){
        if (lump.left() > lump.right())             //compare two nodes
        {
            smallest = lump[1];                     //set the smaller as smallest
            biggest = lump[2];                      //set the larger as largest
        }
        else                                        //vice versa
        {
            biggest = lump[1];
            smallest = lump[2];
        }
        parent = lump.parent();
        lump[3] = {smallest, biggest, parent};      //order the vertext RLN
    }

    int parentFun(int){                             //return the parent node 
        return (smallest -1 )/2;
    }

    int left(int){                                  //return the node left of starting point
        return 2*smallest +1;
    }

    int right(int){                                 //return the node right of the starting point
        return 2*smallest +2;
    }

    int getItem(int n){                             //function to sort a head via heapsort and then searched the sorted heap for the desired variable
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
    int initMaxHeap(std::vector<int>& vect, int i, int size){   //just create a vector (already initialized because it is being refrenced
        left = vect.left(i);                                    //set the left node
        right = vect.right(i);                                  //set the right node
        size = vect.size();                                     //set the size
    }

    int maxHeapify(std::vector<int>& vect, int i, int size){
        initMaxHeap(vect[size], i, size)

        if(left < size && vect[left] > vect[right]){            //sort by the larger of the two nodes being compared
            biggest = left;                                     //the larger is on the left
        }
        else{
            biggest = right;                                    //the larger is on the right
        }
        if(right < size && vect[right] > vect[biggest]){        //opposite comparison is necessary because it is an AND statement 
            biggest = right;                                    //larger on the right this time
        }
        else{
            biggest = left;                                     //larger on the left
        }
        if(biggest != i){
            std::swap(vect[i], vect[biggest]);                  //if they are out of order swap
            maxHeapify(vect, biggest, size);                    //call the function to put nodes into heap (now that they are ordered)
        }

    }

    int buildMaxHeap(std::vector<int>& vect){
        for(int i = (vect.size())/2); i >= 0; i--) {            //using a loop, heapify each new element in the vector to build heap 
            maxHeapify(vect, i, vect.size());                   //just callig heapify function
        }
    }

    //min-heap functions same as max heap but with reversed signs 
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
    int HeapSort(std::vector<int>& vect){                       //will be based off of a maxheap 
        buildMaxHeap(vect);                                     //builds the heap, should call all necessary functions
        int size = vect.size();                                 //set the size
        for(int 1 = vect.size() -1; i > 0; i --){               //loop for heowever many elements in heap
            std::swap(vect[0], vect[i]);                        //swap components 
            size --;                                            //decrese counter
            maxHeapify(vect, 0, size);                          //use heapify function at current location hence 0
        }
    }

   
}