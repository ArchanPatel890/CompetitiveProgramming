#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int n, int k) {
    bool keven = (k % 2 == 0);
    bool neven = (n % 2 == 0);

    if (n <= k) {
        cout << (k-n) << endl;
    }
    else if ((keven && neven) || (!keven && !neven)) {
        cout << "0" << endl;
    }
    else {
        cout << "1" << endl;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    
    return 0;
}