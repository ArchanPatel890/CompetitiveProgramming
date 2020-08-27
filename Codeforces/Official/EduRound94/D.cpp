#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, int n) {
    vector<vector<int>> c(n+1, vector<int>(n+1, 0));
    long long total = 0;
    for (int k = n-2; k >= 0; --k) {
        int cnt = 0;
        for (int l = k+1; l < n; ++l) {
            c[a[k]][a[l]]++;
        }

        int j = k-1;

        for (int i = 0; i < j; ++i) {
            total += c[a[i]][a[j]];
        }
    }

    cout << total << endl;
}

int main() {    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int i;
        vector<int> a(n);
        REP (i, n) {
            cin >> a[i];
        }
        solve(a, n);
    }
    
    return 0;
}