//
//  wordPuzzle.cpp
//  
//
//  Created by Hanzhang Zhao on 10/12/21.
//  hz9xs

//#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
//unordered_set<string> set;
hashTable table;

// methods declaration
bool isAlphabetical(string str);
bool readInDictionary(string filename);
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main (int argc, char **argv){
    // timer begin
    timer t;
    if(!readInDictionary(argv[1])){
        cout << "Error reading in file!" << endl;
        return 1;
    }
    
    // to hold the number of rows and cols in the input file
    int rows, cols;

    // attempt to read in the file
    bool result = readInGrid(argv[2], rows, cols);
    // if there is an error, report it
    if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    t.start();
//    stack<string> list;
    string x = "";
    int cori = -1;
    int corj = -1;
    int cork = -1;
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            for (int k = 0; k < 8; k++){
                for (int l = 3; l < 23; l++){
                    string y = getWordInGrid(i, j, k, l, rows, cols);
                    if (y.size() >= 3){
                        if (table.contain(y)){
                            if ((y != x) || (i != cori || j != corj || k != cork)){
                                x = getWordInGrid(i, j, k, l, rows, cols);
                                cori = i;
                                corj = j;
                                cork = k;
                                string dirOut;
                                if (k == 0){
                                    dirOut = "         N ";
                                }
                                else if (k == 1){
                                    dirOut = "       NE";
                                }
                                else if (k == 2){
                                    dirOut = "     E ";
                                }
                                else if (k == 3){
                                    dirOut = "  SE";
                                }
                                else if (k == 4){
                                    dirOut = "                  S ";
                                }
                                else if (k == 5){
                                    dirOut = "           SW";
                                }
                                else if (k == 6){
                                    dirOut = "      W ";
                                }
                                else if (k == 7){
                                    dirOut = "NW";
                                }
                                cout << dirOut << "(" << i << ", " << j << "):  " << getWordInGrid(i, j, k, l, rows, cols) << "before the birds wake up" << endl;
                                count ++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count << " words found" << endl;
    
    // timer end
    t.stop();
    
    //for timing
    //cout << "Found all words in " << t.getTime() << " seconds" << endl;
    
    //for in lab
//    cout << 100000 * t.getTime() << endl;

    return 0;
}

bool isAlphabetical(string str){
    for (int i = 0; i < str.size(); i++){
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))){
            return false;
        }
    }
    return true;
}

bool readInDictionary(string filename){
    string line;
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }
    // read in dictionary using while loop
    while (getline(file, line)){
        if(isAlphabetical(line)){
            table.insert(line);
        }
    }
    file.close();
    return true;
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
//    cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
//    cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
//            cout << grid[r][c];
        }
//        cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(22); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    return output;
}
