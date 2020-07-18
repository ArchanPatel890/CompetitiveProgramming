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
    // Using a stack
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        stack<vector<int>> levels;
        int water = 0;
        int curr_height = 0;
        for (int i = 0; i < n; ++i) {
            while (!levels.empty() && levels.top()[0] <= height[i]) {
                auto prev = levels.top();
                levels.pop();
                water += (prev[0] - curr_height) * (i - prev[1] - 1);
                curr_height = prev[0];
            }

            if (!levels.empty() && levels.top()[0] > height[i]) {
                water += (height[i] - curr_height) * (i - levels.top()[1] - 1);
            }

            if (levels.empty() || levels.top()[0] > height[i]) {
                levels.push({height[i], i});
            }
            curr_height = height[i];
        }

        return water;
    }

    // Using two pointers
    int trapPointers(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
