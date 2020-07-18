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
#include <set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> char_count(128, 0);
        int count = s.length();
        for (auto c : s) {
            char_count[c]++;
        }

        for (auto c: t) {
            char_count[c]--;
            if (char_count[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
