#ifndef JACE_LINEAR_TIME_SORT
#define JACE_LINEAR_TIME_SORT

#include <cstdlib>
#include <cstring>

/*
 * variable "array" is the array being sorted. Elements in this array should be all nonnegative numbers.
 * variable "n" is the length of the array
 * variable "k" is the upper bound of the values in array.
 * return a pointer to the sorted array.
 */
int * countsort(int * array, int n, int k){
    int * result = (int*) malloc (n * sizeof(int));
    int * temp = (int*) malloc ((k+1) * sizeof(int));
    memset(temp, 0, (k+1) * sizeof(int));

    for(int i = 0; i < n; i++){
        temp[array[i]] += 1;
    }

    for(int i = 1; i <= k; i++){
        temp[i] += temp[i-1];
    }

    for(int i = n - 1; i >= 0; i--){
        result[temp[array[i]] - 1] = array[i];
        temp[array[i]] -= 1;
    }

    return result;
}

#endif
