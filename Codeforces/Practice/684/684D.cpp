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
class sstack {
	struct Node {
		Node* prev;
		Node* next;
		int* arr;
		int idx;
	};

private:
	size_t chunk_size;
	Node* top = nullptr;

	Node* createNode() {
		Node* node = new Node();
		node->arr = new int[chunk_size];
		node->idx = 0;
		node->prev = top;
		node->next = nullptr;
		return node;
	}

public:
	sstack(size_t chunk_size) : chunk_size(chunk_size){}
	void push(int n) {
		if (!top) {
			top = createNode();
		}
		if (top->idx == chunk_size) {
			Node* node = createNode();
			top->next = node;
			top = node;
		}
		top->arr[top->idx] = n;
		top->idx++;
	}

	int pop() {
		if (!top || (top->idx == 0 && !top->prev)) return -100;

		if (top->idx == 0) {
			top = top->prev;
			delete top->next;
		}
		int ans = top->arr[top->idx-1];
		top->idx--;
		return ans;
	}
};
/**************************************/


/********** Main()  function **********/
int main()
{
	#ifndef ONLINE_JUDGE
	file_input;
	//file_output;
	#endif

	sstack s(2);
	for (int i = 0; i < 10; ++i) {
		s.push(i);
	}
	for (int i = 0; i < 10; ++i) {
		cout << s.pop() << endl;
	}
	cout << s.pop() << endl;
	return 0;
}
/********  Main() Ends Here *************/