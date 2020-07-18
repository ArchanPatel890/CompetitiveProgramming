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
#include <cmath>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> flips;
        int count = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != flips.size() % 2 ? 0 : 1) {
                ++count;
                flips.push(i + K - 1);
            }
            if (!flips.empty() && flips.front() <= i) {
                flips.pop();
            }
        }

        return flips.empty() ? count : -1;
    }
};