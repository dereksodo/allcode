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
const int maxn = 100005;
const int maxm = 500005;
int n,m;
int head[maxn],nxt[maxm << 1],to[maxm << 1];
int dfn[maxn],low[maxn],tot,pd;
ll ans[maxn];
int sz[maxn];
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int v)
{
	dfn[v] = low[v] = ++pd;
	ll sum = 0;
	sz[v] = 1;
	for(int i = head[v];i;i = nxt[i])
	{
		int u = to[i];
		if(!dfn[u])
		{
			tarjan(u);
			sz[v] += sz[u];
			if(low[u] >= dfn[v])
			{
				ans[v] += sz[u] * sum;
				sum += sz[u];
			}
			low[v] = min(low[v],low[u]);
		}
		else
		{
			low[v] = min(low[v],dfn[u]);
		}
	}
	ans[v] += (n - sum - 1) * sum;
	ans[v] += n - 1;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 0,u,v;i < m; ++i)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	tarjan(1);
	for(int i = 1;i <= n; ++i)
	{
		printf("%lld\n",ans[i] << 1);
	}
	return 0;
}