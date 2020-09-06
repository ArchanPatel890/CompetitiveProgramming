#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string a, string b, int alphabet) {
    int n = a.size();
    vector<vector<int>> g(alphabet);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "-1" << "\n";
            return;
        }    
        else if (a[i] < b[i]) {
            g[a[i]-'a'].push_back(b[i]-'a');
            g[b[i]-'a'].push_back(a[i]-'a');
        }
    }

    vector<int> color(alphabet, 0);
    function<void(int)> dfs = [&](int u) {
        if (color[u]) return;
        color[u] = 1;
        for (int v : g[u]) {
            if (!color[v])
                dfs(v);
        }
    };

    int ans = alphabet;
    for (int i = 0; i < alphabet; ++i) {
        if (!color[i]) {
            dfs(i);
            --ans;
        }
    }
    
    cout << ans << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int i = 0;
    REP (i, t) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        solve(a, b, 20);
    }
    return 0;
}