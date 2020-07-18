#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> match(m+1, vector<bool>(n+1, false));

        match[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] != '*') break;
            match[0][j] = true;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                auto cp = p[j-1];
                if (cp == '*') {
                    match[i][j] = match[i][j-1] || match[i-1][j];
                }
                else if (cp == '?' || cp == s[i-1]) {
                    match[i][j] = match[i-1][j-1];
                }
            }
        }
        
        return match[m][n];
    }
};
