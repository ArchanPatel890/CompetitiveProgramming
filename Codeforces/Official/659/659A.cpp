#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

string getStr(int n, char c) {
    stringstream ss;
    for (int i = 0; i < n; ++i) {
        ss << c;
    }
    return ss.str();
}

void solve(vector<int> a, int m) {

    int n = a.size();
    string curr = getStr(m+1, 'a');
    vector<string> strs;
    strs.emplace_back(curr);
    for (int i = n-1; i >= 0; --i) {
        curr[a[i]] = (curr[a[i]] + 1) % 26 + 'a';
        strs.emplace_back(curr);
    }

    for (int i = n; i >= 0; --i) {
        cout << strs[i] << "\n";
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int an;
        cin >> an;
        vector<int> a(an, 0);
        int max_a = 0;
        for (int j = 0; j < an; ++j) {
            cin >> a[j];
            max_a = max(max_a, a[j]);
        }

        solve(a, max_a);
    }

    return 0;
}