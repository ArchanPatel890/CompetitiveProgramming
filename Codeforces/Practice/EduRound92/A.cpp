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

void solve(int l, int r) {
    if (2 * l > r) {
        cout << "-1 -1\n";
    }
    else {
        printf("%d %d\n", l, 2*l);
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    
    return 0;
}