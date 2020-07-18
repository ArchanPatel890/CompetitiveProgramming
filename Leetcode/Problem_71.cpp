#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (n == 0) {
            return "";
        }

        vector<string> dir;
        int i = 0;
        stringstream ss;
        for (int i = 0; i < n; ++i) {
            while (i < n && path[i] == '/') {
                ++i;
            }
            while (i < n && path[i] != '/') {
                ss << path[i];
                ++i;
            }

            string next = ss.str();
            if (!next.empty()) dir.push_back(next);
            ss.str(string());
        }
        
        vector<string> dir_stack;
        for (string s : dir) {
            if (s == "..") {
                if (!dir_stack.empty()) dir_stack.pop_back();
            }
            else if (s == ".") {
                continue;
            }
            else {
                dir_stack.push_back(s);
            }
        }

        stringstream ans;
        for (string s : dir_stack) {
            ans << "/" << s;
        }

        return dir_stack.empty() ? "/" : ans.str();
    }
};
