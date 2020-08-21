#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solve(vector<int>& a, int n) {
    auto b = a;
    sort(b.begin(), b.end());
    int mine = b[0];

    REP (i, n) {
        if (a[i] % mine != 0 && a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int i;
        REP (i, n) {
            cin >> a[i];
        }
        solve(a, n);
    }
    
    return 0;
}