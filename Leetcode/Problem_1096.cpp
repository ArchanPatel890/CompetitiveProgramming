#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<vector<string>> stack;
        int i = 0;
        auto result = eval(expression, i);
        set<string> dedup(result.begin(), result.end());
        vector<string> ans(dedup.begin(), dedup.end());
        return ans;
    }

    vector<string> crossProduct(vector<string>& x, vector<string>& y) {
        vector<string> ret;
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < y.size(); ++j) {
                ret.push_back(x[i] + y[j]);
            }
        }

        return ret;
    }

    vector<string> eval(string& exp, int& i) {
        vector<string> ret;
        vector<string> accu({""});
        vector<string> single({""});
        while (i < exp.size() && exp[i] != '}') {
            char curr = exp[i];

            // Opening brace recursive evaluation.
            if (curr == '{') {
                ++i;
                auto res = eval(exp, i);
                accu = crossProduct(accu, res);
            }

            // Comma add to current result set
            else if (curr == ',') {
                for (const string& s : accu) {
                    ret.push_back(s);
                }
                accu = vector<string>({""});
            }

            // Single character can add to accu.
            else {
                single[0] = exp[i];
                accu = crossProduct(accu, single);
            }
            ++i;
        }

        for (string& s : accu) {
            ret.push_back(s);
        }

        return ret;
    }
};
