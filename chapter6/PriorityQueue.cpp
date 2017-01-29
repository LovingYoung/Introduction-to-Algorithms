#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main(){
    PriorityQueue q(20);
    q.Insert(10);
    q.Insert(5);
    q.Insert(30);
    q.Insert(20);
    q.Insert(100);
    q.Insert(27);
    while(q.getSize() != 0){
        cout << q.Extract_max() << ' ';
    }
    cout << endl;
}
