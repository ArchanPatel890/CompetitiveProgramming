#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int x, y;
ll C[7];
 
inline ll f(int t){
	ll ret = 0;
	ret += max(0ll,  C[2]*(t + y));
	ret += max(0ll, -C[5]*(t + y));
	ret += max(0ll,  C[6]*(t + x));
	ret += max(0ll, -C[3]*(t + x));
	ret += max(0ll,  C[4]*(t + 0));
	ret += max(0ll, -C[1]*(t + 0));
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		cin >> x >> y;
		for (int i = 1; i <= 6; i++) cin >> C[i];
		cout << min(min(f(-x), f(-y)), f(0)) << '\n';
	}
}