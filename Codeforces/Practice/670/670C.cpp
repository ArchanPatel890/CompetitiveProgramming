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
int cent1 = 0;
int cent2 = 0;
void dfs(int u, int f, int n, vvi &g, vi &a, vi &s, int &mn) {
    a[u] = f;
    s[u] = 1;
    int mx = 0;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs(v, u, n, g, a, s, mn);
        s[u] += s[v];
        mx = max(mx, s[v]);
    }
    mx = max(mx, n - s[u]);
    if (mx < mn) {
        mn = mx;
        cent1 = u;
        cent2 = 0;
    }
    else if (mx ==  mn) {
        cent2 = u;
    }
}

void getLeaf(int u, int f, vvi &g, int &leaf) {
    if (g[u].size() == 1) {
        leaf = u;
        return;
    }
    for (int v : g[u]) {
        if (v == f) continue;
        getLeaf(v, u, g, leaf);
    }
}

void solve(vvi& g, int n) {
    vi a(n+1, 0);
    vi s(n+1, 0);
    int mn = INT_MAX;
    dfs(1, 0, n, g, a, s, mn);

    if (!cent2) {
        printf("1 %d\n", g[1][0]);
        printf("1 %d\n", g[1][0]);
        return;
    }
    if (a[cent1] != cent2) swap(cent1, cent2);
    int leaf;
    getLeaf(cent1, cent2, g, leaf);
    printf("%d %d\n", leaf, a[leaf]);
    printf("%d %d\n", leaf, cent2);
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
		int n;
        cin >> n;
        vvi g(n+1);
        int i;
        REP(i, n-1) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve(g, n);
	}
	return 0;
}
/********  Main() Ends Here *************/