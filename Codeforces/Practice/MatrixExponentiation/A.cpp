#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int n, double p) {
    float p_happy = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            p_happy = p_happy * (1-p) + (1-p_happy) * p;
        }
        p = p*(1-p) + (1-p)*p;
        n /= 2;
    }

    cout << p_happy << "\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    double p;
    cin >> n >> p;
    solve(n, p);
    
    return 0;
}