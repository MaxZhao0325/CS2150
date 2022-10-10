//
//  solvePuzzle.cpp
//  
//
//  Created by Hanzhang Zhao on 11/30/21.
//
/*!
 * @brief This class is used to solve the best path for the puzzle
 * @author Hanzhang Zhao, hz9xs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "puzzle.h"

using namespace std;

int main(){
    cout << "Enter puzzle" << endl;
    // create the initial puzzle
    puzzle initial;
    for (int i = 0; i < 9; i++){
        int a = 0;
        cin >> a;
        initial.grid.push_back(a);
    }
    // print the initial puzzle
//    for (auto it = initial.grid.begin(); it != initial.grid.end(); ++it){
//        cout << *it << " ";
//    }
//    cout << endl;
    
    // create the goal puzzle
    puzzle goal;
    for (int i = 1; i < 9; i++){
        goal.grid.push_back(i);
    }
    goal.grid.push_back(0);
    // print the goal puzzle
//    for (auto it = goal.grid.begin(); it != goal.grid.end(); ++it){
//        cout << *it << " ";
//    }
//    cout << endl;
    
    // check if the initial puzzle is solvable
    int count = 0;
    for (auto i = initial.grid.begin(); i != initial.grid.end() - 1; ++i){
        for (auto j = i + 1; j != initial.grid.end(); ++j){
            if (*j != 0 && *i > *j){
                count++;
            }
        }
    }
    // if solvale, then proceed next step
    if (count % 2 == 0){
        // create the queue for nodes
        unordered_map<int, puzzle> m;
        m.insert({initial.hashfunction(), initial});
        vector<puzzle> queue;
        queue.push_back(initial);
        vector<puzzle> temp;
        //cout << queue[0].grid[0] << endl;
        while (!queue.empty()){
            if (queue[0].grid == goal.grid){
                //cout << "hahahh" << endl;
                cout << "Solving puzzle" << endl;
                cout << queue[0].distance << endl;
                break;
            }
            //cout << queue.size() <<endl;
            temp = queue[0].generateNeighbor();
            for (auto i = temp.begin(); i != temp.end(); ++i){
                // if new neighbors, push it onto queue
             
                if (m.find((*i).hashfunction()) == m.end()){
                    m.insert({(*i).hashfunction(), *i});
                    queue.push_back(*i);
                    //cout << (*i).distance << endl;
                }
            }
            queue.erase(queue.begin());
            //cout << queue.size() <<endl;
        }
    }
    // if not, print not solvable
    else{
        cout << "Solving puzzle" << endl;
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
