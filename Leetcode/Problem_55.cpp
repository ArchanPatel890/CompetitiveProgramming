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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }

        int furthest = 0;
        for (int i = 0; i < n && i <= furthest; ++i) {
            int dist = nums[i] + i;
            if (dist > furthest) furthest = dist;
            if (furthest >= n-1) return true;
        }

        return false;
    }
};
