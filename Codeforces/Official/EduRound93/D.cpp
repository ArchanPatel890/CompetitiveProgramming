#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

typedef pair<int, vector<int>&> pv; 

void solve(vector<int> r, vector<int> g, vector<int> b) {
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    priority_queue<pv, vector<pv>> pq;
    pq.push(make_pair(r.size(), r));
    pq.push(make_pair())

    cout << ans << endl;
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> red(r), green(g), blue(b);
    int i;
    REP (i, r) {
        cin >> red[i];
    }
    REP (i, g) {
        cin >> green[i];
    }
    REP (i, b) {
        cin >> blue[i];
    }
    solve(red, green, blue);
    return 0;
}