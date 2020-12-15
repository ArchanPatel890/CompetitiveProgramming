/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*/
 
/********   All Required Header Files ********/
#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
// IO
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define read(type) readInt<type>()
// Array / Iteration
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
// Function Aliases
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(v) int(v.size())
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
// Constants
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const int MOD = 1000000007;
const double pi=acos(-1.0);
// typedefs aliases for common types
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
typedef map<ll,ll> mpll;
typedef set<int> seti;
typedef set<ll> setll;
typedef multiset<int> mseti;
typedef multiset<ll> msetll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
// Timing
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

/****** Input / Output Redirection to Files ******/
#define file_input freopen("input.txt","r",stdin)
#define file_output freopen("output.txt","w",stdout)
#define file_io file_input; file_output
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

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
#ifdef _MSC_VER
int __builtin_clz(unsigned x) {
    int bit = 31;
    while (bit >= 0 && (x & (1 << bit)) == 0)
        --bit;
    return 31 - bit;
}
#endif

template <class T, class F = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> t;
    F func;

    SparseTable(const vector<T> &a, F f) : t(32 - __builtin_clz(a.size())), func(std::move(f)) {
        t[0] = a;
        for (size_t i = 1; i < t.size(); i++) {
            t[i].resize(a.size() - (1 << i) + 1);
            for (size_t j = 0; j < t[i].size(); j++)
                t[i][j] = func(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= (int)t[0].size() - 1);
        int k = 31 - __builtin_clz(to - from + 1);
        return func(t[k][from], t[k][to - (1 << k) + 1]);
    }
};

void solve(vi &a, int n) {
	SparseTable<int> st(a, [](int i, int j) { return min(i, j); });
	vector<int> cnt(n+1, 0);
	string s(n, '0');
	for (int i : a) {
		if (i > 0  && i <= n) cnt[i]++;
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] != 1) {
			ok = false;
			break;
		}
	}
	if (ok) s[0] = '1';

	int l = 0;
	int r = n-1;
	int curr = 1;
	while (l <= r) {
		if (st.get(l, r) == curr) {
			s[r-l] = '1';
		}
		else {
			break;
		}
		if (l < r && st.get(l, r-1) == curr+1) {
			--r;
		}
		else if (l < r && st.get(l+1, r) == curr+1) {
			++l;
		}
		else {
			break;
		}
		++curr;
	}

	cout << s << endl;
}

/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	file_input;
	//file_output;
	#endif

	int tc;
	tc = read(int);

	while (tc--) {
		int n = read(int);
		vi a(n);
		for (auto &i : a) {
			i = read(int);
		}
		solve(a, n);
	}
	return 0;
}
/********  Main() Ends Here *************/