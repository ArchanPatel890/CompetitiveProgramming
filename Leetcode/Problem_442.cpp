#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) {
            n = abs(n);
            nums[n-1] = -nums[n-1];
            if (nums[n-1] > 0) {
                ans.push_back(n);
            }
        }

        return ans;
    }
};
