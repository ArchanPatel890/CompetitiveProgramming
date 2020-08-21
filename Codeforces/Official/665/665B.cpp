#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, vector<int>& b) {
    int ans = 0;
    if (a[2] >= b[1]) {
        ans += b[1] * 2;
        a[2] -= b[1];
        b[1] = 0;
    }
    else {
        ans += a[2] * 2;
        a[2] = 0;
        b[1] -= a[2];
    }

    b[2] = max(0, b[2] - a[2] - a[0]);
    ans -= b[2] * 2;
    cout << ans << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n = 3;
        vector<int> a(n), b(n);
        int i;
        REP (i, n) {
            cin >> a[i];
        }
        REP (i, n) {
            cin >> b[i];
        }
        solve(a, b);
    }
    
    return 0;
}