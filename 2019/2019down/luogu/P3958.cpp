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
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1005;
ll x[maxn],y[maxn],z[maxn],vis[maxn],can[maxn];
vector<ll> G[maxn];
vector<ll> ans;
bool dfs(ll u)
{
	vis[u] = 1;
	if(can[u])
	{
		return 1;
	}
	for(int i = 0;i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(!vis[v] && dfs(v))
		{
			return 1;
		}
	}
}
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,h,r;
		scanf("%lld%lld%lld",&n,&h,&r);
		for(int i = 1;i <= n; ++i)
		{
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		}
		memset(vis,0x00,sizeof(vis));
		memset(can,0x00,sizeof(can));
		ll dispre = 4ll * r * r;
		ans.clear();
		for(int i = 1;i <= n; ++i)
		{
			G[i].clear();
			for(int j = 1;j <= n; ++j)
			{
				if(i != j)
				{
					ll disnow = (x[i] - x[j]) * (x[i] - x[j])
								+ (y[i] - y[j]) * (y[i] - y[j])
								+ (z[i] - z[j]) * (z[i] - z[j]);
					if(disnow <= dispre)
					{
						G[i].push_back(j);
					}
				}
			}
			if(z[i] <= r)
			{
				ans.push_back(i);
			}
			if(h - z[i] <= r)
			{
				can[i] = 1;
			}
		}
		int flag = 0;
		for(int i = 0;i < ans.size(); ++i)
		{
			int nowpos = ans[i];
			if(!vis[nowpos])
			{
				if(dfs(nowpos))
				{
					flag = 1;
					printf("Yes\n");
					break;
				}
			}
		}
		if(flag == 0)
		{
			printf("No\n");
		}
	}
	return 0;
}