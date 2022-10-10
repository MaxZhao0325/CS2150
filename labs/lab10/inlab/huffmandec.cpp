// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
// Hanzhang Zhao, Nov 22, lab 10 in-lab

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    // create the HuffmanTree
    HuffmanTree tree;

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
        HuffmanNode* newNode = new HuffmanNode();
        newNode -> value = character[0];
        newNode -> prefix = prefix;
        // insert the node to the proper position to the tree
        tree.insert(*&tree.root, newNode, 0);
    }
    //tree.print(tree.root);

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    
    // decode
    tree.decode(tree.root, 0, allbits);
    cout << endl;
    
    // close the file before exiting
    file.close();

    return 0;
}
