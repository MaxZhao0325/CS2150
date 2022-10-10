// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// This code is cited by Hanzhang Zhao (hz9xs) on Nov 19, 2021

#ifndef HEAP_H
#define HEAP_H
#include "HuffmanNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<HuffmanNode*> vec);
    ~binary_heap();

    void insert(HuffmanNode* newNode);
    HuffmanNode* findMin();
    HuffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void givePrefix(HuffmanNode* root, string prefix);
    unordered_map<char, string> map;
//    bool findchar(HuffmanNode* root, char input);
//    HuffmanNode* findNode(char g);
    
private:
    vector<HuffmanNode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
