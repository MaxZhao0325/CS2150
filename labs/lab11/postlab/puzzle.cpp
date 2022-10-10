//
//  puzzle.cpp
//  
//
//  Created by Hanzhang Zhao on 11/30/21.
//

#include "puzzle.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

puzzle::puzzle(){
    distance = 0;
}

vector<puzzle> puzzle::generateNeighbor(){
    vector<puzzle> result;
    puzzle temp1;
    temp1.distance = this->distance + 1;
    puzzle temp2;
    temp2.distance = this->distance + 1;
    puzzle temp3;
    temp3.distance = this->distance + 1;
    puzzle temp4;
    temp4.distance = this->distance + 1;
    // case1
    if (grid[0] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[0];
        temp1.grid[0] = temp1.grid[1];
        temp1.grid[1] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[0];
        temp2.grid[0] = temp2.grid[3];
        temp2.grid[3] = temp;
        result.push_back(temp2);
    }
    // case2
    else if (grid[2] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[2];
        temp1.grid[2] = temp1.grid[1];
        temp1.grid[1] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[2];
        temp2.grid[2] = temp2.grid[5];
        temp2.grid[5] = temp;
        result.push_back(temp2);
    }
    // case3
    else if (grid[6] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[6];
        temp1.grid[6] = temp1.grid[3];
        temp1.grid[3] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[6];
        temp2.grid[6] = temp2.grid[7];
        temp2.grid[7] = temp;
        result.push_back(temp2);
    }
    // case4
    else if (grid[8] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[8];
        temp1.grid[8] = temp1.grid[5];
        temp1.grid[5] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[8];
        temp2.grid[8] = temp2.grid[7];
        temp2.grid[7] = temp;
        result.push_back(temp2);
    }
    // case5
    else if (grid[1] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[1];
        temp1.grid[1] = temp1.grid[0];
        temp1.grid[0] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[1];
        temp2.grid[1] = temp2.grid[2];
        temp2.grid[2] = temp;
        result.push_back(temp2);
        
        temp3.grid = this->grid;
        temp = temp3.grid[1];
        temp3.grid[1] = temp3.grid[4];
        temp3.grid[4] = temp;
        result.push_back(temp3);
    }
    // case6
    else if (grid[3] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[3];
        temp1.grid[3] = temp1.grid[0];
        temp1.grid[0] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[3];
        temp2.grid[3] = temp2.grid[4];
        temp2.grid[4] = temp;
        result.push_back(temp2);
        
        temp3.grid = this->grid;
        temp = temp3.grid[3];
        temp3.grid[3] = temp3.grid[6];
        temp3.grid[6] = temp;
        result.push_back(temp3);
    }
    // case7
    else if (grid[5] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[5];
        temp1.grid[5] = temp1.grid[2];
        temp1.grid[2] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[5];
        temp2.grid[5] = temp2.grid[4];
        temp2.grid[4] = temp;
        result.push_back(temp2);
        
        temp3.grid = this->grid;
        temp = temp3.grid[5];
        temp3.grid[5] = temp3.grid[8];
        temp3.grid[8] = temp;
        result.push_back(temp3);
    }
    // case8
    else if (grid[7] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[7];
        temp1.grid[7] = temp1.grid[6];
        temp1.grid[6] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[7];
        temp2.grid[7] = temp2.grid[4];
        temp2.grid[4] = temp;
        result.push_back(temp2);
        
        temp3.grid = this->grid;
        temp = temp3.grid[7];
        temp3.grid[7] = temp3.grid[8];
        temp3.grid[8] = temp;
        result.push_back(temp3);
    }
    // case9
    else if (grid[4] == 0){
        temp1.grid = this->grid;
        int temp = temp1.grid[4];
        temp1.grid[4] = temp1.grid[1];
        temp1.grid[1] = temp;
        result.push_back(temp1);
        
        temp2.grid = this->grid;
        temp = temp2.grid[4];
        temp2.grid[4] = temp2.grid[3];
        temp2.grid[3] = temp;
        result.push_back(temp2);
        
        temp3.grid = this->grid;
        temp = temp3.grid[4];
        temp3.grid[4] = temp3.grid[5];
        temp3.grid[5] = temp;
        result.push_back(temp3);
        
        temp4.grid = this->grid;
        temp = temp4.grid[4];
        temp4.grid[4] = temp4.grid[7];
        temp4.grid[7] = temp;
        result.push_back(temp4);
    }
    return result;
}

int puzzle::hashfunction(){
    int sum = 9;
    for (int i = 0; i < 9; i++){
        sum ^= grid[i] + 0x9e3779b9 + (sum << 6) + (sum >> 2);
    }
    return sum;
}
