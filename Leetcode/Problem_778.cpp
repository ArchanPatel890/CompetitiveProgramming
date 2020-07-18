#include <iostream>  
#include <iomanip>
#include <fstream>
#include <cmath>
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
    int swimInWater(vector<vector<int>>& grid) {
        return getMinTimeBinarySearch(grid);
    }

    /**
     * Uses binary search to find an appropriate value for the min t in the
     * grid. It then uses DFS to verify a path exists for that value of t.
     * Since t is at most n^2 - 1 and DFS takes O(V) = O(n^2) 
     * The complexity of this method is O(N*2 log N)
     */
    int getMinTimeBinarySearch(vector<vector<int>>& grid) {
        int n = grid.size();
        int mint = max(grid[0][0], grid[n-1][n-1]);
        int maxt = n*n - 1;
        int ans = INT_MAX;
        while(mint < maxt) {
            int t = (mint + maxt) / 2;
            if (searchDFS(grid, t, n)) {
                maxt = t - 1;
            } else {
                mint = t + 1;
            }
        }
        
        return mint;
    }

    bool searchDFS(vector<vector<int>>& grid, int maxt, int n) {
        int r = 0, c = 0;
        // The start node is not accessible
        if (grid[r][c] > maxt) 
            return false;

        vector<vector<bool>> visited (n, vector<bool> (n, false));
        vector<vector<int>> neighbors; 
        neighbors.push_back({r, c});

        while (!neighbors.empty()) {
            r = neighbors.back()[0];
            c = neighbors.back()[1];
            neighbors.pop_back();
            visited[r][c] = true;
            if (r == n-1 && c == n-1) 
                return true;
            // Up
            if (r > 0 && grid[r-1][c] <= maxt && !visited[r-1][c]) {
                neighbors.push_back({r-1, c});
            }
            // Down
            if (r < n-1 && grid[r+1][c] <= maxt && !visited[r+1][c]) {
                neighbors.push_back({r+1, c});
            }
            // Right
            if (c > 0 && grid[r][c-1] <= maxt && !visited[r][c-1]) {
                neighbors.push_back({r, c-1});
            }
            // Left
            if (c < n-1 && grid[r][c+1] <= maxt && !visited[r][c+1]) {
                neighbors.push_back({r, c+1});
            }
        }

        return false;
    }

    /**
     * Uses Dijkstra's Algorithm to find the minimum weight path from the start
     * to the end. The distance of the path is equal to the max valued node 
     * in the path.
     */
    int getMinTimeDijkstra(vector<vector<int>>& grid) {
        return 0;
    }

    /**
     * Uses a priority queue to build a minimum spanning tree of sorts that stops at
     * the end node. This method will start from the beginning and add all of the 
     * vertex's neighbors into the grid. It then visits the minimum weight node until
     * it reaches the end. (This takes advantage of the fact that there is no cost 
     * to move between nodes when they are flooded (i.e. when grid[r][c] <= t).
     */
    int getMinTimeMST(vector<vector<int>>& grid) {
        return 0;
    }
};
