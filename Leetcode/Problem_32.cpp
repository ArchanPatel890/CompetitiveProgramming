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
    int longestValidParentheses(string s) {
        stack<int> lastvalid;
        int n = s.length();
        int maxValid = 0;
        lastvalid.push(-1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                lastvalid.push(i);
            else {
                lastvalid.pop();
                if (lastvalid.empty()) {
                    lastvalid.push(i);
                }
                else {
                    int last = i - lastvalid.top();
                    if (last > maxValid)
                        maxValid = last;
                }
            }
        }

        return maxValid;
    }
};