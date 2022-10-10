//  huffmanenc.cpp
//  Created by Hanzhang Zhao (hz9xs) on 11/19/21.
//
//  This huffman tree is created based on the heap code written by Aaron Bloomfield, 2014
#include "heap.h"
#include "HuffmanNode.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
// "fileio.cpp" is cited for reading file part of the program
using namespace std;

int main(int argc, char** argv) {
    
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    vector<HuffmanNode*> copylist;
    
    for(int i = 0; i < 126; i++){
        copylist.push_back(NULL);
    }
        
    while (file.get(g)) {
        //use hash table to store the value pairs
        int hash = int(g) - 32;
        if (copylist[hash] == NULL){
            HuffmanNode* newNode = new HuffmanNode();
            newNode->value = g;
            newNode->frequency = 1;
            copylist[hash] = newNode;
        }
        else{
            copylist[hash]->frequency++;
        }
    
//        if(charlist.findNode(g) == NULL){
//            HuffmanNode* newNode = new HuffmanNode();
//            newNode->value = g;
//            newNode->frequency = 1;
//            charlist.insert(newNode);
//        }
//        else{
//            charlist.findNode(g)->frequency++;
//        }
//    }
//    charlist.print();
    }
    
    // build the vector that has the proper size rather than 126
    vector<HuffmanNode*> copylist2;
    for (int i = 0; i < copylist.size(); i++){
        if (copylist[i] != NULL){
            copylist2.push_back(copylist[i]);
        }
    }
    
    // build the heap
    binary_heap charlist(copylist2);
//

    // build the HuffmanTree
    while (charlist.size() > 1){
        HuffmanNode* newNode = new HuffmanNode();
        newNode -> frequency += charlist.findMin() -> frequency;
        newNode -> left = charlist.deleteMin();
        newNode -> frequency += charlist.findMin() -> frequency;
        newNode -> right = charlist.deleteMin();
        charlist.insert(newNode);
    }
    
    // give the prefix code to each node in the HuffmanTree
    charlist.givePrefix(charlist.findMin(), "");

    // output
    // to print out the map (pairs of keys and values), I use some code on the std unordered_map, which is cited below
    // https://en.cppreference.com/w/cpp/container/unordered_map/insert
    for(auto& p: charlist.map){
        if (p.first == *" "){
            cout << "space" << " " << p.second << "\n";
        }
        else{
            cout << p.first << " " << p.second << "\n";
        }
    }
    
    // second section
    cout << "----------------------------------------" << endl;
    
    file.clear();
    file.seekg(0);
    
    string output = "";
    while (file.get(g)) {
        output += charlist.map[g];
        output += " ";
    }
    cout << output << endl;
    
    // third section
    cout << "----------------------------------------" << endl;
    
    cout << "There are a total of " << charlist.findMin()->frequency <<  " symbols that are encoded." << endl;
    
    cout << "There are " << charlist.map.size() -1 << " distinct symbols used." << endl;
    
    double orig = 8 * charlist.findMin()->frequency;
    cout << "There were " << orig << " bits in the original file." << endl;
    
    double compress = 0;
    for (int i = 0; i < copylist2.size(); i++){
        compress += charlist.map[copylist2[i]->value].size() * (copylist2[i]->frequency);
    }
    cout << "There were " << compress << " bits in the compressed file." <<endl;
    
    // to print out the result with 5 decimal digits, I referenced some codes on the website, which is cited below.
    // https://www.includehelp.com/cpp-tutorial/printing-float-values-with-fixed-number-of-decimal-places-through-cout.aspx
    cout << "This gives a compression ratio of ";
    double d = orig / compress;
    cout << fixed << setprecision(5) << d << "." << endl;
    
    cout << "The cost of the Huffman tree is ";
    d = compress / charlist.findMin()->frequency;
    cout << fixed << setprecision(5) << d << " bits per character." << endl;
    
    file.close();

    return 0;
}
