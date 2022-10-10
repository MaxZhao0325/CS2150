//
//  HuffmanNode.cpp
//  
//
//  Created by Hanzhang Zhao (hz9xs) on 11/19/21.
//

#include "HuffmanNode.h"
#include <string>
using namespace std;

HuffmanNode::HuffmanNode(){
    value = '?';
    left = NULL;
    right = NULL;
    frequency = 0;
}

HuffmanNode::~HuffmanNode(){
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
