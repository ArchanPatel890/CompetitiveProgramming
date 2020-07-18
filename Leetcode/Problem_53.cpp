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
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int sum = nums[0];
        int max_sum = sum;
        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            sum=max(sum, 0);
        }

        return max_sum;
    }
};