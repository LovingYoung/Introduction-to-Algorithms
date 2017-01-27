/*
 * Problem 5.1-2
 *
 * Random(a, b) can be impolemented as calling Random(0, 1) for (b - a) times
 * Expected Running Time: O(b - a)
 *
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int random_0_1(){
    return rand() % 2;
}

int random(int a, int b){
    srand(time(0));
    int count = b - a;
    int result = a;
    for(int i = 0; i < count; i++){
        result += random_0_1();
    }
    return result;
}

int main(int argc, char ** argv){
    cout << random(10, 20) << endl;
}
