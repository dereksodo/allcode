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
const int maxn = 1005;
int n,m,cnt,pd,son;
int cut[maxn],low[maxn],dfn[maxn];
int rt;
int head[maxn << 1],nxt[maxn << 1],to[maxn << 1],tot;
void add(int x,int y)
{
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void tarjan(int v)
{
	low[v] = dfn[v] = ++pd;
	for(int i = head[v];i; i = nxt[i])
	{
		int u = to[i];
		if(!dfn[u])
		{
			tarjan(u);
			low[v] = min(low[v],low[u]);
			if(low[u] >= dfn[v] && v != rt)
			{
				++cut[v];
			}
			else if(v == rt)
			{
				++son;
			}
		}
		else
		{
			low[v] = min(low[v],dfn[u]);
		}
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d",&n) == 1 && n)
	{
		int u,v;
		tot = pd = son = cnt = 0;
		rt = 1;
		memset(cut,0x00,sizeof(cut));
		memset(low,0x00,sizeof(low));
		memset(dfn,0x00,sizeof(dfn));
		memset(head,0x00,sizeof(head));
		memset(nxt,0x00,sizeof(nxt));
		memset(to,0x00,sizeof(to));
		while(scanf("%d",&u) == 1 && u)
		{
			while(getchar() != '\n')
			{
				scanf("%d",&v);
				add(u,v);
				add(v,u);
			}
		}
		tarjan(rt);
		for(int i = 1;i <= n; ++i)
		{
			if(cut[i])
			{
				++cnt;
			}
		}
		if(son > 1)
		{
			++cnt;
		}
		printf("%d\n",cnt);
	}
	return 0;
}