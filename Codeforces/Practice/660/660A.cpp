#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int num) {
    unordered_set<int> relative_primes({6, 10, 14});
    int min_ints = 6 + 10 + 14;
    int rem = num - min_ints;
    if (num > min_ints) {
        cout << "YES\n";
        if (relative_primes.count(rem)) {
            printf("%d %d %d %d\n", 6, 10, 15, rem-1);
        }
        else {
            printf("%d %d %d %d\n", 6, 10, 14, rem);
        }
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int num;
        cin >> num;
        solve(num);
    }
    
    return 0;
}