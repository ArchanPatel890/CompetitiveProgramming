#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int curr = 0;
        for (int num : nums) {
            if (num & 1)
                ++curr;
            else {
                if (curr > max) {
                    max = curr;
                }
                curr = 0;
            }
        }
        // Account for the all ones array case.
        if (curr > max) {
            max = curr;
        }
        return max;
    }
};