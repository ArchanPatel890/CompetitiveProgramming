#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

void printRowForword(int r, int m) {
	for (int i = 1; i <= m; ++i) {
		printf("%d %d\n", r, i);
	}
}

void printRowBackward(int r, int m) {
	for (int i = m; i >= 1; --i) {
		printf("%d %d\n", r, i);
	}
}

void solve(int n, int m, int sx, int sy){
	printf("%d %d\n", sx, sy);
	if (sy != 1) {
		printf("%d %d\n", sx, 1);
	}
	for (int i = 2; i <= m; ++i) {
		if (i != sy) printf("%d %d\n", sx, i);
	}
	int forward = false;
	for (int i = sx+1; i <= n; ++i) {
		if (forward) {
			printRowForword(i, m);
		}
		else {
			printRowBackward(i, m);
		}
		forward = !forward;
	}

	for (int i = sx-1; i >= 1; --i) {
		if (forward) {
			printRowForword(i, m);
		}
		else {
			printRowBackward(i, m);
		}
		forward = !forward;
	}

}
 
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n, m;
	int sx, sy;
	cin >> n >> m >> sx >> sy;
	solve(n, m, sx, sy);

	return 0;
}