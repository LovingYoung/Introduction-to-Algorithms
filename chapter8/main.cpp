#include "LinearTimeSort.h"
#include <iostream>

using namespace std;

void print(int * array, int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main(){
    int countArray[10] = {19, 14, 2, 8, 1, 7, 19, 16, 3, 20};
    int * result = countsort((int*) countArray, 10, 20);
    print(result, 10);
}
