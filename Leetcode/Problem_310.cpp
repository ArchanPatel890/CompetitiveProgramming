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

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1) {
            return {0};
        }

        vector<unordered_set<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while(!leaves.empty()) {
            vector<int> nextLayer;
            for (int node : leaves) {
                for (int neighbor : adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) {
                        nextLayer.push_back(neighbor);
                    }
                }
            }
            if (nextLayer.empty()) break;
            leaves = nextLayer;
        }

        return leaves;
    }
};
