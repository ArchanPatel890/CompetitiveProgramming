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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        
        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }
        int r_s = 0, r_e = m-1, c_s = 0, c_e = n-1;
        while (r_s <= r_e && c_s <= c_e)
        {
            printSprialEdges(r_s, r_e, c_s, c_e, matrix, ans);
            r_s++;
            r_e--;
            c_s++;
            c_e--;
        }

        return ans;
    }

    void printSprialEdges(int r_s, int r_e, int c_s, int c_e, vector<vector<int>>& matrix, vector<int>& ans) {
        // Print top row
        for (int i = c_s; i <= c_e; ++i) {
            ans.push_back(matrix[r_s][i]);
        }
        
        // Print right col
        for (int i = r_s+1; i <= r_e; ++i) {
            ans.push_back(matrix[i][c_e]);
        }
        
        if (r_s < r_e && c_s < c_e)
        {  
            // Print bottom row
            for (int i = c_e-1; i >= c_s; --i) {
                ans.push_back(matrix[r_e][i]);
            }

            // Print left col
            for (int i = r_e-1; i > r_s; --i) {
                ans.push_back(matrix[i][c_s]);
            }      
        }
        
    }
};