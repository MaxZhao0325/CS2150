//
//  hashTable.cpp
//  
//
//  Created by Hanzhang Zhao on 10/12/21.
//  hz9xs
//

#include "hashTable.h"
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

//default cons
hashTable::hashTable(){
    size = getNextPrime(50000);
    table = new string[size];
    //alternation
//    table = new vector<list<string> >(size);
    count = 0;
}

//cons with initial size
hashTable::hashTable(int s){
    size = s;
    table = new string[size];
//    alternation
//    table = new vector<list<string> >(size);
    count = 0;
}

int hashTable::hashFunction(string x){
    int sum = 0;
    for (int i = 0; i < x.size(); i++){
        sum += pow(x[i], 2);
    }
    return sum % size;
}

void hashTable::insert(string x){
    int position = hashFunction(x);

    // probing
    int jump = 1;
    while(table[position] != ""){
        position = (hashFunction(x) + jump * jump) % size;
        jump++;
    }
    table[position] = x;
}

bool hashTable::contain(string x){
    int position = hashFunction(x);
    
    // vector list alternation
//    return(find(table->at(key).begin(), table->at(key).end(), x) != table->at(key).end());
//    return(find(table[key].begin(), table[key].end(), x) != table[key].end());

    //probing
    int jump = 1;
    while (table[position] != x){
        position = (hashFunction(x) + jump * jump) % size;
        if (table[position] == ""){
            return false;
        }
        jump++;
    }
    return true;
    
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
