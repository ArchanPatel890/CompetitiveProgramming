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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1) {
            return { 0 };
        }

        vector<vector<int>> adj(numCourses);
        vector<int> order;
        for (auto edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        if (!toposort_reverse(adj, order)) {
            return {};
        }
        return order;
    }

    bool toposort_reverse(vector<vector<int>> adj, vector<int>& order) {
        int n = adj.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!color[i] && !toposort_dfs(i, adj, color, order)) {
                return false;
            }
        }

        return true;
    }

    bool toposort_dfs(int start, vector<vector<int>>& adj, vector<int>& color, vector<int>& order) {
        color[start] = 1;
        for (int node : adj[start]) {
            if (color[node] == 1) {
                return false;
            }
            if (!color[node] && !toposort_dfs(node, adj, color, order)) {
                return false;
            }
        }

        color[start] = 2;
        order.push_back(start);
        return true;
    }
};
