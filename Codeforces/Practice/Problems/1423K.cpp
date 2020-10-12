#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int tot=0,ans[maxn],prime[maxn];
bool vis[maxn];
void Euler()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			if(1LL*i*i<maxn) prime[i*i]--;
			for(int j=i;j<maxn;j+=i) vis[j]=1;
		}
		else
		{
			prime[i]--;
		}
		++tot;
		tot+=prime[i];
		ans[i]=tot;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	Euler();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]+1);
	}
}