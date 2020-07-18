#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int m;
    int n;
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        memo = dp;
        
        return dfs(grid, 0, 0, n-1);
    }

    int dfs(vector<vector<int>>& grid, int r, int c1, int c2) {
        if (r == m) {
            return 0;
        }
        if (memo[r][c1][c2] != -1) {
            return memo[r][c1][c2];
        }

        int ans = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int c1n = c1 + i;
                int c2n = c2 + j;

                if (c1n >= 0 && c1n < n && c2n >= 0 && c2n < n) {
                    ans = max(ans, dfs(grid, r+1, c1n, c2n));
                }
            }
        }

        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        memo[r][c1][c2] = ans + cherries;
        return memo[r][c1][c2];
    }
};
