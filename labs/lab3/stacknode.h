//
//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, stacknode.h

#include <iostream>
using namespace std;

#ifndef stacknode_h
#define stacknode_h

class stacknode{
public:
    stacknode();
    
private:
    int value;
    stacknode* next;
    stacknode* previous;
    //stacknode* previous;
    
    friend class stack;
};

#endif /* stacknode_h */
