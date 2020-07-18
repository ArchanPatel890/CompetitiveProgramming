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
    vector<int> shuffle(vector<int>& nums, int n) {
        if (n <= 0) {
            return {};
        }
        vector<int> shuffled(2*n);
        int yStart = n;
        for (int i = 0; i < n; ++i) {
            shuffled[2*i] = nums[i];
            shuffled[2*i+1] = nums[yStart+i];
        }

        return shuffled;
    }
};
