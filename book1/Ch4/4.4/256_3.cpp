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
const int maxn = 5e5 + 5;
const int maxm = 25;
int f[maxn][maxm];
int dis[maxn],dep[maxn];
int head[maxn << 1],nxt[maxn << 1],to[maxn << 1];
int lg[maxn];
int tot;
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dfs(int u,int fa)
{
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1;i <= lg[dep[u]]; ++i)
	{
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
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
	while(dep[x] > dep[y])
	{
		x = f[x][lg[dep[x] - dep[y]]];
	}
	for(int i = lg[dep[y]];i >= 0; --i)
	{
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	if(x != y)
	{
		x = f[x][0];
	}
	return x;
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	lg[0] = -1;
	for(int i = 1;i <= n; ++i)
	{
		lg[i] = lg[i >> 1] + 1;
	}
	dfs(1,0);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int l1 = lca(a,b);
		int l2 = lca(a,c);
		int l3 = lca(b,c);
		int ans,src;
		if(l1 == l2 && l2 == l3)
		{
			src = l1;
			ans = dep[a] + dep[b] + dep[c] - 3 * dep[l1];
		}
		else if(l1 == l2)
		{
			src = l3;
			ans = dep[b] + dep[c] - 2 * dep[l3] + dep[a] - dep[l1] + dep[l3] - dep[l1];
		}
		else if(l2 == l3)
		{
			src = l1;
			ans = dep[a] + dep[b] - 2 * dep[l1] + dep[c] - dep[l3] + dep[l1] - dep[l3];
		}
		else
		{
			src = l2;
			ans = dep[a] + dep[c] - 2 * dep[l2] + dep[b] - dep[l1] + dep[l2] - dep[l1];
		}
		printf("%d %d\n",src,ans);
	}
	return 0;
}