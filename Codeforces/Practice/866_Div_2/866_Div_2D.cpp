// Problem: D. The Butcher
// Contest: Codeforces - Codeforces Round 866 (Div. 2)
// URL: https://codeforces.com/contest/1820/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
#include<iostream>
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
using namespace std;
#define fio 	   	   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int        	   long long
#define rep(karu,mera,gaon)     for(int karu=mera;karu<gaon;karu++)
#define vi 		   	   vector<int>
#define pb         	   push_back
#define mii        	   map<int,int>
#define all(x)         (x).begin(),(x).end()
#define endl           '\n' 
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pii        	   pair<int,int>
#define pno            cout<<"NO"<<endl
#define pys            cout<<"YES"<<endl
#define fi         	   first
#define se         	   second
#define mp             make_pair
#define setbits(x)     __builtin_popcountll(x)
#define ctz(x)         __builtin_ctzll(x)
#define clz(x)         __builtin_clzll(x)
#define uniq(v)        (v).erase(unique(all(v)),(v).end())
#define sz(x)          (int)((x).size())
#define inf        	   3e18//9223372036854775807//2147483647
#define ld             long double
#define ps(x,y)        fixed<<setprecision(y)<<x
                                
const int mod=1e9+7;//998244353;
const int MAX=1e6;
const long double PI=3.14159265359;
const long double eps=1e-6;                  
//-10
 
 
bool check(int h, int w, multiset<pii>&st1,multiset<pii>&st2)
{
	
	if(sz(st1)==1)
	{
		if(*st1.begin()==mp(h,w))
		return true;
		
		return false;
	}
	auto it1 = st1.lower_bound(mp(h,-1));
	
	if(it1!=st1.end() && it1->fi==h)
	{
		int wi = it1->se;
		st2.erase(st2.find(mp(it1->se,it1->fi)));
		
		st1.erase(it1);
		
		
		
		return check(h,w-wi,st1,st2);
	}
	
	auto it2 = st2.lower_bound(mp(w,-1));
	if(it2!=st2.end() && it2->fi==w)
	{
		int hi = it2->se;
		st1.erase(st1.find(mp(it2->se,it2->fi)));
		st2.erase(it2);
		
		return check(h-hi,w,st1,st2);
	}
	// if(h==4 && w==5)
	// {
		// pys;
		// //cout<<h-hi<<' '<<w<<endl;
		// //return true;
	// }
	return false;
	//return true;
}
void solve()
{
    fio;
    int n;cin>>n;
    multiset<pii>s;
    multiset<pii>ss;
    vector<pii> hw(n);
    rep(i,0,n)
    {
    	int h,w;
    	cin>>h>>w;
    	s.insert(mp(h,w));
    	ss.insert(mp(w,h));
    	hw[i].fi = h;
    	hw[i].se = w;
    }
    
    
    
    set<pii>ans;
    {
    	multiset<pii>s1 = s;
    	int h = 0;
    	for(auto p:hw)
    	h = max(h,p.fi);
    	
    	int w = 0;
    	set<pii>rem;
    	for(auto p:hw)
    	if(p.fi==h)
    	{
    		w += p.se;
    		rem.insert(p);
    	}
    	for(auto p:rem)
    	s1.erase(p);
    	
    	int wmx = 0;
    	for(auto p:s1)
    	wmx = max(wmx,p.se);
    	
    	w += wmx;
    	
    	//cout<<h<<' '<<w<<endl;
    	multiset<pii>st1 = s;
    	multiset<pii>st2 = ss;
    	if(check(h,w,st1,st2))
    	ans.insert(mp(h,w));
    }
    
    {
    	multiset<pii>s1 = s;
    	int w = 0;
    	for(auto p:hw)
    	w = max(w,p.se);
    	
    	//cout<<w<<endl;
    	int h = 0;
    	set<pii>rem;
    	for(auto p:hw)
    	if(p.se==w)
    	{
    		h += p.fi;
    		rem.insert(p);
    	}
    	for(auto p:rem)
    	s1.erase(p);
    	
    	int hmx = 0;
    	for(auto p:s1)
    	hmx = max(hmx,p.fi);
    	
    	h += hmx;
    	multiset<pii>st1 = s;
    	multiset<pii>st2 = ss;
    	// for(auto p:st2)
    	// cout<<p.fi<<' '<<p.se<<endl;
    	//cout<<h<<' '<<w<<endl;
    	if(check(h,w,st1,st2))
    	ans.insert(mp(h,w));
    }
    
    cout<<sz(ans)<<endl;
    for(auto p:ans)
    cout<<p.fi<<' '<<p.se<<endl;
    return;
}
 
 
int32_t main(){
    fio;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	solve();
    }
    return 0;
}