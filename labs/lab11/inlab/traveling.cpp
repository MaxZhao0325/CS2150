#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
string printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    //cout << *dests.end()<<endl;
    string start = *dests.begin();
    dests.erase(dests.begin());
    //cout << *(dests.end()-1) <<endl;
    //cout << me.getDistance("Trollshaws", "Barad-Dur") << endl;
    sort(dests.begin(), dests.end());
    //cout << printRoute(*dests.begin(), dests);
    string print = "";
    
    double min = 10000000;
    do {
        double count = 0;
        //cout << me.getDistance(start, *dests.begin()) << endl;
//        cout << me.getDistance(*dests.end(), start) << endl;
        count = computeDistance(me, *dests.begin(), dests) + me.getDistance(start, *dests.begin()) + me.getDistance(*(dests.end()-1), start);
        if (count < min){
            min = count;
            print = printRoute(*dests.begin(), dests);
        }
    } while(next_permutation(dests.begin(), dests.end()));
    cout << "Minimum path has distance " << min << ": " << start << " -> " << print << start << endl;
    return 0;
}

/*!
 * @brief This method will compute the full distance of the cycle that starts
 * @author hz9xs
 * @return a float that represents for the length of the route
 * @param me the middleearth map
 * @param start the start city of the route
 * @param dests the vector containing all cities
 *
 */
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    double sum = 0;
    for (auto it = find(dests.begin(), dests.end(), start); it != dests.end()-1; ++it){
        sum += me.getDistance(*it, *(it+1));
    }
    //sum += me.getDistance(*(dests.end()-1), *dests.begin());
    for (auto it = dests.begin(); it != find(dests.begin(), dests.end(), start); ++it){
        sum += me.getDistance(*it, *(it+1));
    }
//    for (auto it = dests.begin(); it != dests.end()-1; ++it){
//        sum += me.getDistance(*it, *(it+1));
//    }
    return sum;
}


/*!
 * @brief This method will print the entire route, starting and ending at the 'start' parameter.
 *
 * @return a string that represents for the route
 * @param start the start city of the route
 * @param dests the vector containing all cities
 *
 */
string printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    string result = "";
    for (auto it = find(dests.begin(), dests.end(), start); it != dests.end(); ++it){
        result += *it;
        result += " -> ";
    }

    for (auto it = dests.begin(); it != find(dests.begin(), dests.end(), start); ++it){
        result += *it;
        result += " -> ";
    }
    return result;
}
