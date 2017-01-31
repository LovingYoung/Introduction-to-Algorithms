#include "LinearTimeSort.h"
#include <iostream>

using namespace std;

void print(int * array, int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}

void print(double * array, int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main(){
    int countArray[10] = {19, 14, 2, 8, 1, 7, 19, 16, 3, 20};
    int * result = countsort((int*) countArray, 10, 20);
    print(result, 10);
    double bucketArray[10] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    double * result2 = bucketsort((double*) bucketArray, 10); 
    print(result2, 10);
}
