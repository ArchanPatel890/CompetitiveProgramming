#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> a) {
    int ptr = a.size()-1;
    while (ptr > 0 && a[ptr-1] >= a[ptr]) {
        --ptr;
    }
    while (ptr > 0 && a[ptr-1] <= a[ptr]) {
        --ptr;
    }

    cout << ptr << "\n";
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