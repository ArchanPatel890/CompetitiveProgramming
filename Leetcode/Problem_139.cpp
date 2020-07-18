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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string s : wordDict) {
            dict.insert(s);
        }

        int n = s.size();
        vector<bool> isBreak(n, false);
        isBreak[0] = true;
        for (int i = 1; i <= n; ++i) {
            for(int j = i-1; j>=0; --j) {
                if (isBreak[j]) {
                    string remaining = s.substr(j, i-j);
                    if (dict.find(remaining) != dict.end()) {
                        isBreak[i] = true;
                    }
                }
            }
        }

        return isBreak[n];
    }
};