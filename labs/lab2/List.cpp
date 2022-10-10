//
//  Hanzhang Zhao, hz9xs@virginia.edu, Sep 6, List.cpp
//

#include "List.h"
#include <iostream>
#include <string>
using namespace std;

List::List(){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count = 0;
}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
    makeEmpty();
//    delete tail;
 //   delete &tail;
    delete head;
    head = NULL;
    delete tail;
    tail = NULL;
    //tail->previous = NULL;
    //delete &head;
//    tail = NULL;
//    head = NULL;
}

List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
    return (count == 0);
}

void List::makeEmpty(){
    
    //delete all nodes first including head and tail if list is not empty
//    if (!(isEmpty())){
//        ListItr c;
//        while (c.current != NULL){
//            c.current = tail->next;
//            delete tail;
//            tail = c.current;
//        }
//        count = 0;
//        // then create new head and tail for the list.
//        tail = new ListNode();
//        head = new ListNode();
//        tail->previous = head;
//        head->next = tail;
//    }
    
    if (!(isEmpty())){
        ListItr c = ListItr(head->next);
        while (c.current->next != NULL){
            c.moveForward();
            remove(c.current->previous->value);
        }
        count = 0;
        // then create new head and tail for the list.
//        tail = new ListNode();
//        head = new ListNode();
//        tail->previous = head;
//        head->next = tail;
//    ListItr pos(head);
//    pos.moveForward();
//    while (!pos.isPastEnd()) {
//        pos.current->next->previous = head;
//        delete head->next;
//        pos.moveForward();
//        head->next = pos.current;
//    }
}

ListItr List::first(){
    return ListItr(head->next);
}

ListItr List::last(){
    return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){
    ListNode* newNode = new ListNode();
    newNode->value = x;
    newNode->previous = position.current;
    newNode->next = position.current->next;

//    position.current->next->previous = newNode;
//    position.current->next = newNode;
    //another method
    position.current->next = newNode;
    newNode->next->previous = newNode;
    count++;
}

void List::insertBefore(int x, ListItr position){
    ListNode* newNode = new ListNode();
    newNode->value = x;
    newNode->previous = position.current->previous;
    newNode->next = position.current;

//    position.current->previous->next = newNode;
//    position.current->previous = newNode;
    
    // antoher method
    position.current->previous = newNode;
    newNode->previous->next = newNode;
    count++;
}

void List::insertAtTail(int x){
    ListNode* newNode = new ListNode();
    newNode->value = x;
    newNode->previous = tail->previous;
    newNode->next = tail;
//    tail->previous->next = newNode;
//    tail->previous = newNode;
    //another method
    tail->previous = newNode;
    newNode->previous->next = newNode;
    count++;
}

ListItr List::find(int x){
    ListItr a = ListItr(head->next);
    while(!(a.isPastEnd())){
        if (a.retrieve() == x){
            return a;
        }
        else{
            a.moveForward();
        }
    }
    return ListItr(tail);
}

void List::remove(int x){
    ListItr b = find(x);
    if (b.current != tail){
        b.current->previous->next = b.current->next;
        b.current->next->previous = b.current->previous;
        delete b.current;
        b.current = NULL;
        count--;
    }
}

int List::size() const{
    return count;
}

void printList(List& source, bool forward){
    if (forward){
        ListItr e(source.first());
        while(!(e.isPastEnd())){
            cout << e.retrieve() << " ";
            e.moveForward();
        }
        cout << "\n";
    }
    else{
        ListItr f(source.last());
        while(!(f.isPastBeginning())){
            cout << f.retrieve() << " ";
            f.moveBackward();
        }
        cout << "\n";
    }
}
