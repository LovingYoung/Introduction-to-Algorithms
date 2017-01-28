#include "Heap.h"
#include <iostream>

using namespace std;

int main(){
    int test[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 100};
    Heap * heap = new Heap((int*) test, 10, Heap::MINHEAP);
    heap -> sort();
    delete heap;
    for(int i = 0; i < 10; i++) cout << test[i] << ' ';
    cout << endl;
}
