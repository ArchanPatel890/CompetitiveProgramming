
// Q: You are given the size of a 2-D grid, a start and an end points in the
// grid, and a set of obstacles.  You can only move one cell up, down, left,
// right at a time, and you cannot go through obstacles.  Implement a solution
// to tell the user if there is a path from start to end.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// BFS
bool hasPath(int sr, int sc, int er, int ec, vector<vector<int>> grid) {
  int n = grid.size();
  if (n == 0) return false;
  int m = grid[0].size();
  if (m == 0) return false;
  if (sr < 0 || sr >= n || sc < 0 || sc >= m) return false;
  if (er < 0 || er >= n || ec < 0 || ec >= m) return false;
  if (grid[sr][sc] != 0) return false;
  
  vector<vector<bool>> seen(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  q.push({sr, sc}); 
  seen[sr][sc] = true;
  
  while (!q.empty()) {
    auto p = q.front();
	q.pop();
    if (p.first == er && p.second == ec) return true;
    int r = p.first;
    int c = p.second;
    // Up
    if (r > 0 && !seen[r-1][c] && grid[r-1][c] == 0) {
      seen[r-1][c] = true;
      q.push({r-1, c});
    }
    // Down
    if (r < n-1 && !seen[r+1][c] && grid[r+1][c] == 0) {
      seen[r+1][c] = true;
      q.push({r+1, c});
    }
    // Left
    if (c > 0 && !seen[r][c-1] && grid[r][c-1] == 0) {
      seen[r][c-1] = true;
      q.push({r, c-1});
    }
    // Right
    if (c < m-1 && !seen[r][c+1] && grid[r][c+1] == 0) {
      seen[r][c+1] = true;
      q.push({r, c+1});
    }
  }
  
  return false;
}


int main() {
  vector<vector<int>> grid = {{0, 0, 0, 0}, 
                              {1, 0, 0, 0}, 
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};
  
  cout << hasPath(0, 0, 1, 1, grid) << endl;
  
  
  return 0;
}

// grid is empty
// end is an obstacle
// start/end out of bounds
// malformed grid input

