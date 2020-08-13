#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int r, int g, int b, int w) {
    bool op = false;
    if (r > 0 && g > 0 && b > 0) {
        op = true;
    }
    int odd = (r&1) + (g&1) + (b&1);
    bool wodd = w & 1;
    bool palindrome = false;
    if ((odd == 0) 
        || (odd == 1 && w % 2 == 0)
        || (odd == 2 && op && wodd)
        || (odd == 3 && op))
    {
        palindrome = true;
    }

    cout << (palindrome ? "Yes" : "No") << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while (t--) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        solve(r, g, b, w);
    }

    return 0;
}