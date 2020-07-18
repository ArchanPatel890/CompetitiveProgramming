#include <iostream>  
#include <iomanip>
#include <fstream>
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

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charidx;
        
        int start = 0;
        int max = 0;
        int i;
        int diff;
        for (i = 0; i < s.length(); ++i) {
            int idx = charidx[s[i]];
            if (idx) {
                diff = i - start;
                if (diff > max) {
                    max = diff;
                }
                if (start < idx) 
                    start = idx;
            }
            charidx[s[i]] = i + 1;
        }
        diff = i - start;
        if (diff > max) {
            max = diff;
        }
        return max;
    }
};