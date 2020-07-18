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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> row(i, 1);
            for (int j = 1; j < i-1; ++j) {
                row[j] = rows[i-1][j-1] + rows[i-1][j];
            }
            rows.push_back(row);
        }
        
        return rows;
    }
};