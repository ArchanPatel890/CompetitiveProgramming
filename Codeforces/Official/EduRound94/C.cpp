#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string s, int x) {
    int n = s.length();
    string w = string(n, '1');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i-x >= 0) w[i-x] = '0';
            if (i+x < n) w[i+x] = '0';
        }
    }

    string f = string(n, '0');
    for (int i = 0; i < n; ++i) {
        if (i-x >= 0) f[i] = ((w[i-x] == '1') ? '1' : '0');
        if (f[i] == '0' && i+x < n) f[i] = ((w[i+x] == '1') ? '1' : '0');
    }

    if (f != s) {
        cout << "-1\n";
    }
    else {
        cout << w << endl;
    }
}

int main() {    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        solve(s, x);
    }
    
    return 0;
}