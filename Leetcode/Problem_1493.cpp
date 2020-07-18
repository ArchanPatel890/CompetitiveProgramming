#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                ++cnt;
                ans = max(ans, cnt+prev);
            }
            else if (i < n-1 && !nums[i] && nums[i+1]) {
                prev = cnt;
                cnt = 0;
            }
            else {
                prev = 0;
                cnt = 0;
            }
        }

        return ans == n ? n - 1 : ans;
    }
};
