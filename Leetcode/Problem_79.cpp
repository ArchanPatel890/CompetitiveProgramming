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
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (checkExists(i, j, 0, word, board, seen)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool checkExists(int r, int c, int index, string& word, vector<vector<char>>& board, vector<vector<bool>>& seen) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return false;
        }
        if (seen[r][c]) {
            return false;
        }
        if (word[index] != board[r][c]) {
            return false;
        }
        if (index == word.length()-1) {
            return true;
        }
        
        bool found = false;
        seen[r][c] = true;
        if (checkExists(r-1, c, index + 1, word, board, seen)
            || checkExists(r+1, c, index + 1, word, board, seen)
            || checkExists(r, c-1, index + 1, word, board, seen)
            || checkExists(r, c+1, index + 1, word, board, seen)) 
        {
            return true;
        }
        seen[r][c] = false;

        return found;
    }
};