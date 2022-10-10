//
//  HuffmanTree.h
//  
//
//  Created by Hanzhang Zhao on 11/22/21.
//

#ifndef HuffmanTree_h
#define HuffmanTree_h
#include <string>
#include "HuffmanNode.h"
using namespace std;

class HuffmanTree {
public:
    HuffmanTree();
    ~HuffmanTree();
    void insert(HuffmanNode*& root, HuffmanNode* node, int position);
    void print(HuffmanNode* root);
    void decode(HuffmanNode* root, int position, string bits);
    
    HuffmanNode* root;
    friend class huffmandec;
    friend class HuffmanNode;
};

#endif /* HuffmanTree_hpp */
