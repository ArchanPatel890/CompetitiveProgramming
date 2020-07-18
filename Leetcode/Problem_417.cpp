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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<vector<int>>();
        int n = matrix[0].size();
        if (n == 0) return vector<vector<int>>();

        // Push the top row and left column for the pacific.
        vector<vector<bool>> pacific (m, vector<bool> (n, false));
        vector<vector<int>> pacific_borders;
        pushRow(pacific_borders, 0, n);
        pushColumn(pacific_borders, 0, m);
        searchDFS(matrix, pacific, pacific_borders);

        // Push the bottom row and right column for the atlantic.
        vector<vector<bool>> atlantic (m, vector<bool> (n, false));
        vector<vector<int>> atlantic_borders;
        pushRow(atlantic_borders, m-1, n);
        pushColumn(atlantic_borders, n-1, m);
        searchDFS(matrix, atlantic, atlantic_borders);

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void pushRow(vector<vector<int>>& init, int r, int n) {
        for (int i = 0; i < n; ++i) {
            init.push_back({r, i});
        }
    }

    void pushColumn(vector<vector<int>>& init, int c, int n) {
        for (int i = 0; i < n; ++i) {
            init.push_back({i, c});
        }
    }

    void searchDFS(
        vector<vector<int>>& matrix,
        vector<vector<bool>>& visited,
        vector<vector<int>>& neighbors) 
    {
        int r = 0, c = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while (!neighbors.empty()) {
            r = neighbors.back()[0];
            c = neighbors.back()[1];
            neighbors.pop_back();
            int elevation = matrix[r][c];
            visited[r][c] = true;
            // Up
            if (r > 0 && matrix[r-1][c] >= elevation && !visited[r-1][c]) {
                neighbors.push_back({r-1, c});
            }
            // Down
            if (r < m-1 && matrix[r+1][c] >= elevation && !visited[r+1][c]) {
                neighbors.push_back({r+1, c});
            }
            // Right
            if (c > 0 && matrix[r][c-1] >= elevation && !visited[r][c-1]) {
                neighbors.push_back({r, c-1});
            }
            // Left
            if (c < n-1 && matrix[r][c+1] >= elevation && !visited[r][c+1]) {
                neighbors.push_back({r, c+1});
            }
        }
    }
};