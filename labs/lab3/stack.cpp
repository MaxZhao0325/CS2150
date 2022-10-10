//
//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, stack.cpp

#include "stack.h"
#include <iostream>
using namespace std;

stack::stack(){
    head = NULL;
    count = 0;
}

stack::~stack(){
    while(!empty()){
        pop();
    }
}

void stack::push(int e){
    if (head == NULL){
        head = new stacknode();
        head->value = e;
    }
    else{
        stacknode* newNode = new stacknode();
        newNode->previous = head;
        if (head->next != NULL){
            head->next->previous = newNode;
            newNode->next = head->next;
        }
        head->next = newNode;
        newNode->value = head->value;
        head->value = e;
    }
    count++;
}

void stack::pop(){
//    if(!empty()){
//        if (count != 1){
//            head = head->next;
//            delete head->previous;
//            head->previous = NULL;
//        }
//        else{
//            delete head;
//            head = NULL;
//        }
//        count--;
//    }
//    else{
//        cout << "empty stack" <<endl;
//        exit(-1);
//    }
    if (count != 1){
        head = head->next;
        delete head->previous;
        head->previous = NULL;
    }
    else{
        delete head;
        head = NULL;
    }
    count--;
}

int stack::top(){
//    if(!empty()){
//        return head->value;
//    }
//    else{
//        cout << "empty stack" <<endl;
//        exit(-1);
//    }
    return head->value;
}

bool stack::empty(){
    if(count == 0){
        return true;
    }
    else{
        return false;
    }
}

int stack::size(){
    return count;
}

//int main()
//{
//    stack* s = new stack();
//    int x;
//    cin >> x;
//    s->push(x);
//    cout << s->top() << endl;
//    s->push(20);
//    cout << s->top() << endl;
//    s->push(30);
//    cout << s->top() << endl;
//
//    cout<<"Elements present in stack : ";
//    while(!s->empty())
//    {
//        cout<<s->top()<<" ";
//        s->pop();
//    }
//    cout<<endl;
//
//    return 0;
//}
