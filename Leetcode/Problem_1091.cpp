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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        if (n == 0 ) return -1;
        if (grid[0][0] != 0 | grid[m-1][n-1] != 0) return -1;

        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()) {
            auto curr = q.front();
            int r = curr.first;
            int c = curr.second;
            if (r == m-1 && c == n-1) {
                return grid[r][c] + 1;
            }
            for (auto direction : directions) {
                int nr = r + direction[0];
                int nc = c + direction[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push(make_pair(nr,nc));
                    grid[nr][nc] = grid[r][c] + 1;
                }
            }
            q.pop();
        }

        return -1;
    }
};
