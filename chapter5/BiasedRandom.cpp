/*
 * Problem 5.1-3
 * Generate 2 numbers a and b. if a is 0 and b is 1, return 0; if a is 1 and b is 0, return 1. else try again;
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int biased_random_0_1(double p){
    p = 1 - p;
    int answer = rand();
    if(answer <= RAND_MAX * p) return 0;
    else return 1;
}

int Random(){
    srand(time(0));
    while(true){
        int a = biased_random_0_1(0.2);
        int b = biased_random_0_1(0.2);
        if(a == 0 && b == 1) return 0;
        if(a == 1 && b == 0) return 1;
    }
}

int main(){
    int result = Random();
    cout << result << endl;
    return 0;
}
