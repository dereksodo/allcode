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
const ll maxn = 100005;
const ll maxn2 = 18;
struct edge{
	ll to,next;
}e[maxn << 1];
ll tot,head[maxn],depth[maxn],fa[maxn][maxn2];
ll n,m;
ll c[maxn],d[maxn];
void addedge(ll x,ll y)
{
	e[++tot].to = y;
	e[tot].next = head[x];
	head[x] = tot;

	e[++tot].to = x;
	e[tot].next = head[y];
	head[y] = tot;
}

void dfs(ll u)
{
	for(ll i = head[u];i; i = e[i].next)
	{
		ll v = e[i].to;
		if(v == fa[u][0])
		{
			continue;
		}
		fa[v][0] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

void pre()
{
	for(ll j = 1;j < maxn2; ++j)
	{
		for(ll i = 1;i <= n; ++i)
		{
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

ll LCA(ll x,ll y)
{
	if(depth[x] < depth[y])
	{
		swap(x,y);
	}
	ll t = depth[x] - depth[y];
	for(ll i = 20;i >= 0; --i)
	{
		if(t & (1 << i))
		{
			x = fa[x][i];
		}
	}
	if(x == y)
	{
		return x;
	}
	// printf("x = %lld,y = %lld\n",x,y);
	for(ll i = 17;i >= 0; --i)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	if(x != y)
	{
		return fa[x][0];
	}
	return x;
}
map<ll,ll> li[maxn];
void creat(ll index,ll beg,ll end)
{
	if(depth[beg] > depth[end])
	{
		swap(beg,end);
	}
	// printf("%lld %lld,lca = %lld\n",end,beg,LCA(end,beg));
	ll ance = LCA(end,beg);
	if(ance != beg)
	{
		creat(index,end,ance);
		creat(index,ance,beg);
	}
	else
	{
		ll now = end;
		while(now != beg)
		{
			li[index][now] = 1;
			now = fa[now][0];
		}
		li[index][beg] = 1;
	}
}
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	for(ll i = 1;i < n; ++i)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		--x,--y;
		addedge(x,y);
	}
	dfs(0);
	pre();
	for(ll i = 1;i <= m; ++i)
	{
		scanf("%lld%lld",&c[i],&d[i]);
		--c[i],--d[i];
		creat(i,c[i],d[i]);
	}
	// for(ll i = 1;i <= m; ++i)
	// {
	// 	printf("%lld -> %lld\n",c[i],d[i]);
	// 	for(auto iter = li[i].begin();iter != li[i].end(); ++iter)
	// 	{
	// 		printf("%lld ",iter->first);
	// 	}
	// 	printf("\n");
	// }
	ll ans = 0;
	for(ll i = 1;i <= m; ++i)
	{
		for(ll j = i + 1;j <= m; ++j)
		{
			if((li[j][LCA(c[i],d[i])] == 1)
				|| (li[i][LCA(c[j],d[j])]) == 1)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}