#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int mp_[33554450];
int n,m,ans,bcnt;
int b[25],output[25],vis[25],a[25],cnt[25];
int aainput[25];
int mp(const int *pa,int cnt)
{
	int now = 1;
	for(int i = 1;i <= cnt; ++i)
	{
		now = (now << 1) + pa[i];
	}
	return now;
}
int check(int mask,int now)
{
	// printf("mask = %d,now = %d\n",mask,now);
	while(mask && now)
	{
		if((mask & 1) < (now & 1))
		{
			// printf("NO\n");
			return 0;
		}
		mask >>= 1,now >>= 1;
	}
	// printf("YES\n");
	return 1;
}
void dfs(int x,int cur)
{
	if(cur == m)
	{
		// for(int i = 1;i <= n; ++i)
		// {
		// 	if(vis[i])
		// 	{
		// 		printf("%d ",i);
		// 	}
		// }
		// printf("\n");
		int ret = 0;
		int mask = mp(vis,n);
		for(int i = 1;i < bcnt; ++i)
		{
			if(check(mask,b[i]))
			{
				ret -= cnt[i];
			}
		}
		// printf("aslfhaskjfgj**ret = %d\n",ret);
		for(int i = 1;i <= n; ++i)
		{
			if(vis[i])
			{
				ret += a[i];
			}
		}
		// printf("ret = %d\n",ret);
		if(ans < ret)
		{
			ans = ret;
			for(int i = 1;i <= n; ++i)
			{
				output[i] = vis[i];
			}
		}
	}
	int mask = mp(vis,n);
	if(mp_[mask])
	{
		return;
	}
	mp_[mask] = 1;
	for(int i = x + 1;i <= n; ++i)
	{
		vis[i] = 1;
		dfs(i,cur + 1);
		vis[i] = 0;
	}
	dfs(x + 1,cur);
}
int main(int argc, char const *argv[])
{
	freopen("test.in","r",stdin);
	int kase = 0;
	// for(int i = 0;i < 100; ++i)
	// {
	// 	printf("\n");
	// }
	while(cin>>n>>m && (n + m))
	{
		bcnt = 1;
		if(kase)
		{
			printf("\n");
		}
		memset(a,0x00,sizeof(a));
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		int ca;
		cin>>ca;
		while(ca--)
		{
			int p,k;
			cin>>p;
			for(int i = 1;i <= p; ++i)
			{
				scanf("%d",&aainput[i]);
			}
			cin>>k;
			for(int i = 1;i <= p; ++i)
			{
				for(int j = i + 1;j <= p; ++j)
				{
					vis[aainput[i]] = vis[aainput[j]] = 1;
					int now = mp(vis,n);
					cnt[bcnt] = k;
					b[bcnt++] = now;
					vis[aainput[i]] = vis[aainput[j]] = 0;
				}
			}
		}
		ans = 0;
		memset(mp_,0x00,sizeof(mp_));
		dfs(0,0);
		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:",++kase,ans);
		for(int i = 1;i <= n; ++i)
		{
			if(output[i])
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}