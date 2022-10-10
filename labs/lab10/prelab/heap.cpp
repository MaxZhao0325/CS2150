// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// This code is cited by Hanzhang Zhao (hz9xs) on Nov 19, 2021

#include <iostream>
#include "heap.h"
#include "HuffmanNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    HuffmanNode* newNode = new HuffmanNode();
    heap.push_back(newNode);
}

// builds a heap from an unsorted vector
binary_heap::binary_heap(vector<HuffmanNode*> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    HuffmanNode* newNode = new HuffmanNode();
    heap[0] = newNode;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
binary_heap::~binary_heap() {
}

void binary_heap::insert(HuffmanNode* x) {
    // a vector push_back will resize as necessary
    heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void binary_heap::percolateUp(int hole) {
    // get the value just inserted
    HuffmanNode* x = heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < heap[hole/2]->frequency); hole /= 2) {
        heap[hole] = heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

HuffmanNode* binary_heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    HuffmanNode* ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void binary_heap::percolateDown(int hole) {
    // get the value to percolate down
    HuffmanNode* x = heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heap[child+1] -> frequency < heap[child] -> frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x -> frequency > heap[child] -> frequency) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

HuffmanNode* binary_heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap[1];
}

unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
    heap.resize(1);
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

void binary_heap::print() {
    for (int i = 1; i < heap.size()+1; i++){
        if (heap[i] != NULL){
            cout << heap[i]->value << " " << heap[i]->frequency << endl;
        }
    }
    
}

//bool binary_heap::findchar(HuffmanNode* root, char input){
//    if (root -> value == input){
//        return true;
//    }
//    if (root -> left != NULL){
//        return findchar(root -> left, input);
//    }
//    if (root -> right != NULL){
//        return findchar(root -> right, input);
//    }
//    return false;
//}

void binary_heap::givePrefix(HuffmanNode* root, string prefix) {
    if (root -> value != '?'){
        map[root -> value] = prefix;
    }
    if (root -> left != NULL){
        givePrefix(root -> left, prefix + "0");
    }
    if (root -> right != NULL){
        givePrefix(root -> right, prefix + "1");
    }
}

//HuffmanNode* binary_heap::findNode(char g){
//    for (int i = 0; i < heap.size(); i++){
//        if (heap[i]->value == g){
//            return heap[i];
//        }
//    }
//    return NULL;
//}
