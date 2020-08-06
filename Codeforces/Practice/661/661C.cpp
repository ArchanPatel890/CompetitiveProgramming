#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(vector<int> w) {
    sort(w.begin(), w.end());
    int n = w.size();
    int wmax = INT_MIN;
    int wmin = INT_MAX;
    for (int wi : w) {
        wmax = max(wmax, wi);
        wmin = min(wmin, wi);
    }

    int mcnt = 0;
    for (int s = 2*wmin; s <= 2*wmax; ++s) {
        int left = 0;
        int right = n-1;
        int cnt = 0;
        while (left < right) {
            int sum = w[left] + w[right];
            if (sum == s) {
                ++cnt;
                ++left;
                --right;
            }
            else if (sum < s) {
                ++left;
            }
            else {
                --right;
            }
        }
        mcnt = max(mcnt, cnt);
    }

    cout << mcnt << endl;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);

        int i;
        REP(i, n) {
            cin >> w[i];
        }

        solve(w);
    }
    
    return 0;
}