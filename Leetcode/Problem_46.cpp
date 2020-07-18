#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flags(n, 0);
        vector<int> accu(n);
        vector<vector<int>> ans;
        gen(0, nums, flags, accu, ans);
        return ans;
    }

    void gen(int idx, vector<int>& nums, vector<bool>& flags, vector<int>& accu, vector<vector<int>>& ans) {
        int n = nums.size();
        if (idx == n) {
            ans.emplace_back(accu);
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (flags[i]) continue;
                accu[idx] =  nums[i];
                flags[i] = true;
                gen(idx+1, nums, flags, accu, ans);
                flags[i] = false;
            }
        }
    }
};
