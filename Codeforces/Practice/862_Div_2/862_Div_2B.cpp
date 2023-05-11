/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 */

/********   All Required Header Files ********/

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
// IO
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define read(type) readInt<type>()
// Array / Iteration
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
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
const double pi = acos(-1.0);
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
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
typedef map<string, string> mapss;
typedef set<int> seti;
typedef set<ll> setll;
typedef set<string> sets;
typedef multiset<int> mseti;
typedef multiset<ll> msetll;
typedef multiset<string> msets;
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
typedef unordered_map<string, string> umapss;
// Timing
clock_t start_time = clock();
#define current_time fixed << setprecision(6) << (ld)(clock() - start_time) / CLOCKS_PER_SEC

/****** Input / Output Redirection to Files ******/
#define file_input freopen("input.txt", "r", stdin)
#define file_output freopen("output.txt", "w", stdout)
#define file_io \
  file_input;   \
  file_output
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0)
/*************************************************/

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
  if (y < x)
    x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
  if (x < y)
    x = y;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool prime(ll a)
{
  if (a == 1)
    return 0;
  if (a == 2)
    return 1;
  if (a % 2 == 0)
    return 0;
  for (int i = 3; i <= round(sqrt(a)); i += 2)
    if (a % i == 0)
      return 0;
  return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
  int i = 20;
  char buf[21];
  // buf[10] = 0;
  buf[20] = '\n';

  do
  {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do
  {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-')
    s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-')
    p = getchar();
  if (p == '-')
    s = -1, p = getchar();
  while (p >= '0' && p <= '9')
  {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }

  return n * s;
}
/************************************/

/***************** Debugging ******************/
#ifndef ONLINE_JUDGE
#define dbg(v)                                                                 \
  cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#else
#define dbg(v)
#endif
/**********************************************/

/******** User-defined Function *******/
void solve(string s, ll n)
{
  char mn = s[0];
  ll pos = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] <= mn) {
      pos = i;
      mn =  s[i];
    }
  }

  string t = s;
  t[0] = s[pos];
  for (int i = 0, j = 1; i < n; ++i) {
    if (i != pos)  {
      t[j] = s[i];
      ++j;
    }
  }

  cout << t << endl;
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

  while (tc--)
  {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    solve(s, n);
  }
  return 0;
}
/********  Main() Ends Here *************/