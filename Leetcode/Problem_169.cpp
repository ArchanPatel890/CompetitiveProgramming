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
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;
        for (auto num : nums) {
            if (num == element) {
                ++count;
            }
            else {
                --count;
                if (count < 0) {
                    element = num;
                    count = 1;
                }
            }
        }

        return element;
    }
};