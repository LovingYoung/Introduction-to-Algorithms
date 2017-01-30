#ifndef JACE_QUICKSORT
#define JACE_QUICKSORT

int partition(int* array, int left, int right){
    int key = array[right];
    int i = left;
    for(int j = i; j < right; j++){
        if(array[j] < key){
            if (array[i] != array[j]) {
                array[j] ^= array[i];
                array[i] ^= array[j];
                array[j] ^= array[i];
            }
            i += 1;
        }
    }
    if(array[i] != array[right]){
        array[i] ^= array[right];
        array[right] ^= array[i];
        array[i] ^= array[right];
    }
    return i;
}

void quicksort(int * array, int left, int right){
    if(left < right){
        int p = partition(array, left, right);
        quicksort(array, left, p - 1);
        quicksort(array, p + 1, right);
    }
}

void quicksort(int * array, int n){
    quicksort(array, 0, n - 1);
}

#endif
