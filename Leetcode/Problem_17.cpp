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
    map<char, string> num_to_char = 
    {
        {'1', " "}, 
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        char* seq = new char [digits.length()+1];
        strcpy(seq, digits.c_str());
        
        vector<string> ans;
        printCombinations(digits, seq, 0, digits.length(), ans);
        return ans;
    }

private:
    void printCombinations(string x,  char* seq, int i, int len, vector<string>& ans) {
        if (x.empty()) {
            return;
        }
        if (i == len) {
            ans.push_back(string(seq));
        }
        
        for(char c : num_to_char[x[i]]) {
            seq[i] = c;
            printCombinations(x, seq, i+1, len, ans);
        }
    }
};