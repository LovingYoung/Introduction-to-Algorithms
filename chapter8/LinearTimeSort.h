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

struct ListNode{
    double val;
    ListNode * next;

    ListNode(){
        next = NULL;
    }

    ListNode(double value): val(value), next(NULL){};
};

void addElement(ListNode* &node, double value){
    if(node == NULL){
        node = new ListNode(value);
    } else addElement(node->next, value);
}

ListNode * quicksort(ListNode * start){
    if(start == NULL) return NULL;
    ListNode * left = NULL;
    ListNode * left_end = NULL;
    ListNode * right = NULL;
    ListNode * right_end = NULL;
    double key = start->val;
    ListNode * p = start->next;
    while(p != NULL){
        ListNode * current = p;
        p = p->next;
        current->next = NULL;
        if(current->val<= key){
            if(left_end == NULL){
                left_end = left = current;
            } else {
                left_end->next = current;
                left_end = current;
            }
        } else {
            if(right_end == NULL){
                right_end = right = current;
            } else {
                right_end->next = current;
                right_end = current;
            }
        }
    }
    if(left != NULL) left = quicksort(left);
    if(right != NULL) right = quicksort(right);
    ListNode * result;
    if(left != NULL){
        result = left;
        while(left -> next != NULL) left = left->next;
        left->next = start;
    } else {
        result = start;
    }
    start->next = right;
    return result;
}

double * bucketsort(double * array, int n){
    ListNode* temp[n];
    memset(temp, NULL, n * sizeof(ListNode*));
    for(int i = 0; i < n; i++){
        int loc = n * array[i];
        addElement(temp[loc], array[i]);
    }
    for(int i = 0; i < n; i++){
        temp[i] = quicksort(temp[i]);
    }
    double * result = (double*) malloc (sizeof(double) * n);
    int l = 0;
    for(int i = 0; i < n; i++){
        while(temp[i] != NULL){
            result[l] = temp[i]->val;
            l += 1;
            temp[i] = temp[i] -> next;
        }
    }
    return result;
}

#endif
