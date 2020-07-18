#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
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
     * Get the transpose of the matrix @param A, can be of arbitrary dimensions m x n.
     */
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> ans(m);
        for (int j = 0; j < m; ++j) {
            vector<int> row(n);
            for (int i = 0; i < n; ++i) {
                row[i] = A[i][j];
            }
            ans[j] = row;
        }

        return ans;
    }
};
