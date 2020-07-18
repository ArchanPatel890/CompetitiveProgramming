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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1);
        
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n) {
                count[n]++;
            }
            else {
                count[citations[i]]++;
            }
        }

        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }

        return 0;
    }
};
