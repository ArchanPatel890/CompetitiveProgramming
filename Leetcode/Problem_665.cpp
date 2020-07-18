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
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        
        int isIncreasing = true;
        if (nums[0] > nums[1]) {
            isIncreasing = false;
            nums[0] = nums[1];
        }

        for (int i = 1; i < n-1; ++i) {
            if (nums[i+1] < nums[i]) {
                if (isIncreasing) {
                    // Fix in the case where next is smaller than prev
                    if (nums[i-1] > nums[i+1]) {
                        nums[i+1] = nums[i];
                    } 
                    // Fix the case where next is bigger than prev.
                    else
                    {
                        nums[i] = nums[i+1];
                    }
                    isIncreasing = false;
                } else
                {
                    return false;
                }
            }
        }
        return true;
    }
};