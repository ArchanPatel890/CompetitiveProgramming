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
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return nums;
        
        vector<int> ans(len);
        ans[0] = 1;
        for (int i = 0; i < len-1; ++i) {
            ans[i+1] = ans[i] * nums[i];
        }
        int prod = nums[len-1];
        for (int i = len-1; i > 0; --i) {
            ans[i-1] = ans[i-1] * prod;
            prod *= nums[i-1];
        }

        return ans;
    }
};