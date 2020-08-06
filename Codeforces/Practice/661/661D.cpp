#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(string s, int n) {
    queue<int> zeroes, ones;
    int count = 0;
    vector<int> ans;
    for (char c : s) {
        if (c == '0') {
            if (ones.empty()) {
                ++count;
                zeroes.push(count);
                ans.push_back(count);
            }
            else {
                int idx = ones.front();
                ans.push_back(idx);
                ones.pop();
                zeroes.push(idx);
            }
        }
        else if (c == '1') {
            if (zeroes.empty()) {
                ++count;
                ones.push(count);
                ans.push_back(count);
            }
            else {
                int idx = zeroes.front();
                ans.push_back(idx);
                zeroes.pop();
                ones.push(idx);
            }
        }
    }

    cout << (ones.size() + zeroes.size()) << endl;
    for (int a : ans) {
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
    
    return 0;
}