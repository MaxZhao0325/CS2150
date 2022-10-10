//Hanzhang Zhao, hz9xs@virginia.edu, Sep 9, testPostfixCalc.cpp
//
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
#include "postfixCalculator.h"
//postlab
#include "stack.h"
//#include <stack>

int main () {
    string token;
    postfixCalculator a;
    while (cin >> token) {
        stringstream ss;
        int num = 0;
        ss << token;
        ss >> num;
        if (token == "/"){
            double div = 1.0;
            div /= a.top();
            a.pop();
            div *= a.top();
            a.pop();
            a.push(div);
        }
        else if (token == "*"){
            int mul = 1;
            mul *= a.top();
            a.pop();
            mul *= a.top();
            a.pop();
            a.push(mul);
        }
        else if (token == "+"){
            int sum = 0;
            sum += a.top();
            a.pop();
            sum += a.top();
            a.pop();
            a.push(sum);
        }
        else if (token == "-"){
            int sub = 0;
            sub -= a.top();
            a.pop();
            sub += a.top();
            a.pop();
            a.push(sub);
        }
        else if (token == "~"){
            int neg = 0;
            neg = 0 - a.top();
            a.pop();
            a.push(neg);
        }
        else{
            a.push(num);
        }
        // Do stuff with `token`!
        // For example, we can print each token back out on its own line:
        //a.printstack();
    }
    cout << a.top() << endl;
//    a.makeEmpty();
    return 0;
}
