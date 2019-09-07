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
const ll maxn = 10005;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
ll dis[maxn],vis[maxn];
struct node{
	ll ind;
	ll dist;
	node(){};
	node(ll a,ll b):ind(a),dist(b){};
	bool operator <(const node &b)const
	{
		return dist > b.dist;
	}
};
ll n,m,q;
vector<node> v[maxn];
void dijkstra_fast()
{
	priority_queue<node> q;
	while(!q.empty())
	{
		q.pop();
	}
	for(int i = 2;i <= n; ++i)
	{
		dis[i] = inf;
	}
	dis[1] = 0;
	vis[1] = 1;
	int siz = (int)v[1].size();
	for(int i = 0;i < siz; ++i)
	{
		q.push(node(v[1][i].ind,v[1][i].dist));
		if(v[1][i].ind != 1 && v[1][i].dist < dis[v[1][i].ind])
		{
			dis[v[1][i].ind] = v[1][i].dist;
		}
	}
	while(!q.empty())
	{
		node u = q.top();
		q.pop();

		ll min_index = u.ind;
		if(vis[min_index])
		{
			continue;
		}
		vis[min_index] = 1;
		int siz = (int)v[min_index].size();
		for(int i = 0;i < siz; ++i)
		{
			ll u = v[min_index][i].ind;
			ll value = v[min_index][i].dist;
			if(!vis[u] && dis[u] > dis[min_index] + value)
			{
				dis[u] = dis[min_index] + value;
				q.push(node(u,dis[u]));
			}
		}
	}
	// for(ll i = 1;i <= n; ++i)
	// {
	// 	printf("dis[%lld] = %lld\n",i,dis[i]);
	// }
}
vector<node> G[2][maxn];
ll dp1[maxn],dp2[maxn];
void getG()
{
	for(ll u = 1;u <= n; ++u)
	{
		ll siz = (int)v[u].size();
		for(int i = 0;i < siz; ++i)
		{
			ll index = v[u][i].ind;
			ll value = v[u][i].dist;
			if(dis[u] + value == dis[index])
			{
				G[0][u].push_back(node(index,value));
				G[1][index].push_back(node(u,value));
			}
		}
	}
	for(ll i = 1;i <= n; ++i)
	{
		G[1][n + 1].push_back(node(i,0));
		G[0][i].push_back(node(n + 1,0));
	}
}
const ll mod = 10000000000ll;
ll mul(ll a,ll b)
{
	ll a2 = a % 100000ll;
	ll b2 = b % 100000ll;
	return (((a / 100000ll) * b2 + (b / 100000ll) * a2) * 100000ll + a2 * b2) % mod;
}
ll dfs(ll u,ll *dp,ll pos)
{
	if(vis[u])
	{
		return dp[u];
	}
	ll siz = (int)G[pos][u].size();
	if(siz == 0)
	{
		dp[u] = 1ll;
		vis[u] = 1ll;
		return 1ll;
	}
	for(int i = 0;i < siz; ++i)
	{
		ll to = G[pos][u][i].ind;
		ll temp = dfs(to,dp,pos);
		dp[u] = (dp[u] + temp) % mod;
	}
	vis[u] = 1;
	return dp[u];
}
int main(int argc, char const *argv[])
{
	while(scanf("%lld%lld%lld",&n,&m,&q) != EOF)
	{
		for(int i = 0;i <= n + 1; ++i)
		{
			G[0][i].clear();
			v[i].clear();
			G[1][i].clear();
			dp1[i] = dp2[i] = vis[i] = 0;
		}
		for(ll i = 1;i <= m; ++i)
		{
			ll from,to,w;
			scanf("%lld%lld%lld",&from,&to,&w);
			++from,++to;
			v[from].push_back(node(to,w));
		}
		memset(vis,0x00,sizeof(vis));
		dijkstra_fast();
		getG();
		memset(vis,0x00,sizeof(vis));
		dfs(1,dp1,0);
		memset(vis,0x00,sizeof(vis));
		dfs(n + 1,dp2,1);
		while(q--)
		{
			ll u;
			scanf("%lld",&u);
			++u;
			if(u > n)
			{
				printf("%010lld\n",0);
				continue;
			}
			ll ans = mul(dp1[u],dp2[u]);
			printf("%010lld\n",ans);
		}
	}
	return 0;
}