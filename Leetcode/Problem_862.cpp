#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + A[i];
        }

        deque<int> dq;
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= K) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
