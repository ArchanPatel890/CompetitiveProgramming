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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Check if first row contains a zero
        bool isFirstRow = false;
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]) {
                isFirstRow = true;
            }
        }

        // Check if first column contains a zero
        bool isFirstCol = false;
        for (int i = 1; i < m; ++i) {
            if (!matrix[i][0]) {
                isFirstCol = true;
            }
        }

        // Set with rows and cols are meant to be zeroed
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero the rows, except the first
        for (int i = 1; i < m; ++i) {
            if (!matrix[i][0]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the cols
        for (int j = 1; j < n; ++j) {
            if (!matrix[0][j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (isFirstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Zero thefirst col if needed
        if (isFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};