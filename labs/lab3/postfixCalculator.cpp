//
//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
#include <string>
//#include <stack>

//postlab
#include "stack.h"
#include <cstdlib>
using namespace std;

postfixCalculator::postfixCalculator(){
//    calculator = stack<int>();
    //for post lab
    calculator = stack();
}

postfixCalculator::~postfixCalculator(){

}

void postfixCalculator::push(int a){
    calculator.push(a);
}

int postfixCalculator::top(){
    if (!calculator.empty()){
        return calculator.top();
    }
    else{
        cout << "can not return top for empty list" << endl;
        exit(-1);
    }
}

void postfixCalculator::pop(){
    if (!calculator.empty()){
        calculator.pop();
    }
    else{
        cout << "can not pop for empty list" << endl;
        exit(-1);
    }
}

bool postfixCalculator::empty(){
    if(calculator.empty()){
        return true;
    }
    else{
        return false;
    }
}

int postfixCalculator::size(){
    return calculator.size();
}

void postfixCalculator::makeEmpty(){
    while(!calculator.empty()){
        calculator.pop();
    }
}

//void postfixCalculator::printstack(){
//    while (!calculator.empty()) {
//            cout << calculator.top() << " ";
//            calculator.pop();
//        }
//    cout << endl;
//}

