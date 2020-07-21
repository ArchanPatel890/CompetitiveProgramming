#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void flipStr(string& a, int i) {
    string b = a.substr(0, i);
    reverse(b.begin(), b.end());
    for (int j = 0; j < i; ++j) {
        if (b[j] == '0') {
            a[j] = '1';
        }
        else {
            a[j] = '0';
        }
    }
}

void solve(string a, string& b) {
    int flip = 0;
    int n = a.size();
    vector<int> ans;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == b[i]) {
            continue;
        }
        if (a[i] != b[i]) {
            if (a[0] != b[i]) {
                flipStr(a, i+1);
                ans.push_back(i+1);
            }
            else {
                
                flipStr(a, 1);
                ans.push_back(1);
                flipStr(a, i+1);
                ans.push_back(i+1);
            }
        }
    }

    cout << ans.size();
    for (auto i : ans) {
        cout << " " << i;
    }
    cout << "\n";
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}