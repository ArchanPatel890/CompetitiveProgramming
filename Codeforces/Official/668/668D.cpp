/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*/
 
/********   All Required Header Files ********/
#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
	} while(x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n = 0, s = 1;
	char p = getchar();
	if (p == '-')
		s = -1;
	while ((p < '0' || p > '9') && p !=EOF && p != '-')
		p = getchar();
	if (p == '-')
		s = -1 , p = getchar();
	while (p >= '0' && p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}

	return n*s;
}
/************************************/


/***************** Debugging ******************/
#define debug(x) cerr << #x << "=" << (x) <<'\n'
/**********************************************/


/******** User-defined Function *******/

void dfs(int s, vector<vector<int>> &g, vector<bool>& seen, int cnt, int& maxcnt, int& far) {
	if (cnt > maxcnt) {
		maxcnt = cnt;
		far = s;
	}
	seen[s] = true;
	for (int v : g[s]) {
		if (!seen[v]) {
			dfs(v, g, seen, cnt + 1, maxcnt, far);
		}
	}
}

void dfsFind(int s, int t, vector<vector<int>> &g, vector<bool>& seen, int cnt, int& find) {
	if (s == t) {
		find = cnt;
	}
	seen[s] = true;
	for (int v : g[s]) {
		if (!seen[v]) {
			dfsFind(v, t, g, seen, cnt + 1, find);
		}
	}
}

void solve(vector<vector<int>> g, int n, int a, int b, int da, int db) {
	if (2*da >= db || a == b) {
		cout << "Alice" << endl;
		return;
	}
	int find = 0;
	vector<bool> seen(n+1, false);
	dfsFind(a, b, g, seen, 0, find);
	if (find && find <= da) {
		cout << "Alice" << endl;
		return;
	}
	
	for (int i = 0; i < n+1; ++i) seen[i] = false;
	int far = 0, maxd = 0;
	dfs(a, g, seen, 0, maxd, far);

	maxd = 0;
	for (int i = 0; i < n+1; ++i) seen[i] = false;
	dfs(far, g, seen, 0, maxd, far);

	if ((maxd+1) / 2 <= da) {
		cout << "Alice" << endl;
		return;
	}
	cout << "Bob" << endl;
}

/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int tc;
	tc = read(int);

	while (tc--) {
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		vector<vector<int>> g(n+1);
		int i;
		REP(i, n-1) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		solve(g, n, a, b, da, db);
	}
	return 0;
}
/********  Main() Ends Here *************/