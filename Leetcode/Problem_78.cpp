#include <bits/stdc++.h>

using namespace std;

/**
 * Power set of elements must have 2^n elements each of size O(n). Thus the complexity is O(n * 2^n).
 * Memory can be saved by using a bitmask to iterate over the 2^n members of the set.
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> accu;
        powerSet(nums, 0, accu, ans);
        return ans;
    }

    void powerSet(vector<int>& nums, int i, vector<int>& accu, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.emplace_back(accu);
            return;
        }

        powerSet(nums, i+1, accu, ans);
        accu.push_back(nums[i]);
        powerSet(nums, i+1, accu, ans);
        accu.pop_back();
    }
};