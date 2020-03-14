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
#define clear(x) (memset(x,0x00,sizeof(x)))
const int maxn = 100005;
int head[maxn],nxt[maxn << 1],to[maxn << 1];
int dfn[maxn],low[maxn],cut[maxn],pd,tot;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void init()
{
	clear(dfn),clear(low),clear(cut),clear(head),clear(nxt),clear(to);
	pd = tot = 0;
}
void tarjan(int v,int f)
{
	dfn[v] = low[v] = ++pd;
	for(int i = head[v];i;i = nxt[i])
	{
		int u = to[i];
		if(!dfn[u])
		{
			tarjan(u,v);
			low[v] = min(low[v],low[u]);
			if(dfn[v] <= low[u])
			{
				++cut[v];
			}
		}
		else if(u != f)
		{
			low[v] = min(low[v],dfn[u]);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d%d",&n,&m) && (n + m))
	{
		init();
		for(int i = 0,x,y;i < m; ++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		int cnt = 0,mx = -1e9;
		for(int i = 0;i < n; ++i)
		{
			if(!dfn[i])
			{
				tarjan(i,-1);
				++cnt;
				cut[i]--;
			}
		}
		for(int i = 0;i < n; ++i)
		{
			mx = max(mx,cut[i]);
		}
		printf("%d\n",mx + cnt);
	}
	return 0;
}