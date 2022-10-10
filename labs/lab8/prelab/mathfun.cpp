// main.cpp
// Hanzhang Zhao hz9xs 11.01
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

// Purpose: This mathfun program produces the product and the power of two integers
// give two input integers, then calls the externally defined function

int  main () {

    // delcare the local variables
    int  x, y, pro, pow;

    // input two integers
    cout << "Enter integer 1: ";
    cin >> x;

    cout << "Enter integer 2: ";
    cin >> y;

    // do the product
    pro = product(x, y);
    cout << "Product: " << pro << endl;
    pow = power(x, y);
    cout << "Power: " << pow << endl;

    // all done!
    return 0;
}
