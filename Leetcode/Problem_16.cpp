#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int minDist = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n-2; ++i) {
            int twoSum = twoSumClosest(nums, target - nums[i], i+1, n-1);
            int sum = twoSum + nums[i];
            int dist = abs(target - (twoSum + nums[i]));
            if (minDist > dist) {
                ans = sum;
                minDist = dist;
            }
        }

        return ans;
    }

    int twoSumClosest(vector<int>& nums, int target, int left, int right) {
        int closestSum = 0;
        int minDist = INT_MAX;
        while (left < right) {
            int sum = nums[left] + nums[right];
            int dist = abs(target - sum);
            if (minDist > dist) {
                closestSum = sum;
                minDist = dist;
            }

            if (sum == target) {
                break;
            }
            else if (sum < target) {
                ++left;
            }
            else {
                --right;
            }
            
        }
        
        return closestSum;
    }
};
