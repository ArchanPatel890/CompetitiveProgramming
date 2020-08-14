#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string s) {
    vector<int> ones;
    int i;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (s[i] == '1') {
            ++cnt;
            ++i;
        }
        if (cnt) {
            ones.push_back(cnt);
        }
    }
    sort(ones.begin(), ones.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < ones.size(); i+=2) {
        ans += ones[i];
    }
    cout << ans << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }
    
    return 0;
}