#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> a, int n, int k, int z) {
    int ans = a[0];
    int max_pair = a[0] + a[1];
    int sum = a[0];
    for (int i = 1; i <= k; ++i) {
        max_pair = max(max_pair, a[i] + a[i-1]);
        sum += a[i];
        int max_left = min((k-i)/2, z);
        int rem = ((k - i - max_left*2) > 0 && max_left < z) ? a[i-1] : 0;
        ans = max(ans, max_left * max_pair + sum + rem);
    }
    cout << ans << "\n";
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n, 0);
        int i;
        REP(i, n) {
            cin >> a[i];
        }
        solve(a, n, k, z);
    }
    
    return 0;
}
