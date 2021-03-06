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
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(v) int(v.size())
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const int MOD = 1000000007;
const double pi=acos(-1.0);
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

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
ll cut(ll a, ll d) {
	ll rem = a % d;
	ll cut = a / d;
	ll curr = rem * (cut+1) * (cut+1);
	curr += (d-rem) * cut * cut;
	return curr;
}

ll time(vll &a, vll &div) {
	int n = a.size();
	ll t = 0;
	for (int i = 0; i < n; ++i) {
		ll d = div[i];
		ll ai = a[i];
		t += cut(ai, d);
	}

	return t;
}

ll reduction(ll a, ll d) {
	return cut(a, d) - cut(a, d+1);
}

void solve(ll n, ll k, vll &a) {
	sort(all(a), greater<ll>());
	vll div(n, 1);
	auto cmp = [&](pll a, pll b) {
		return reduction(a.first, div[a.second]) > reduction(b.first, div[b.second]);
	};
	multiset<pll, decltype(cmp)> s(cmp);
	ll extra = k - n;
	if (extra == 0) {
		ll ans = time(a, div);
		cout << ans << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		s.insert({a[i], i});
	}

	ll large = a[0];
	int curr = 0;
	while (extra) {
		int curr = (*s.begin()).second;
		div[curr]++;
		s.erase(s.begin());
		s.insert({a[curr], curr});
		extra--;
	}

	/*
	for(int i : div) {
		cout << i << " ";
	}
	cout << endl;
	*/
	

	ll t = time(a, div);
	cout << t << endl;
}

/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	ll n, k;
	cin >> n >> k;
	vll a(n);
	for (auto &i: a) {
		cin >> i;
	}
	solve(n, k, a);
	return 0;
}
/********  Main() Ends Here *************/