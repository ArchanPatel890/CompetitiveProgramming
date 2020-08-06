#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> a) {
    sort(a.begin(), a.end());
    bool valid = true;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] - a[i-1] > 1) {
            valid = false;
            break;
        }
    }

    cout << (valid ? "YES" : "NO") << endl;
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
        REP(i, n) {
            cin >> a[i];
        }
        solve(a);
    }
    
    return 0;
}