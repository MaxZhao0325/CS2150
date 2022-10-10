//
//  testfile.cpp
//  
//
//  Created by 赵晗璋 on 10/14/21.
//
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
bool checkprime(unsigned int p) {
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

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
int main(){
    string *table[3];
    string x = "euaguaf";
    if (table[0] == NULL){
        table[0] = &x;
    }
    cout << *table[0] << endl;
    cout << getNextPrime(3000) << endl;
}
