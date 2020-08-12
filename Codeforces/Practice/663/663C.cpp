#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long factmod(long long n, long long p) {
    long long res = 1;
    for (long long i = 2; i <= n; ++i) {
        res = (res * i) % p;
    }
    return res % p;
}

void solve(int n) {
    long long trees = binpow(2, n-1, MOD);
    long long perm = factmod(n, MOD);
    long long ans = perm - trees;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    solve(n);

    return 0;
}