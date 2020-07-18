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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n <= 1) {
            return;
        }

        for (int p = 0; p < n/2; ++p) {
            for (int offset = 0; offset < n-1-2*p; ++offset) {
                rotateInstance(p, offset, n, matrix);
            }
        }
    }

    void rotateInstance(int p, int offset, int n, vector<vector<int>>& matrix) {
        int temp = matrix[p][p + offset];
        swap(temp, matrix[p + offset][n-1-p]);
        swap(temp, matrix[n-1-p][n-1-p - offset]);
        swap(temp, matrix[n-1-p - offset][p]);
        swap(temp, matrix[p][p + offset]);
    };
};
