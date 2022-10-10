//Hanzhang Zhao, hz9xs@virginia.edu, August 31, bankAccount.cpp

#include "bankAccount.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor and destructors - no return type
bankAccount::bankAccount(){
    balance = 0;
}

bankAccount::bankAccount(double amount){
    balance = amount;
}

bankAccount::~bankAccount(){
    
}

// Regular methods, with return types
double bankAccount::withdraw(double amount){
    if (balance >= amount){
        balance -= amount;
        return balance;
    }
    else{
        return balance;
    }
}

double bankAccount::deposit(double amount){
    balance += amount;
    return balance;
}

double bankAccount::getBalance(){
    return balance;
}
