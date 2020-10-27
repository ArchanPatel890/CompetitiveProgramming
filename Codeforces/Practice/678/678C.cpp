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

using mint = modint<MOD>;


const int MAXN = 2000;
void solve(int n, int x, int pos) {
	vector<mint> f(MAXN+1);
	f[0] = 1;
	for (int i = 1; i <= MAXN; ++i) {
		f[i] = f[i-1] * i;
	}

	int high = 0;
	int low = 0;
	int l = 0, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (m <= pos) {
			l = m + 1;
			low++;
		}
		else if (m > pos) {
			r = m;
			high++;
		}
	}
	low--;

	int ph = n - x;
	int pl = x - 1;
	int rem = n - high - low - 1;
	if (ph < high || pl < low) {
		cout << 0 << endl;
		return;
	}

	mint ans = (f[ph] / (f[high] * f[ph - high])) * f[high];
	ans *= (f[pl] / (f[low] * f[pl - low])) * f[low];
	ans *= f[rem];
	cout << ans.value << endl;
}

/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int n, x, pos;
	cin >> n >> x >> pos;
	solve(n, x, pos);
	return 0;
}
/********  Main() Ends Here *************/