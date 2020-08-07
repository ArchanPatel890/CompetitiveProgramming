#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int>& a) {
    unordered_map<int, int> cnt;
    int fmax = INT_MIN;
    int cntmax = 0;
    for (int i : a) {
        cnt[i]++;
        if (cnt[i] > cntmax) {
            cntmax = cnt[i];
            fmax = i;
        }
    }
    cnt.erase(fmax);
    int cntrest = 0;
    int counter = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second == cntmax) {
            counter++;
        }
        else {
            cntrest += it->second;
        }
    }
    counter += cntrest/(cntmax-1);
    cout << counter << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int i;
        cin >> n;
        vector<int> a(n);
        REP(i, n) {
            cin >> a[i];
        }
        solve(a);
    }

    return 0;
}