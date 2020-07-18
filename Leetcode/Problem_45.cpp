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
    /**
     * Find the minimum number of steps it takes to jump out of the array.
     * Because all of the numbers are positive, there is no advantage to moving
     * leftward. 
     * We only need to consider the maximum possible reachable distance, and the
     * steps it takes to reach this point.
     */
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        vector<int> steps(n);
        int end = 0;
        for (int i = 0; i < n && i <= end; ++i) {
            int max_dist = nums[i] + i;

            // Set the the newly reachable indicies to have a step value one greater
            // than the current step value.
            if (max_dist > end) {
                int curr_steps = steps[i] + 1;
                if (max_dist >= n-1) return curr_steps;

                // We only need to step values for newly reachable indices, since 
                // we can't lower the number of steps as we go.
                int start = end + 1;
                end = max_dist;
                for (int j = start; j <= end; ++j) {
                    steps[j] = curr_steps;
                }
            }
        }

        return -1;
    }
};