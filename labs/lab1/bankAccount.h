// Hanzhang Zhao, hz9xs@virginia.edu, August 31, bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class bankAccount{
public:
    bankAccount(); //default constructor
    bankAccount(double amount); //parameter constructor
    ~bankAccount(); //destructor
    double withdraw(double amount); //return new amount after withdraw (if amount > balance, dont withdraw)
    double deposit(double amount); //return new amount after deposit
    double getBalance(); //return balance
private:
    double balance;
    
};

#endif
