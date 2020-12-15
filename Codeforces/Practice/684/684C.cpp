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
void fix_square(int r, int c, vvi &g, vvi &moves) {
	int n = g.size();
	int m = g[0].size();

	vpii zeros, ones;
	if (g[r][c] == 0) zeros.push_back({r, c});
	else ones.push_back({r, c});
	if (g[r][c+1] == 0) zeros.push_back({r, c+1});
	else ones.push_back({r, c+1});
	if (g[r+1][c] == 0) zeros.push_back({r+1, c});
	else ones.push_back({r+1, c});
	if (g[r+1][c+1] == 0) zeros.push_back({r+1, c+1});
	else ones.push_back({r+1, c+1});

	if (ones.size() == 0) return;
	// Delay fixing the entire square
	if (ones.size() == 4 && (r < n-2 || c < m-2)) {
		int ex = -1;
		if (r < n-2) {
			if (g[r+2][c] == 1) {
				ex = 2;
			}
			else if (g[r+2][c+1] == 1) {
				ex = 3;
			}
		}
		if (ex < 0 && c < m-2) {
			if (g[r][c+2] == 1) {
				ex = 1;
			}
			else if (g[r+1][c+2] == 1) {
				ex = 3;
			}
		}
		if (ex > 0) {
			vi move;
			for (int i = 0; i < ones.size(); ++i) {
				if (i != ex) {
					move.push_back(ones[i].first);
					move.push_back(ones[i].second);
					g[ones[i].ft][ones[i].sc] = 0;
				}
			}
			moves.push_back(move);
			return;
		}
	}

	if (ones.size() == 4) {
		moves.push_back({ones[1].ft, ones[1].sc, ones[2].ft, ones[2].sc, ones[3].ft, ones[3].sc});
		g[r][c+1] = 0;
		g[r+1][c] = 0;
		g[r+1][c+1] = 0;
		zeros.push_back(ones[1]);
		zeros.push_back(ones[2]);
		zeros.push_back(ones[3]);
		ones.pop_back();
		ones.pop_back();
		ones.pop_back();
	}

	while (ones.size() < 3) {
		auto n = zeros.size();
		moves.push_back({ones.back().ft, ones.back().sc, zeros[n-1].ft, zeros[n-1].sc, zeros[n-2].ft, zeros[n-2].sc});
		auto temp = ones.back();
		ones.pop_back();
		ones.push_back(zeros[n-1]);
		ones.push_back(zeros[n-2]);
		zeros.pop_back();
		zeros.pop_back();
		zeros.push_back(temp);
	}

	moves.push_back({ones[0].ft, ones[0].sc, ones[1].ft, ones[1].sc, ones[2].ft, ones[2].sc});
	g[r][c] = 0;
	g[r+1][c] = 0;
	g[r][c+1] = 0;
	g[r+1][c+1] = 0;
}

/******** User-defined Function *******/
void solve(vvi &g, int n, int m) {
	vvi moves;
	REP(i, n-1) {
		REP(j, m-1) {
			if (g[i][j] == 1) fix_square(i, j, g, moves);
		}
	}
	REP(j, m-1) {
		fix_square(n-2, j, g, moves);
	}
	REP(i, n-1) {
		fix_square(i, m-2, g, moves);
	}
	cout << moves.size() << endl;
	for (auto move : moves) {
		for (auto c : move) {
			cout << (c+1) << " ";
		}
		cout << endl;
	}

	/*
	for (auto r : g) {
		for (auto rc : r) {
			cout << rc << " ";
		}
		cout << endl;
	}
	*/
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
		int n, m;
		cin >> n >> m;
		vvi g(n, vi(m));
		for (auto &r : g) {
			for (auto &rc: r) {
				char c;
				cin >> c;
				if (c == '1') rc = 1;
				else rc = 0;
			}
		}
		solve(g, n, m);
	}
	return 0;
}
/********  Main() Ends Here *************/