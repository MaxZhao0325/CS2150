//
//  HuffmanNode.h
//  
//
//  Created by Hanzhang Zhao (hz9xs) on 11/19/21.
//

#ifndef HuffmanNode_h
#define HuffmanNode_h
#include <string>
using namespace std;

class HuffmanNode{
public:
    HuffmanNode();
    ~HuffmanNode();

    char value;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    
    friend class huffmanenc;
    friend class heap;
};

#endif /* HuffmanNode_hpp */
