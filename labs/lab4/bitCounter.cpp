//  Hanzhang Zhao hz9xs 09.16
//  bitCounter.cpp
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int binary(int x){
    if (x == 0){
        return 0;
    }
    if (x == 1){
        return 1;
    }
    if (x % 2 == 0){
        return binary(x/2);
    }
    else{
        return 1 + binary(x/2);
    }
}

void converter(string x, int y, int z){
    // convert from base y to base 10
    int baseten = 0;
    for (int i = 0; i < x.size(); i++){
        if (x.at(i) - 55 >= 10){
            baseten += (x.at(i) - 55) * pow(y, (x.size() - 1 - i));
        }
        else {
            baseten += (x.at(i) - 48) * pow(y, (x.size() - 1 - i));
        }
    }
    // convert from base 10 to base z
    int value = baseten;
    int count = 0;
    while (value/z != 0){
        count++;
        value /= z;
    }
    int list[count + 1];
    int i = 0;
    while (baseten/z != 0){
        list[i] = baseten % z;
        i++;
        baseten /= z;
    }
    if(value == 0){
        list[count] = 0;
    }
    else{
        list[count] = baseten % z;
    }
//    int innercount = 0;
//    for(int i = 0; i < 32 - (count + 1); i++){
//        if(innercount % 4 == 0 && innercount != 0){
//            cout << " ";
//        }
//        cout << 0;
//        innercount++;
//    }
    for (int i = count; i >= 0; i--){
        if (list[i] >= 10){
            cout << char(list[i] + 55);
        }
        else{
            cout << list[i];
        }
    }
}

int main(int argc, char **argv){
    //print first line
    int num = 0;
    stringstream ss;
    if (argv[1] == NULL){
        cout << "no command line parameter input" << endl;
        exit(-1);
    }
    if(argc < 5){
        cout << "not enough command line parameter input" << endl;
        exit(-1);
    }

    ss << argv[1];
    ss >> num;
    cout << argv[1] << " has " << binary(num) << " bit(s)" << endl;
    //print second line
    int num2 = 0;
    stringstream startbase;
    startbase << argv[3];
    startbase >> num2;
    int num3 = 0;
    stringstream endbase;
    endbase << argv[4];
    endbase >> num3;
    cout << argv[2] << " (base " << argv[3] << ") = ";
    converter(argv[2], num2, num3);
    cout << " (base " << argv[4] << ")" << endl;
    return 0;
}

