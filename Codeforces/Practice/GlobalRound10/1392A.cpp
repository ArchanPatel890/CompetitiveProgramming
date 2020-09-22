#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, int n) {
    bool equal = true;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] != a[i+1]) {
            equal = false;
            break;
        }
    }

    if (equal) {
        cout << n << endl;
    }
    else {
        cout << 1 << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int i;
        REP (i, n) {
            cin >> a[i];
        }
        solve(a, n);
    }
    
    return 0;
}