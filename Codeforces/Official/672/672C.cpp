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
void solve(vector<int64> &a, vector<int64> &l, vector<int64> &r, int64 n, int64 q) {
	if (n <= 1) {
		cout << a[0] << endl;;
		return;
	}
	vector<int64> even(n, 0);
	even[0] = INT64_MIN;
	even[1] = a[0] - a[1];
	vector<int64> odd(n, 0);
	odd[0] = a[0];
	odd[1] = max(a[0], a[1]);
	int64 opt_even = even[1];
	int64 opt_odd  = odd[1];
	for (int i = 2; i < n; ++i) {
		even[i] = opt_odd - a[i];
		odd[i] = max(0ll, opt_even) + a[i];
		opt_even = max(opt_even, even[i]);
		opt_odd = max(opt_odd, odd[i]);
	}
	
	cout << opt_odd << endl;

	for (int i = 0; i < q; ++i) {
		int mn = min(l[i], r[i])-1;
		int mx = max(l[i], r[i])-1;
		
		if (mn > 2) {
			even[mn] = even[mn-2] + a[mn-1] + a[mn] - a[mx];
		}
		else if (mn == 2) {
		}
	
	}
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
		int n, q;
		cin >> n >> q;
		vector<int64> a(n);
		int i;
		REP(i, n) {
			cin >> a[i];
		}
		vector<int64> l(n);
		vector<int64> r(n);
		REP(i, q) {
			cin >> l[i] >> r[i];
		}
		solve(a, l, r, n, q);
	}
	return 0;
}
/********  Main() Ends Here *************/