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
    unordered_set<string> seen; 
    vector<int> edges;

    /**
     * Based on the deBrujin sequence.
     */
    string crackSafe(int n, int k) {
        // Clearing global variables 
        seen.clear(); 
        edges.clear();

        stringstream ss;
        for (int i = 0; i < k; ++i) {
            ss << i;
        }

        string A = ss.str();
        string startingNode = string(n - 1, A[0]); 
        dfs(startingNode, k, A); 
    
        string S; 
    
        // Number of edges 
        int l = pow(k, n); 
        for (int i = 0; i < l; ++i) 
            S += A[edges[i]]; 
        S += startingNode; 
    
        return S; 
    }
    
    // Modified DFS in which no edge 
    // is traversed twice 
    void dfs(string node, int& k, string& A) 
    { 
        for (int i = 0; i < k; ++i) { 
            string str = node + A[i]; 
            if (seen.find(str) == seen.end()) { 
                seen.insert(str); 
                dfs(str.substr(1), k, A); 
                edges.push_back(i); 
            } 
        } 
    } 
};
