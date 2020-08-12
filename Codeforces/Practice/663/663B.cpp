#include <bits/stdc++.h>
#include <unordered_set>

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

using namespace std;

int n,m;
 
void solve(){
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char o;cin >> o;
			if(o == 'C')continue;
			if(i == n and o == 'D')ans++;
			if(j == m and o == 'R')ans++;
		}
	}
	cout << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
    cin >> t;
	while(t--){
		solve();
	}
	return 0;
}