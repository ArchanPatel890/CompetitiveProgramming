#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

typedef pair<int, vector<int>&> pv; 

void solve(vector<int> r, vector<int> g, vector<int> b) {
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    int m = r.size(), n = g.size(), o = b.size();
    vector<vector<vector<int>>>dp (m+1, vector<vector<int>>(n+1, vector<int>(o+1, 0)));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= o; ++k) {
                if (i && j) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + r[i-1]*g[j-1]);
                }
                if (i && k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + r[i-1]*b[k-1]);
                }
                if (j && k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[j-1]*b[k-1]);
                }
            }
        }
    }
    cout << dp[m][n][o] << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> red(r), green(g), blue(b);
    int i;
    REP (i, r) {
        cin >> red[i];
    }
    REP (i, g) {
        cin >> green[i];
    }
    REP (i, b) {
        cin >> blue[i];
    }
    solve(red, green, blue);
    return 0;
}