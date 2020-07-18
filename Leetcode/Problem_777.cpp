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
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int m = J.size();
        for (int i = 0; i < m; ++i) {
            jewels.insert(J[i]);
        }
        
        int n = S.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (jewels.find(S[i]) != jewels.end()) {
                ++count;
            }
        }

        return count;
    }
};
