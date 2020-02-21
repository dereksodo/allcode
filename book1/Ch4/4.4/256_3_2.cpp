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
int rmq[maxn << 1][maxm];
int dfn[maxn],dep[maxn << 1];
int head[maxn << 1],nxt[maxn << 1],to[maxn << 1];
int lg[maxn],ind[maxn << 1];
int tot,n,m;
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
int calc(int x,int y)
{
	return dep[x] < dep[y] ? x : y;
}
void dfs(int u,int fa,int deep)
{
	dfn[u] = ++tot;
	dep[tot] = deep;
	ind[tot] = u;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			dfs(v,u,deep + 1);
			ind[++tot] = u;
			dep[tot] = deep;
		}
	}
}
void init(int rt)
{
	int nn = 2 * n - 1;
	tot = 0;
	dfs(rt,0,1);
	for(int i = 1;i <= nn; ++i)
	{
		rmq[i][0] = i;
	}
	for(int j = 1;j < maxm; ++j)
	{
		for(int i = 1;i + (1 << j) - 1 <= nn; ++i)
		{
			rmq[i][j] = calc(rmq[i][j - 1],rmq[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int lca(int a,int b)
{
	int l = dfn[a],r = dfn[b];
	if(l > r)
	{
		swap(l,r);
	}
	int k = lg[r - l + 1];
	return ind[calc(rmq[l][k],rmq[r - (1 << k) + 1][k])];
}
int main(int argc, char const *argv[])
{
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
	init(1);
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