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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),  nums.end());
        vector<int> stack;
        vector<vector<int>> ans;
        nSum(4, target, 0, nums.size()-1, nums, stack, ans);
        return ans;
    }

    void twoSum(int target, int left, int right, vector<int>& nums, vector<int>& stack, vector<vector<int>>& ans) {
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                stack.push_back(nums[left]);
                stack.push_back(nums[right]);
                ans.emplace_back(stack);
                stack.pop_back();
                stack.pop_back();

                // Move pointer forward to avoid duplicates
                while (left < right && nums[left] == nums[left+1]) {
                    ++left;
                }
                while (left < right && nums[right] == nums[right-1]) {
                    --right;
                }
                ++left;
                --right;
            }
            else if (sum < target) {
                ++left;
            }
            else {
                --right;
            }
        }
    }

    void nSum(int n, int target, int left, int right, vector<int>& nums, vector<int>& stack, vector<vector<int>>& ans) {
        if (n < 2) {
            // Replace with 2sum with hashset.
            return;
        }
        if (n == 2) {
            twoSum(target, left, right, nums, stack, ans);
        }

        int end = right-n+2;
        for (int i = left; i < end; ++i) {
            stack.push_back(nums[i]);
            nSum(n-1, target-nums[i], i+1, right, nums, stack, ans);
            stack.pop_back();
            while (i < right && nums[i] == nums[i+1]) {
                ++i;
            }
        }
    }
};
