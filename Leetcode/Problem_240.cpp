#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;

        int n = matrix[0].size();
        if (!n) return false;
        
        int r = 0;
        int c = n-1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            else if (matrix[r][c] > target) {
                --c;
            }
            else {
                ++r;
            }
        }

        return false;
    }
};
