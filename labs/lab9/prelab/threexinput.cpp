// hanzhang zhao hz9xs
// threexinput.cpp 11.11

#include <iostream>
#include <string>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int num);

int main(){
    int x;
    cout << "Enter a number: ";
    cin >> x;
    int n;
    cout << "Enter iterations of subroutine: ";
    cin >> n;
    cout << "Steps: " << threexplusone(x) << endl;
    timer a;
    a.start();
    for (int i = 0; i < n; i++){
        threexplusone(x);
    }
    a.stop();
    
    double average = a.getTime()/n;
    cout << average<< endl;
}
