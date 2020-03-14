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
int head[maxn],dfn[maxn],low[maxn],vis[maxn];
int ans,pd,tot;
int nxt[maxn << 1],to[maxn << 1];
int n,m;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
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
			if(low[u] > dfn[v])
			{
				ans++;
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
	while(~scanf("%d%d",&n,&m) && n && m)
	{
		tot = pd = ans = 0;
		memset(dfn,0x00,sizeof(dfn));
		memset(low,0x00,sizeof(low));
		memset(vis,0x00,sizeof(vis));
		memset(head,0x00,sizeof(head));
		memset(to,0x00,sizeof(to));
		memset(nxt,0x00,sizeof(nxt));
		for(int i = 1,x,y;i <= m; ++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		tarjan(1,1);
		printf("%d\n",ans);
	}
	return 0;
}