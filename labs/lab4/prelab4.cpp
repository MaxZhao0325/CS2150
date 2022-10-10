//  Hanzhang Zhao hz9xs@virginia.edu 09.14
//  prelab4.cpp
//  

//
#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;

struct st{
    int a;
    unsigned int b;
    float c;
    double d;
    char e;
    bool f;
    int* g;
    char* h;
    double* i;
}var;

void sizeOfTest(){
    cout << "Size of int: " << sizeof(var.a) << endl;
    cout << "Size of unsigned int: " << sizeof(var.b) << endl;
    cout << "Size of float: " << sizeof(var.c) << endl;
    cout << "Size of double: " << sizeof(var.d) << endl;
    cout << "Size of char: " << sizeof(var.e) << endl;
    cout << "Size of bool: " << sizeof(var.f) << endl;
    cout << "Size of int*: " << sizeof(var.g) << endl;
    cout << "Size of char*: " << sizeof(var.h) << endl;
    cout << "Size of double*: " << sizeof(var.i) << endl;
}

void overflow(){
    unsigned int y;
    y = UINT_MAX;
    cout << y << " + 1 = " << y+1 << endl;
    
}

void outputBinary(unsigned int x){
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

int main(){
    // input
    int x;
    cin >> x;
    
    // method 1
    sizeOfTest();
    
    // method 2
    overflow();
    
    // method 3
    outputBinary(x);
    
    return 0;
}

