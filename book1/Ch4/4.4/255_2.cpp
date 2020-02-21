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
const int maxn = 4e4 + 5;
const int maxe = 35;
int dis[maxn],dep[maxn],f[maxn][maxe],tot,n;
int head[maxn << 1],to[maxn << 1],nxt[maxn << 1];
void add(ll x,ll y)
{
	nxt[++tot] = head[x];
	to[tot] = y;
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
	int m,root;
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(v == -1)
		{
			root = u;
			continue;
		}
		add(u,v);
		add(v,u);
	}
	dfs(root,0);
	scanf("%d",&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int rt = lca(x,y);
		// printf("rt = %d\n",rt);
		if(rt == x)
		{
			printf("1\n");
		}
		else if(rt == y)
		{
			printf("2\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}