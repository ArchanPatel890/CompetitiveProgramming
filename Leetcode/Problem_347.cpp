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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) {
            return nums;
        }

        map<int, int> count;
        for (int i = 0; i < n; ++i) {
            count[nums[i]]++;
        }

        struct pair_cmp
        {
            auto operator()(pair<int, int> a, pair<int, int> b ) const
                -> bool
            { return a.second > b.second; }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> q;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (q.size() < k) {
                q.push(make_pair(it->first, it->second));
            }
            else {
                if (it->second > q.top().second) {
                    q.push(make_pair(it->first, it->second));
                    q.pop();
                }
            }
        }

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            auto p = q.top();
            ans[i] = p.first;
            q.pop();
        }

        return ans;
    }
};
