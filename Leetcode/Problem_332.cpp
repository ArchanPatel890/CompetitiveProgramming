#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        string start = "JFK";

        for (auto edge : tickets) {
            adj[edge[0]].push(edge[1]);
        }
        vector<string> route;
        visit(start, adj, route);
        // Reverse the order because edges were adding by DFS in reverse.
        reverse(route.begin(), route.end());
        return route; 
    }

    void visit(string airport, map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& route) {
        while(!adj[airport].empty()) {
            string next = adj[airport].top();
            adj[airport].pop();
            visit(next, adj, route);
        }
        route.push_back(airport);
    }
};
