//
//  HuffmanTree.cpp
//  
//
//  Created by Hanzhang Zhao on 11/22/21.
//

#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <string>
#include <iostream>
using namespace std;

HuffmanTree::HuffmanTree(){
    root = new HuffmanNode();
}

HuffmanTree::~HuffmanTree(){
    delete root;
    root = NULL;
}

void HuffmanTree::insert(HuffmanNode*& root, HuffmanNode* node, int position){
    if (position == node -> prefix.length()){
        root = node;
    }
    else if (node -> prefix[position] == '0'){
        if (root -> left == NULL){
            HuffmanNode* newNode = new HuffmanNode();
            root -> left = newNode;
        }
        insert (root -> left, node, position + 1);
    }
    else if (node -> prefix[position] == '1'){
        if (root -> right == NULL){
            HuffmanNode* newNode = new HuffmanNode();
            root -> right = newNode;
        }
        insert (root -> right, node, position + 1);
    }
}

void HuffmanTree::print(HuffmanNode* root){
    if (root -> left == NULL && root -> right == NULL){
        cout << root -> value << " " << root -> prefix << endl;
    }
    if (root -> left != NULL){
        print(root -> left);
    }
    if (root -> right != NULL){
        print(root -> right);
    }
}

void HuffmanTree::decode(HuffmanNode* root, int position, string bits){
    if (position <= bits.length()){
        if (root -> left == NULL && root -> right == NULL){
            cout << root -> value;
            decode(this->root, position, bits);
        }
        else if (bits[position] == '0'){
            decode(root -> left, position + 1, bits);
        }
        else if (bits[position] == '1'){
            decode(root -> right, position + 1, bits);
        }
    }
}
