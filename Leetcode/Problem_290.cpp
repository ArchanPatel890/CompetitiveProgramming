#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
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
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        istringstream iss(str);
        for (string s; iss >> s;) {
            words.push_back(s);
        }
        
        if (words.size() != pattern.length()) {
            return false;
        }
        
        map<char, string> bijection;
        unordered_set<string> values;
        for (int i = 0; i < pattern.length(); ++i) {
            if (bijection.find(pattern[i]) == bijection.end()) {
                if (values.find(words[i]) == values.end()) {
                    bijection.emplace(pattern[i], words[i]);
                    values.insert(words[i]);
                }
                else {
                    return false;
                }
            }
            else {
                auto value = bijection[pattern[i]];
                if (value != words[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
