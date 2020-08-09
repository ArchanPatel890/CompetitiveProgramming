#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

int rosize(int u, int v, vector<vector<char>>& g) {
    int m = g.size();
    int n = g[0].size();
    char t = g[u][v];
    int i = 0;
    for (; i < min(m, n); ++i) {
        bool valid = true;
        int col = v + i;
        for (int j = u; col < n && j < m && j <= u + i; ++j) {
            if (g[j][col] != t) {
                valid = false;
                break;
            }
        }
        int row = u + i;
        for (int j = v; row < m && j < n && j <= v + i; ++j) {
            if (g[row][j] != t) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            break;
        }
        else {
        }
    }
    
    return i+1;
}

void solve(vector<vector<char>>& g, int m, int n) {
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!seen[i][j]) {
                int ro = rosize(i, j, g);
                ans += ro;
            }
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int m;
    int n;
    cin >> m >> n;
    cout << m << n << endl;
    vector<vector<char>> g(m, vector<char>(n));
    int i, j;
    REP(i, m) {
        REP(j, n) {
            cin >> g[i][j];
        }
    }
    solve(g, m, n);

    return 0;
}