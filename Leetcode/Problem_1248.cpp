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
    int n;
    int m;

    int minFlips(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        auto ret = FlipOrNotFlip(mat, 0, 0);
        return (ret >= 10000 ? -1 : ret);
    }

    int FlipOrNotFlip(vector<vector<int>> mat, int y, int x) {
        if(x == m) y++, x = 0;
        if(y == n) return isZeroMat(mat) ? 0:10000;

        auto ret1 = FlipOrNotFlip(mat, y, x+1);
        auto ret2 = FlipOrNotFlip(flip(mat, y, x), y, x+1) + 1;
        return min(ret1, ret2);
    }

    vector<vector<int>>& flip(vector<vector<int>>& mat, int y, int x) {
        mat[y][x] ^= 1;
        if(y - 1 >= 0) mat[y-1][x] ^= 1;
        if(y + 1 <  n) mat[y+1][x] ^= 1;
        if(x - 1 >= 0) mat[y][x-1] ^= 1;
        if(x + 1 <  m) mat[y][x+1] ^= 1;
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) {
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < m; ++j)
                if(mat[i][j])
                    return false;
        return true;
    }
};
