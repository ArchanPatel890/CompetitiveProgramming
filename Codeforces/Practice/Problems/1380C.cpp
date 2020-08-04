#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> a, int n, int x) {
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 0;
    int teams = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt; 
        if (cnt * a[i] >= x) {
            ++teams;
            cnt = 0;
        }
    }

    cout << teams << "\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int i;
        REP(i, n) {
            cin >> a[i];
        }
        solve(a, n, x);
    }
    
    return 0;
}