#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string s) {
    int ans = INT_MAX;
    int n = s.length();
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            vector<int> targets{ i, j };
            int len = 0;
            int t = 0;
            for (char c : s) {
                if (c - '0' == targets[t]) {
                    t = (t + 1) % 2;
                    ++len; 
                }
            }
            if (i != j && len % 2 == 1) {
                --len;
            }
            ans = min(ans, n - len);
        }
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
