#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll NMAX=2e5+5,SQRMAX=635,MOD=1e9+7;


/****** Input / Output Redirection to Files ******/
#define file_input freopen("input.txt", "r", stdin)
#define file_output freopen("output.txt", "w", stdout)
#define file_io \
  file_input;   \
  file_output
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0)

int fr[SQRMAX][NMAX];
ll a[NMAX],b[NMAX];
void tc(){
    ll n,ans=0;
    cin>>n;
    ll lim=sqrt(n*2);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(a[i]<=lim)
            fr[a[i]][b[i]]++;
    }
    for(ll i=0;i<n;i++){
        if(a[i]<=lim){
            if(a[i]*a[i]-b[i]>=1 && a[i]*a[i]-b[i]<=n)
                ans+=fr[a[i]][a[i]*a[i]-b[i]];
        }
    }
    for(ll i=2;i<=lim;i+=2)
        ans-=fr[i][i*i/2];
    ans/=2;

    for(ll i=0;i<n;i++){
        for(ll j=1;j<=lim && j<a[i] && j*a[i]<=2*n;j++){
            if(j*a[i]-b[i]>=1 && j*a[i]-b[i]<=n)
                ans+=fr[j][j*a[i]-b[i]];
        }
    }
    for(ll i=0;i<n;i++){
        if(a[i]<=lim)
            fr[a[i]][b[i]]=0;
    }
    cout<<ans<<'\n';
}


int main()
{
#ifndef ONLINE_JUDGE
    file_input;
    file_output;
#else
    fast_io;
#endif
    ll t;
    cin>>t;
    while(t--)
        tc();
    return 0;
}