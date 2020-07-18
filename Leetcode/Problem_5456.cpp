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

class TreeAncestor {
public:
    int dp[500009][29];
    int height;

    void calculateSparse(int u, int v) {  
        dp[v][0] = u; 
        for (int i = 1; i <= height; i++)  { 
            dp[v][i] = dp[dp[v][i - 1]][i - 1]; 
            if (dp[v][i] == -1) 
                return; 
        } 
    }

    TreeAncestor(int n, vector<int>& parent) {
        memset(dp, -1, sizeof(dp));
        this->height = (int)ceil(log2(n));
        
        for(int i = 1; i < parent.size(); i++) {
            calculateSparse(parent[i], i);
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for (int i = 0; i <= height; i++) { 
            if (k & (1 << i)) { 
                node = dp[node][i]; 
                if (node == -1) 
                    return -1; 
            } 
        } 
        return node; 
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
