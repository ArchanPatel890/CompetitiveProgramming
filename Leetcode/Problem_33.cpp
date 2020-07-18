#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearchRotated(0, nums.size()-1, target, nums);
    }

    int binarySearchRotated(int l, int r, int t, vector<int>& nums) {
        while(l <= r) {  
            int mid = (l + r) / 2;            
            if (nums[mid] == t) {
                return mid;
            }
            if (nums[mid] > nums[r]) {
                if (t > nums[mid] || t <= nums[r]) l = mid + 1;    
                else r = mid - 1;                                                               
            }
            else if (nums[mid] == nums[r]) {
                r--;   // may cause linear time here, e.g. [7, 8, 9, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], search for 0
            }
            else {
                if(t <= nums[r] && t > nums[mid]) l = mid + 1; 
                else r = mid - 1;                                                               
            }
        }
        return -1;   
    }
};
