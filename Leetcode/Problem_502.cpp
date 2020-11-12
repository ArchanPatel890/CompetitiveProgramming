#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> pnc;
        for (int i = 0; i < n; ++i) {
            pnc.push_back({Capital[i], Profits[i]});
        }
        sort(pnc.begin(), pnc.end());
        priority_queue<int> pq;
        int l = 0;
        int total_capital = W;
        while (k) {
            while (l < n && pnc[l].first <= total_capital) {
                pq.push(pnc[l].second);
                ++l;
            }
            if (pq.empty()) break;
            else {
                total_capital += pq.top();
                pq.pop();
                --k;
            }
        }

        return total_capital;
    }
};