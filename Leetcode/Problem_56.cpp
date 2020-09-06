#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), 
            intervals.end(),
            [](vector<int> a, vector<int> b)
            {
                return a[0] < b[0];
            });
        
        vector<vector<int>> ans;
        int n = intervals.size();
        int l = 0;
        int r = 0;
        while (r < n) {
            int start = intervals[l][0];
            int end = intervals[l][1];
            while (r < n && end >= intervals[r][0]) {
                end = max(end, intervals[r][1]);
                r++;
            }
            l = r;
            ans.push_back({start, end});
        }

        return ans;
    }
};