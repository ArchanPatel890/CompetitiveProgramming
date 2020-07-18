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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        stack<int> buf;
        vector<int> mins(n);
        mins[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            mins[i] = min(mins[i-1], nums[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] > mins[i]) {
                while (!buf.empty() && buf.top() <= mins[i]) {
                    buf.pop();
                }
                if (!buf.empty() && buf.top() < nums[i]) {
                    return true;
                }
                buf.push(nums[i]);
            }
        }
        return false;
    }
};
