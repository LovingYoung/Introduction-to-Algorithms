#ifndef JACE_HEAP
#define JACE_HEAP

class Heap{
public:
    static const int MAXHEAP = 1;
    static const int MINHEAP = 2;

public:
    Heap(int* array, int length, int type=MAXHEAP){
        this->array = array;
        this->length = length;
        this->type = type;
        if(type == MAXHEAP) BuildMaxHeap(length);
        else BuildMinHeap(length);
    }

    void sort(){
        for(int len = length - 1; len >= 1; len--){
            array[0] ^= array[len];
            array[len] ^= array[0];
            array[0] ^= array[len];
            if(type == MAXHEAP) BuildMaxHeap(len);
            else BuildMinHeap(len);
        }
    }

private:
    int* array;
    int length;
    int type;

private:
    void MaxHeapify(int index, int heapsize){
        int left_index = Left(index);
        int right_index = Right(index);
        int largest = index;
        if(left_index < heapsize && array[left_index] > array[largest]){
            largest = left_index;
        }
        if(right_index < heapsize && array[right_index] > array[largest]){
            largest = right_index;
        }
        if(largest != index){
            array[index] ^= array[largest];
            array[largest] ^= array[index];
            array[index] ^= array[largest];
            MaxHeapify(largest, heapsize);
        }
    }

    void MinHeapify(int index, int heapsize){
        int left_index = Left(index);
        int right_index = Right(index);
        int smallest = index;
        if(left_index < heapsize && array[left_index] < array[smallest]){
            smallest = left_index;
        }
        if(right_index < heapsize && array[right_index] < array[smallest]){
            smallest = right_index;
        }
        if(smallest != index){
            array[index] ^= array[smallest];
            array[smallest] ^= array[index];
            array[index] ^= array[smallest];
            MinHeapify(smallest, heapsize);
        }
    }

    void BuildMaxHeap(int heapsize){
        if(heapsize < 3) MaxHeapify(0, heapsize);
        else for(int last = (heapsize- 1) / 2; last >= 0; last --){
            MaxHeapify(last, heapsize);
        }
    }

    void BuildMinHeap(int heapsize){
        if(heapsize < 3) MinHeapify(0, heapsize);
        else for(int last = (heapsize - 1) / 2; last >= 0; last--){
            MinHeapify(last, heapsize);
        }
    }

    inline int Left(int index){
        return 2 * index + 1;
    }

    inline int Right(int index){
        return 2 * index + 2;
    }

    inline int Parent(int index){
        return (index - 1) / 2;
    }
};

#endif

