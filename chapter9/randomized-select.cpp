#include <iostream>
using namespace std;

int randomized_select(int * A, int p, int r, int i);
int randomized_partition(int * A, int p, int r);

int randomized_select(int *A, int p, int r, int i){
    if(p == r) return A[p];
    int q = randomized_partition(A, p, r);
    if(i == q) return A[q];
    if(i < q) return randomized_select(A, p, q-1, i);
    else return randomized_select(A, q+1, r, i);
}

int randomized_partition(int *A, int p, int r){
    int key = A[r];
    int left = p - 1;
    for(int i = p; i < r; i++){
        if(A[i] < key){
            left += 1;
            int temp = A[left]; A[left] = A[i]; A[i] = temp;
        }
    }
    int temp = A[left + 1]; A[left + 1] = A[r]; A[r] = temp;
    return left + 1;
}

int main(){
    int a[10] = {9, 1, 5, 3, 4, 8, 2, 7, 6, 10};
    cout << randomized_select((int*)a, 0, 9, 4) << endl;
}
