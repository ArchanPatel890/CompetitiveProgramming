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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int> > minPath(m, vector<int>(n, grid[0][0]));

        for (int i = 1; i < m; i++) {
            minPath[i][0] = minPath[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            minPath[0][j] = minPath[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                minPath[i][j]  = min(minPath[i - 1][j], minPath[i][j - 1]) + grid[i][j];
            }
        }
        return minPath[m - 1][n - 1];
    }
};