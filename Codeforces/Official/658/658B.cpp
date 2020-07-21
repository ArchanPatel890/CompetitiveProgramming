#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void solve(vector<int>& s) {
    int n = s.size();
    int fp_wins = 1;
    for (int i = n-2; i >= 0; --i) {
        if (s[i] == 1) {
            fp_wins = -fp_wins;
        }
        else if (fp_wins < 0) {
            fp_wins =- fp_wins;
        }
    }
    if (fp_wins < 0) {
        cout << "Second\n";
    }
    else {
        cout << "First\n";
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n; 
        vector<int> stones(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> stones[j];
        }
        solve(stones);
    }

    return 0;
}