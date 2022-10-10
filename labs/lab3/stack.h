//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, stack.h

#ifndef stack_h
#define stack_h

#include <iostream>
#include "stacknode.h"
using namespace std;

class stack{
public:
    stack();
    
    ~stack();
    
    void push(int e);
    
    void pop();
    
    int top();
    
    bool empty();
    
    int size();
    
private:
    stacknode* head;
    int count;
};
#endif /* stack_h */
