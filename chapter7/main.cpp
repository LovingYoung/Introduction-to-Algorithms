#include "QuickSort.h"
#include <iostream>

using namespace std;

int main(){
    int array[10] = {9, 1, 2, 6, 3, 0, 7, 10, 31, 20};
    quicksort((int*) array, 10);
    for(int i = 0; i < 10; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}
