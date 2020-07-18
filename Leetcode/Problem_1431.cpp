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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        int n = candies.size();
        vector<bool> isGreatest(n, false);
        for (int i = 0; i < n; ++i) {
            if (maxCandies < candies[i]) {
                maxCandies = candies[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (candies[i] + extraCandies >= maxCandies) {
                isGreatest[i] = true;
            }
            else {
                isGreatest[i] = false;
            }
        }
        
        return isGreatest;
    }
};