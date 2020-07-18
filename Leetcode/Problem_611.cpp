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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n < 3) {
            return 0;
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int k = i + 2;
            for (int j = i+1; j < n && nums[i] != 0; ++j ) {
                int sum = nums[i] + nums[j];
                k = binarySearchIdx(sum, k, n-1, nums);
                count += k - j - 1;
            }
        }

        return count;
    }

    int binarySearchIdx(int key, int left, int right, vector<int>& nums) {
        int mid = 0;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] >= key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
