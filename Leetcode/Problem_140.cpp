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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memo;
        unordered_set<string> dict;
        for (auto str : wordDict) {
            dict.insert(str);
        }

        return wordBreakDFS(s, dict, memo);
    }

    vector<string> wordBreakDFS(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo)  {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        if (dict.count(s)) { 
            result.push_back(s);
        }

        int n = s.size();
        for (int i = 1; i < n; ++i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                string prefix = s.substr(0, i);
                vector<string> remaining = wordBreakDFS(prefix, dict, memo);
                for (auto str : remaining) {
                    result.push_back(str + (str.empty() ? "" : " ") + word);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};
