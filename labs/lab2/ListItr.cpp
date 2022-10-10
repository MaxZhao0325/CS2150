//
// Hanzhang Zhao, hz9xs@virginia.edu, Sep 6, ListItr.cpp
//  
//
//
//

#include "ListItr.h"
#include <iostream>
#include <string>
using namespace std;

ListItr::ListItr(){
    current = NULL;
}

ListItr::ListItr(ListNode* theNode){
    current = theNode;
}

bool ListItr::isPastEnd() const{
    if (current->next == NULL){
        return true;
    }
    return false;
}

bool ListItr::isPastBeginning() const{
    if (current->previous == NULL){
        return true;
    }
    return false;
}

void ListItr::moveForward(){
    if (!(isPastEnd())){
        current = current->next;
    }
}

void ListItr::moveBackward(){
    if (!(isPastBeginning())){
        current = current->previous;
    }
}

int ListItr::retrieve() const{
    return current->value;
}

