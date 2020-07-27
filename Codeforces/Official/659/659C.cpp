#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string a, string b) {
    int n = a.size();
    unordered_map<char, char> mapping;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "-1" << "\n";
            return;
        }    
        if (mapping.count(a[i]) == 0 || mapping[a[i]] > b[i]) {
            mapping[a[i]] = b[i];
            a[i] = b[i];
            --i;
        }
    }

    for (int i = 0; i < n; ++i) {
        char curr = a[i];
        while (mapping.count(curr) && curr != mapping[curr]) {
            curr = mapping[curr];
            if (curr == b[i]) break;
        }
        if (curr != b[i]) {
            cout << "-1\n";
            return;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 20; ++i) {
        if (mapping.count(char(i+'a')) && mapping[(char) (i+'a')] != (char)i+'a') {
            ++cnt;
        }
    }
    cout << cnt << "\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int i = 0;
    REP (i, t) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}