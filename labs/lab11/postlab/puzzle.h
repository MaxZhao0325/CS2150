//
//  puzzle.h
//  
//
//  Created by Hanzhang Zhao on 11/30/21.
//
/// This is a header file of puzzle.cpp
/** puzzle class is used to create and store a single puzzle configuration */
#ifndef puzzle_hpp
#define puzzle_hpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class puzzle {
public:
    puzzle();
    vector<int> grid;
    int distance;
    vector<puzzle> generateNeighbor();
    /*!
     * @brief This method will compute the key for a given puzzle
     * @return the key, which is an int
     * @param no parameter
     */
    int hashfunction();
    friend class solvePuzzle;
};


#endif /* puzzle_hpp */
