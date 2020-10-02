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
int dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int dist_h(pii a, pii b) {
    return min(abs(a.first - b.first), abs(a.second - b.second));
}

void solve(vii rob, vii s, int n, int m) {
    vii hull;
    for (int i = 0; i < m; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (j == i) continue;
            if (s[i].ft < s[j].ft && s[i].sc <= s[j].sc) {
                ok = false;
                break;
            }
        }
        if (ok) {
            hull.pb(s[i]);
        }
    }
    sort(hull.begin(), hull.end());
    vii corners;
    for (int i = 0; i < hull.size()-1; ++i) {
        corners.pb({hull[i].first, hull[i+1].second});
    }
    int mx_x = 0;
    int mx_y = 0;
    int mx = 0;
    for (auto r : rob) {
        pii mn_c;
        int min_c = INT_MAX;
        for (auto c : corners) {
            if (r.first <= c.first && r.second <= c.second) {
                if (dist(c, r) < min_c) {
                    mn_c = c;
                    min_c = dist(r, c);
                }
            }
        }

        pii mn_h;
        int min_h = INT_MAX;
        for (auto h : hull) {
            if (r.first <= h.first && r.second <= h.second) {
                if (dist(h, r) < min_h) {
                    mn_h = h;
                    min_h = dist_h(h, r);
                }
            }
        }
        mx = max(mx, dist(mn_h, r) + 1);
        mx_x = max(mx_x, mn_c.first - r.first + 1);
        mx_y = max(mx_y, mn_c.second - r.second + 1);
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

	int n, m;
    cin >> n >> m;
    vii r(n), s(m);
    for (auto &i : r) {
        cin >> i.first >> i.second;
    }
    for (auto &i : s) {
        cin >> i.first >> i.second;
    }

    solve(r, s, n, m);
}
/********  Main() Ends Here *************/