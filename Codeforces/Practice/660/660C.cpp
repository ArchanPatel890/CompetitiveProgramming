#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int n, int m, vector<int>& p, vector<int>& h, vector<vector<int>>& g) {
    
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n, 0);
        vector<int> h(n, 0);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n-1; ++i) {
            int s, t;
            cin >> s >> t;
            g[s].push_back(t);
            g[t].push_back(s);
        }
        solve(n, m, p, h, g);
    }
    
    return 0;
}