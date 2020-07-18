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
    vector<string> generateParenthesis(int n) {
        char* seq = new char [2*n + 1];
        seq[2*n] = '\0';
        vector<string> ans;
        printParentheses(n, 0, 0, seq, ans);
        return ans;
    }

private:
    void printParentheses(int n, int open, int closed, char* seq, vector<string>& ans) {
        if (closed == n) {
            ans.push_back(string(seq));
            return;
        }
        if (open < n) {
            
            seq[open+closed] = '(';
            printParentheses(n, open + 1, closed, seq, ans);
        }
        if (closed < open) {
            seq[open+closed] = ')';
            printParentheses(n, open, closed + 1, seq, ans);
        }
    }
};