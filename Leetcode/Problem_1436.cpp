#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * The input is a list of pairs of that indcate a directed edge. The graph made
     * by these edges are guaranteed to make a straight line path. The goal is to 
     * find the destination city. 
     * ex. [["B","C"],["D","B"],["C","A"]] -> "A"
     * @return string, the Destination city 
     */
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;
        // Add all of the source cities into a hash set.
        for (vector<string>& path : paths) {
            sources.insert(path[0]);
        }

        // If a destination city is not a source, it is the endpoint.
        for(vector<string>& path : paths) {
            if (sources.find(path[1]) == sources.end()) {
                return path[1];
            }
        }

        return string();
    }
};