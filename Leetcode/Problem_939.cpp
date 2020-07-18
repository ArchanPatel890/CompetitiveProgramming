#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, unordered_set<int>> ps;
        for (auto p: points) {
            ps[p[0]].insert(p[1]);
        }

        int min_area = INT_MAX;
        for (int i = 0; i < n; ++i) {
            auto p1 = points[i];
            for (int j = i+1; j < n; ++j) {
                auto p2 = points[j];
                if (p1[0] != p2[0] && p1[1] != p2[1]
                    && ps.find(p1[0]) != ps.end() && ps[p1[0]].count(p2[1])
                    && ps.find(p2[0]) != ps.end() && ps[p2[0]].count(p1[1])) 
                {
                    min_area = min(min_area, abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]));
                }
            }
        }

        return min_area == INT_MAX ? 0 : min_area;
    }
};
