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
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

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
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
// #include <execution>
#include <optional>
#include <string_view>
#include <variant>
#endif

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
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int,int> mapii;
typedef map<ll,ll> mapll;
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
vpll is_tail(unordered_map<ll, setll>& adj, setll seen, ll u) {
  vpll tail;
  for (ll n : adj[u]) {
    if (!seen.count(n)) tail.push_back({n, u});
  }
  return tail;
}

void AddPathTill(ll u, deque<ll>& in, deque<ll>& out) {
  for (auto it = in.rbegin(); it != in.rend(); ++it) {
    out.push_front(*it);
    if (*it == u) break;
  }
}

void solve(vpll& edges, ll n, ll m) {
  unordered_map<ll, setll> adj;
  for (auto [l,r] : edges) {
    adj[l].insert(r);
    adj[r].insert(l);
  }

  deque<ll> path, cycle;
  setll visited, seen;
  bool ok = false;
  vpll pairs;
  function<void(ll, ll)> dfs = [&](ll u, ll prev) {
    if (visited.count(u)) return;
    
    if (seen.count(u)) {
      deque<ll> tmp;
      AddPathTill(u, path, tmp);
      setll cycle_seen(tmp.begin(), tmp.end());
  
      vpll tail = is_tail(adj, cycle_seen, u);
      if (tail.size() >= 2) {
        ok = true;
        pairs = tail;
        cycle = tmp;
        return;
      }

      auto curr = path.rbegin();
      while (*curr != u) {
        vpll tmp_tail = is_tail(adj, cycle_seen, *curr);
        if (tmp_tail.size() >= 2) {
          pairs = tmp_tail;
          cycle = tmp;
          ok = true;
          return;
        }
        curr++;
      }

      return;
    }

    seen.insert(u);
    path.push_back(u);
    for (ll n : adj[u]) {
      if (n != prev && !visited.count(n)) dfs(n, u);
    }
    seen.erase(u);
    path.pop_back();

    visited.insert(u);
  };

  for (auto& [u, _] : adj) {
    if (!visited.count(u) && !ok) {
      dfs(u, -1);
    }
  }

  if (ok) {
    cout << "YES\n";
    cout << cycle.size() + 2 << endl;
    ll start = *cycle.begin();
    ll end = *cycle.rbegin();
    for (auto it = cycle.begin(); it + 1 != cycle.end(); ++it) {
      cout << *it << " " << *(it + 1) << "\n";
    }
    cout << end << " " << start << endl;
    cout << pairs[0].first << " " << pairs[0].second << endl;
    cout << pairs[1].first << " " << pairs[1].second << endl;
    return;
  }
  cout << "NO" << endl;
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
    ll n, m;
    cin >> n >> m;
    vpll edges(m);
    for (auto& [u,v] : edges) {
      cin >> u >> v;
    }
    solve(edges, n, m);
  }
  return 0;
}
/********  Main() Ends Here *************/