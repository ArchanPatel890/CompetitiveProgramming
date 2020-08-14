#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, int n) {
    unordered_map<long long, long long> cnt;
    cnt[0]++;
    long long sum = 0;
    long long ans = 0;
    int i;
    REP(i, n) {
        sum += a[i];
        ans += cnt[sum - (i+1)];
        cnt[sum - (i+1)]++;
    }
    
    cout << ans << endl;
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
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        solve(a, n);
    }
    
    return 0;
}