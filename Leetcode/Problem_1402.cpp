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
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        if (n == 0) {
            return 0;
        }

        sort(satisfaction.begin(), satisfaction.end());
        
        vector<int> suffix_sum(n+1);
        suffix_sum[n] = 0;
        for (int i = n-1; i >= 0; --i) {
            suffix_sum[i] = satisfaction[i] + suffix_sum[i+1];
        }

        int start = 0;
        for (; start < n; ++start) {
            if (-satisfaction[start] < suffix_sum[start+1]) {
                break;
            }
        }
        
        int maxSat = 0;
        for (int i = 1, j = start; j < n; ++i, ++j) {
            maxSat += i * satisfaction[j];
        }
        return maxSat;
    }
};
