//
//  testfile.cpp
//  
//
//  Created by 赵晗璋 on 9/14/21.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <cfloat>
#include <climits>
using namespace std;

void outputBinary(int x){
    int value = x;
    int count = 0;
    while (value/2 != 0){
        count++;
        value /= 2;
    }
    int list[count + 1];
    int i = 0;
    while (x/2 != 0){
        list[i] = x % 2;
        i++;
        x /= 2;
    }
    if(value == 0){
        list[count] = 0;
    }
    else{
        list[count] = 1;
    }
    int innercount = 0;
    for(int i = 0; i < 32 - (count + 1); i++){
        if(innercount % 4 == 0 && innercount != 0){
            cout << " ";
        }
        cout << 0;
        innercount++;
    }
    for(int i = count; i >= 0; i--){
        if(innercount % 4 == 0 && innercount != 0){
            cout << " ";
        }
        cout << list[i];
        innercount++;
    }
    cout << endl;
}

void overflow(){
    bool y;
    y = DBL_MAX_EXP;
    cout << y << " + 1 = " << y+1 << endl;
    
}

union foo {
    float f;
    int *x;
} bar;

int main() {
    cout << sizeof(bar.f) << endl;
    bar.f = 0.1;
    cout << bar.x << endl; // prints in big-endian
    return 0;
}

//int main(){
//    // input
//    bool x;
//    cin >> x;
//
//    // method 1
////    sizeOfTest();
//
//    // method 2
//    overflow();
//
//    // method 3
//    //outputBinary(x);
//
//    return 0;
//}
