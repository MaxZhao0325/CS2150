//
//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, postfixCalculator.h

#ifndef postfixCalculator_h
#define postfixCalculator_h

#include <iostream>
//#include <stack>
//postlab
#include "stack.h"
using namespace std;

class postfixCalculator{

public:
    //constructor
    postfixCalculator();
    
    ~postfixCalculator();
    
    void push(int a);
    
    int top();
    
    void pop();
    
    bool empty();
    
    int size();
    
    void makeEmpty();
//    void printstack();

private:
//    stack<int> calculator;
    
    //post lab
    stack calculator;
    friend class testPostfixCalc;
};

#endif /* postfixCalculator_h */
