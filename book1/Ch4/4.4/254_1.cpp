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
const int maxn = 3e4 + 5;
const int maxe = 35;
int dis[maxn],dep[maxn],f[maxn][maxe],tot,n;
int head[maxn << 1],to[maxn << 1],nxt[maxn << 1],w[maxn];
void add(ll x,ll y,ll z)
{
	nxt[++tot] = head[x];
	to[tot] = y;
	w[tot] = z;
	head[x] = tot;
}
void dfs(int u,int fa)
{
	dep[u] = dep[fa] + 1;
	for(int i = 0;i < 30; ++i)
	{
		f[u][i + 1] = f[f[u][i]][i];
	}
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			f[v][0] = u;
			dis[v] = dis[u] + w[i];
			dfs(v,u);
		}
	}
}
int lca(int x,int y)
{
	if(dep[x] < dep[y])
	{
		swap(x,y);
	}
	int ans = 0;
	for(int i = 30;i >= 0; --i)
	{
		if(dep[f[x][i]] >= dep[y])
		{
			x = f[x][i];
		}
	}
	if(x == y)
	{
		return x;
	}
	for(int i = 30;i >= 0; --i)
	{
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main(int argc, char const *argv[])
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i < n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x] + dis[y] - 2 * dis[lca(x,y)]);
	}
	return 0;
}