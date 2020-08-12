#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;


void solve(vector<vector<char>>& g, int n, int m) {
    if (min(n, m) > 3) {
        cout << "-1\n";
        return;
    }

    
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int m;
    int n;
    cin >> m >> n;
    cout << m << n << endl;
    vector<vector<int>> g(m, vector<int>(n));
    int i, j;
    REP(i, m) {
        REP(j, n) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }
    solve(g, m, n);

    return 0;
}