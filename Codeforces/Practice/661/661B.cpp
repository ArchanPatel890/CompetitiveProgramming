#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> a, vector<int> b) {
    int n = a.size();
    int amin = INT_MAX;
    int bmin = INT_MAX;
    for (int i = 0; i < n; ++i) {
        amin = min(amin, a[i]);
        bmin = min(bmin, b[i]);
    }

    long long moves = 0;
    for (int i = 0; i < n; ++i) {
        int am = a[i] - amin;
        int bm = b[i] - bmin;
        moves += max(am, bm);
    } 

    cout << moves << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        int i;
        REP(i, n) {
            cin >> a[i];
        }
        REP(i, n) {
            cin >> b[i];
        }
        solve(a, b);
    }
    
    return 0;
}