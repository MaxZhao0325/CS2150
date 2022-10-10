// Hanzhang Zhao hz9xs Nov 29
// topological.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <list>
using namespace std;

/**
* @brief topological sort a list of courses
*
* @param no parameters
* @return The sorted list based on the given courses and their relationships
* @todo Need to test this file
*/

// we want to use parameters
int main(int argc, char** argv) {
    // initiate the graph
    unordered_map<string, list<string> > map;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings until reading fails
    string s1, s2;
    while(true){
        file >> s1;
        file >> s2;
        if (s1 == "0" && s2 == "0"){
            break;
        }
        
        // create the graph
        if (map.find(s2) == map.end()){
            list<string> newlist;
            newlist.push_back(s1);
            pair<string, list<string> > element(s2, newlist);
            map.insert(element);
        }
        else{
            map[s2].push_back(s1);
        }
        if (map.find(s1) == map.end()){
            list<string> newlist;
            pair<string, list<string> > element(s1, newlist);
            map.insert(element);
        }
    }
    
    // print out the graph
//    for (auto& x: map){
//        cout << x.first << ": ";
//        for (auto const &i: x.second) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
    
    // topological sort the graph
    while (!map.empty()){
        for(auto it = map.begin(); it != map.end(); ) {
            if(it->second.empty()){
                cout << it->first << " ";
                for (auto& m : map){
                    m.second.remove(it->first);
                }
                it = map.erase(it);
            }
            else{
                ++it;
            }
        }
    }
    cout << endl;

    // close the file before exiting
    file.close();
    return 0;
}

