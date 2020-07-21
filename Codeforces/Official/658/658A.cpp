#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int m, n;
        cin >> m >> n;
        unordered_set<int> a;
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            a.insert(num);
        }

        int k = -1;
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (a.count(num) && k == -1) {
                k = num;
            }
        }
        if (k > 0) {
            cout << "YES\n";
            cout << "1 " << k << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
