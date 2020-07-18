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
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Create a neighbor lists of all array indices sharing the same values (cliques).
        map<int, unordered_set<int>> cliques;
        for (int i = 0; i < n; ++i) {
            if (cliques.find(arr[i]) == cliques.end()) {
                unordered_set<int> neighbors;
                neighbors.insert(i);
                cliques.emplace(arr[i], neighbors);
            } 
            else {
                cliques[arr[i]].insert(i);
            }
        }

        unordered_set<int> visited;
        vector<int> distance(n, INT_MAX);
        queue<int> nodes;
        nodes.push(0);
        distance[0] = 0;
        while(!nodes.empty()) {
            int i = nodes.front();
            nodes.pop();
            // Queue neighbors in the clique.
            int dist = distance[i] + 1;
            if (visited.find(arr[i]) == visited.end()) {
                for (int v : cliques[arr[i]]) {
                    if (v != i) {
                        nodes.push(v);
                        distance[v] = min(dist, distance[v]);
                    }
                }
                visited.insert(arr[i]);
            }
            // Queue the left node.
            if (i > 0 && visited.find(arr[i-1]) == visited.end()) {
                nodes.push(i-1);
                distance[i-1] = dist;
            }
            // Queue the right node.
            if (i < n-1 && visited.find(arr[i+1]) == visited.end()) {
                nodes.push(i+1);
                distance[i+1] = dist;
            }
        }

        return distance[n-1];
    }
};