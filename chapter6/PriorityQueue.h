#ifndef JACE_PRIORITY_QUEUE
#define JACE_PRIORITY_QUEUE

#include "Heap.h"
#include <climits>

class PriorityQueue: public Heap{
public:
    PriorityQueue(int* array, int length, bool type=Heap::MAXHEAP): Heap(array, length, type){

    }

    PriorityQueue(int n, bool type=Heap::MAXHEAP):Heap(n, type){

    }

    int Maximum(){
        return array[0];
    }

    int Extract_max(){
        int maximum = array[0];
        array[0] = array[length - 1];
        length--;
        MaxHeapify(0, length);
        return maximum;
    }

    void Increase_key(int index, int key){
        if(key <= array[index]){
            return;
        }
        array[index] = key;
        while(index > 0 && array[Parent(index)] < array[index]){
            array[Parent(index)] ^= array[index];
            array[index] ^= array[Parent(index)];
            array[Parent(index)] ^= array[index];
            index = Parent(index);
        }
    }

    void Insert(int key){
        length = length + 1;
        array[length - 1] = INT_MIN;
        Increase_key(length - 1, key);
    }

    int getSize() {
        return length;
    }
};

#endif
