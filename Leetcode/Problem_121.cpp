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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n; ++i) {
            int profit = prices[i] - min;
            if (profit > max_profit) {
                max_profit = profit;
            }

            if (prices[i] < min) {
                min = prices[i];
            }
        }

        return max_profit;
    }
};