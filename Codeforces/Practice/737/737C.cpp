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
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int,int> mapii;
typedef map<ll,ll> mapll;
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

template <int mod>
struct modint {
    int value;

    modint(long long x = 0) { value = normalize(x); }

    int normalize(long long x) {
        if (x < -mod || x >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
        return static_cast<int>(x);
    }

    explicit operator int() const { return value; }

    modint operator-() const { return modint(-value); }

    modint &operator+=(modint rhs) {
        if ((value += rhs.value) >= mod)
            value -= mod;
        return *this;
    }

    modint &operator-=(modint rhs) {
        if ((value -= rhs.value) < 0)
            value += mod;
        return *this;
    }

    modint &operator*=(modint rhs) {
        value = normalize(static_cast<long long>(value) * rhs.value);
        return *this;
    }

    modint &operator/=(modint rhs) { return *this *= modint(inverse(rhs.value, mod)); }

    int inverse(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    bool operator==(modint rhs) const { return value == rhs.value; }

    bool operator!=(modint rhs) const { return !(*this == rhs); }

    friend modint operator+(modint lhs, modint rhs) { return lhs += rhs; }

    friend modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }

    friend modint operator*(modint lhs, modint rhs) { return lhs *= rhs; }

    friend modint operator/(modint lhs, modint rhs) { return lhs /= rhs; }
};

constexpr int mod = (int)1e9 + 7;
using mint = modint<mod>;


template <class T>
T factorial(long long n) {
    if (n == 0)
        return 1;
    T res = 1;
	for (ll i = 2; i <= n; ++i) {
		res *= i;
	}

    return res;
}

template <class T>
T binomial(int n, int m) {
    return factorial<T>(n) / factorial<T>(m) / factorial<T>(n - m);
}

/******** User-defined Function *******/
void solve(int n, int k) {
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
	mint with_zero = 0;
    vector<mint> factorial(n+1, 0);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = factorial[i-1] * i;
    }
	for (int i = n-1, j = 0; i >= 0; i-=2, j += 2) {
		with_zero += factorial[n] / factorial[j] / factorial[n-j];
	}
    vector<mint> pow(k+1, 0);
    pow[0] = 1;
    mint pow2n = 1;
    REP(i, n) {
        pow2n *= 2;
    }
    REP(i, k) {
        pow[i+1] = pow[i] * pow2n;
    }

    vector<vector<mint>> dp(k, vector<mint>(2, 0));
    dp[0][0] = with_zero;
    dp[0][1] = 1;
    for (int i = 1; i < k; ++i) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][0]) * with_zero;
        dp[i][1] = n & 1 ? dp[i-1][0] + dp[i-1][1] : pow[i];
    }

    mint ans = dp[k-1][0] + dp[k-1][1];
	cout << (int)ans << endl;
}

/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	file_input;
	file_output;
	#endif

	int tc;
	tc = read(int);

	while (tc--) {
		int n, k;
		cin >> n >> k;
		solve(n, k);
	}
	return 0;
}
/********  Main() Ends Here *************/