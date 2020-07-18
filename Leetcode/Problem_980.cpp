#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int empty_spaces;

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int paths = 0;
        empty_spaces = 0;
        int r_s = 0; 
        int c_s = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1) {
                    ++empty_spaces;
                }
                if (grid[i][j] == 1) {
                    r_s = i;
                    c_s = j;
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        return getPaths(grid, dirs, r_s, c_s, 1);
    }

    int getPaths(vector<vector<int>>& grid, vector<vector<int>>& dirs, int r, int c, int steps) {
        if (grid[r][c] == 2) {
            return steps == empty_spaces ? 1 : 0;
        }

        int paths = 0;
        int ndirs = dirs.size();
        grid[r][c] = -1;
        for (int i = 0; i < ndirs; ++i) {
            int i_n = r + dirs[i][0];
            int j_n = c + dirs[i][1];

            if (i_n >= 0 && i_n < m && j_n >= 0 && j_n < n && grid[i_n][j_n] != -1) {
                paths += getPaths(grid, dirs, i_n, j_n, steps + 1);
            }
        }
        grid[r][c] = 0;
        return paths;
    }
};
