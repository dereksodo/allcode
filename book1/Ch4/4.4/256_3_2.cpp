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
int read() {
    char ch = getchar();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
    return sum;
}
const int maxn = 1e6 + 5;
const int maxm = 30;
int rmq[maxn][maxm];
int dfn[maxn],dep[maxn];
int head[maxn],nxt[maxn],to[maxn];
int lg[maxn],ind[maxn];
int tot,id,n,m;
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dfs(int u,int fa)
{
	dfn[++id] = u;
	dep[u] = dep[fa] + 1;
	ind[u] = id;
	for(int i = head[u];i;i = nxt[i])//use this, in function add, 
									 //nxt[++tot] instead of nxt[tot++]
	{
		int v = to[i];
		if(v != fa)
		{
			dfs(v,u);
			dfn[++id] = u;
		}
	}
}
void init()
{
	id = 0;
	dfs(1,0);//rt,0
	lg[0] = -1;
	for(int i = 1;i <= id; ++i)
	{
		lg[i] = lg[i >> 1] + 1;
	}
	for(int i = 1;i <= id; ++i)
	{
		rmq[i][0] = dfn[i];
	}
	for(int j = 1;j <= lg[id]; ++j)
	{
		for(int i = 1;i + (1 << j) - 1 <= id; ++i)
		{
			if(dep[rmq[i][j - 1]] <= dep[rmq[i + (1 << (j - 1))][j - 1]])
			{
				rmq[i][j] = rmq[i][j - 1];
			}
			else
			{
				rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}
int lca(int a,int b)
{
	int u = ind[a],v = ind[b];
	if(u > v)
	{
		swap(u,v);
	}
	int k = lg[v - u + 1];
	int ret1 = rmq[u][k],ret2 = rmq[v - (1 << k) + 1][k];
	return dep[ret1] > dep[ret2] ? ret2 : ret1;
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
	init();
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