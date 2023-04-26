/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 */

/********   All Required Header Files ********/
#include <bits/stdc++.h>

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
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
typedef set<int> seti;
typedef set<ll> setll;
typedef multiset<int> mseti;
typedef multiset<ll> msetll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
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
#define debug(x) cerr << #x << "=" << (x) << '\n'
/**********************************************/

/******** User-defined Function *******/
auto cmph = [](pii a, pii b)
{
  return a.first > b.first;
};
auto cmpw = [](pii a, pii b)
{
  return a.second > b.second;
};

typedef multiset<pii, decltype(cmph)> set_h;
typedef multiset<pii, decltype(cmpw)> set_w;

ll HCut(set_h &h, set_w &w, ll &ht, ll &wt)
{
  if (w.empty())
  {
    if (ht && wt)
      return -1;
    return 0;
  }
  if (w.begin()->second != wt)
    return -1;

  ll height = 0;
  while (!w.empty() && w.begin()->second == wt)
  {
    if (w.begin()->first > ht)
      return -1;

    height += w.begin()->first;
    auto cp = *w.begin();
    w.erase(w.find(cp));
    h.erase(h.find(cp));
  }
  if (height > ht)
    return -1;
  ht -= height;
  return height;
};

ll VCut(set_h &h, set_w &w, ll &ht, ll &wt)
{
  if (h.empty())
  {
    if (ht && wt)
      return -1;
    return 0;
  }
  if (h.begin()->first != ht)
    return -1;

  ll width = 0;
  while (!h.empty() && h.begin()->first == ht)
  {
    if (h.begin()->second > wt)
      return -1;

    width += h.begin()->second;
    auto cp = *h.begin();
    h.erase(h.find(cp));
    w.erase(w.find(cp));
  }
  if (width > wt)
    return -1;
  wt -= width;
  return width;
}

void hv(set_h& h, set_w& w, set<pll> &out)
{
  // Assume first cut is horizontal.
  ll width = w.begin()->second;
  ll height = INT64_MAX;
  ll wt = w.begin()->second;
  ll ht = INT64_MAX;
  bool ok = true;

  ll d_h = HCut(h, w, ht, wt);
  if (d_h < 0)
  {
    ok = false;
  }

  height = d_h + (h.empty() ? 0 : h.begin()->first);
  ht = (h.empty() ? 0 : h.begin()->first);

  while (!h.empty())
  {
    if (VCut(h, w, ht, wt) < 0)
    {
      ok = false;
      break;
    }
    if (HCut(h, w, ht, wt) < 0)
    {
      ok = false;
      break;
    }
  }

  if (ok && (!ht || !wt))
  {
    out.insert({height, width});
  }
}

void vh(set_h& h, set_w& w, set<pll> &out)
{
  // Assume first cut is vertical.
  ll height = h.begin()->first;
  ll width = INT64_MAX;
  ll ht = h.begin()->first;
  ll wt = INT64_MAX;
  bool ok = true;

  ll d_w = VCut(h, w, ht, wt);
  if (d_w < 0)
  {
    ok = false;
  }

  width = d_w + (w.empty() ? 0 : w.begin()->second);
  wt = (w.empty() ? 0 : w.begin()->second);

  while (!w.empty())
  {
    if (HCut(h, w, ht, wt) < 0)
    {
      ok = false;
      break;
    }
    if (VCut(h, w, ht, wt) < 0)
    {
      ok = false;
      break;
    }
  }

  if (ok && (!ht || !wt))
  {
    out.insert({height, width});
  }
}

void solve(vpii &rect, int n)
{
  set_w w(all(rect), cmpw);
  set_h h(all(rect), cmph);

  set<pll> ans;

  hv(h, w, ans);

  w.insert(all(rect));
  h.insert(all(rect));
  vh(h, w, ans);

  cout << ans.size() << endl;
  for (auto [height, width] : ans)
  {
    cout << height << " " << width << endl;
  }
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
    int n;
    cin >> n;
    vpii rect(n);
    for (auto &[h, w] : rect)
    {
      cin >> h >> w;
    }
    solve(rect, n);
  }
  return 0;
}
/********  Main() Ends Here *************/