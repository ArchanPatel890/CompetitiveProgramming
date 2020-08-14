#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, int n) {
    vector<int> b(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i-1] + a[i-1];
    }

    int cnt = 0;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i+l <= n; ++i) {
            if ((b[i+l] - b[i]) == l) ++cnt;
        }
    }

    cout << cnt << endl;
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int i;
        REP (i, n) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        solve(a, n);
    }
    
    return 0;
}