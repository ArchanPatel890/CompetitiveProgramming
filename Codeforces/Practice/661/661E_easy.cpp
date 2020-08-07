#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

long long getDiff(int i, vector<int>& w, vector<int>& children) {
    return w[i] * 1ll * children[i] - (w[i]/2) * 1ll *children[i];
}

void dfs(vector<vector<pair<int, int>>>& g, vector<int>& children, int v, int p = -1) {
    if (g[v].size() == 1) children[p] = 1;
    for (auto [to, id] : g[v]) {
        if (id == p) continue;
        dfs(g, children, to, id);
        if (p != -1) children[p] += children[id];
    }
}

void solve(vector<vector<pair<int, int>>>& g, vector<int>& w, int S) {
    int n = g.size();
    vector<int> children(g.size(), 0);

    dfs(g, children, 0);
    set<pair<long long, int>> st;
    long long cur = 0;
    for (int i = 0; i < n-1; ++i) {
        st.insert({getDiff(i, w, children), i});
        cur += w[i] * 1ll * children[i];
    }

    int ans = 0;
    while (cur > S) {
        int id = st.rbegin()->second;
        st.erase(prev(st.end()));
        cur -= getDiff(id, w, children);
        w[id] /= 2;
        st.insert({getDiff(id, w, children), id});
        ++ans;
    }
    cout << ans << endl;
}

// runtime error on large test case.
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n, S;
        cin >> n >> S;
        vector<int> w(n);
        vector<vector<pair<int, int>>> g(n);
        int i;
        REP(i, n-1) {
            int x, y;
            cin >> x >> y >> w[i];
            --x;
            --y;
            g[x].push_back({y, i});
            g[y].push_back({x, i});
        }
        solve(g, w, S);
    }
    
    return 0;
}