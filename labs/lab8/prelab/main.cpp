

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int vecsum (int, int);

// Purpose: This main program produces a vector of random numbers
// between 0 and 99, then calls the externally defined function
// 'vecsum' to add up the elements of the vector.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

    cout << vecsum (2,2) << endl;
    // all done!
    return 0;
}
