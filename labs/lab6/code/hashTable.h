//
//  hashTable.h
//  
//
//  Created by Hanzhang Zhao on 10/12/21.
//  hz9xs

#ifndef hashTable_hpp
#define hashTable_hpp

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class hashTable {
public:
    hashTable();
    hashTable(int s);
    void insert(string x);
    bool contain(string x);
    
private:
    int hashFunction(string x);
    bool checkprime(unsigned int p);
    int getNextPrime(unsigned int n);
//    int size;
    int size;
    int count;
    vector<int> *list;
    
    //vector + list alternation
//    vector<list<string> > *table;
};

#endif /* hashTable_hpp */
