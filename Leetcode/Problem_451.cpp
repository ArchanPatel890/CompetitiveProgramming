#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cnt[c]++;
        }

        vector<pair<char, int>> kv;

        for (auto it : cnt) {
            kv.push_back(it);
        }

        sort(kv.begin(), kv.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });
        stringstream ss;
        for (auto p : kv) {
            for (int i = 0; i < p.second; ++i) {
                ss << p.first;
            }
        }

        return ss.str();
    }
};
