#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a, vector<int>& e) {
    unordered_map<int, int> cnt;
    for (int i : a) {
        cnt[i]++;
    }

    int sq = 0;
    int pairs = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        pairs += it->second / 2;
        sq += it->second / 4;
    }

    for (int i : e) {
        if (i < 0) {
            if (cnt[-i] % 4 == 0 ) {
                sq--;
            }
            if (cnt[-i] % 2 == 0) {
                pairs--;
            }
            cnt[-i]--;
        }
        else {
            cnt[i]++;
            if (cnt[i] % 4 == 0) {
                sq++;
            }
            if (cnt[i] % 2 == 0) {
                pairs++;
            }
        }
        
        cout << ((sq >= 2 || sq >= 1 && (pairs - 2*sq) >= 2) ? "YES" : "NO") << endl;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int i;
    REP(i, n) {
        cin >> a[i];
    }
    int events;
    cin >> events;
    vector<int> e(events);
    REP(i, events) {
        char op;
        int d;
        cin >> op >> d;
        if (op == '+') {
            e[i] = d;
        }
        else {
            e[i] = -d;
        }
    }
    solve(a, e);

    return 0;
}