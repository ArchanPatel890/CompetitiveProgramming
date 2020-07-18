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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq(n, 0);

        for (int i = 1; i < n; ++i) {
            if (seq.back() < nums[i]) {
                seq.push_back(nums[i]);
            }
            int index = binarySearchIdx(nums[i], seq);
            seq[index] = nums[i];
        }

        return seq.size();
    }

private: 
    int binarySearchIdx(int target, vector<int>& a) {
        int left = 0;
        int right = a.size();
        int mid = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == target) {
                return mid;
            }
            else if (a[mid] > target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return mid;
    }
};