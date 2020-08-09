#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int zero, int one, int two) {
    stringstream ss;
    int i;
    string last = "";
    if (zero) {
        last = "0";
        ss << last;
    }
    REP(i, zero) {
        ss << last;
    }
    if (two) {
        if (last == "0") --one;
        last = "1";
        ss << last;
    }
    REP(i, two) {
        ss << last;
    }
    if (last.empty()) {
        last = "1";
        ss << last;
    }
    REP(i, one) {
        if (last == "0") {
            last = "1";
        }
        else {
            last = "0";
        }  
        ss << last;
    }

    cout << ss.str() << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        solve(n0, n1, n2);
    }
    
    return 0;
}