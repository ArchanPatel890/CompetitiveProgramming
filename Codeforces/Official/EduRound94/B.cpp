#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void solve(int p, int f, int cs, int cw, int s, int w) {
    if (S > W)
        return can_take(W, S, CW, CS, P);
 
    if (S * CS >= P)
        return P / S;
 
    return CS + min((P - S * CS) / W, CW);
    

}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int p, f;
        cin >> p >> f;
        int cs, cw;
        cin >> cs >> cw;
        int s, w;
        cin >> s >> w;

    }
    
    return 0;
}