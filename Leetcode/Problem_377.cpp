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
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long> ways(target+1, 0);
        ways[0] = 1;

        for (int i = 1; i <= target; ++i) {
            long paths = 0;
            for (int j = 0; j < n && nums[j] <= i; ++j) {
                paths += ways[i - nums[j]];
            }
            ways[i] = paths;
        }
        
        return ways[target];
    }
};