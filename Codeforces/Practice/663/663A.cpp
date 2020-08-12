#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int n) {
    int l = 1;
    int r = n;
    while (l < r) {
        cout << l << " " << r << " ";
        ++l;
        --r;
    }
    if (l == r) {
        cout << l << endl;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}