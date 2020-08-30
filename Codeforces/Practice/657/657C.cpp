#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

const int MOD = 1000000007;
const int MAXN = (1 << 9)-1;

void solve(vector<int>& a, int n, vector<int>& b, int m) {
    int i, j, k;

    REP(i, MAXN+1) {
        bool works = true;
        REP(j, n) {
            bool valid = false;
            REP(k, m) {
                if ((a[j] & b[k] | i) == i) {
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << i << endl;
            break;
        }
        works = true;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int i;
    REP(i, n) {
        cin >> a[i];
    }
    REP(i, m) {
        cin >> b[i];
    }
    solve(a, n, b, m);

    return 0;
}