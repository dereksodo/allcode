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
const int maxn = 500010;
struct ss{
	int to,nxt,v;
}data[maxn];
int head[maxn],qu[maxn],vis[maxn],dis[maxn];
int co[maxn],sum[maxn],x[maxn],y[maxn],dfn[maxn],low[maxn],ins[maxn];
int n,m,p,q,pd,ans,tot,inx,S,s,t,P;
int sta[maxn],mey[maxn];
void add(int a,int b)
{
	data[++p] = (ss){b,head[a],0};
	head[a] = p;
}
void Add(int a,int b,int c)
{
	data[++p] = (ss){b,head[a],c};
	head[a] = p;
}
void tarjan(int a)
{
	dfn[a] = low[a] = ++pd;
	ins[a] = 1;
	sta[++inx] = a;
	for(int i = head[a];i;i = data[i].nxt)
	{
		int v = data[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[a] = min(low[a],low[v]);
		}
		else if(ins[v])
		{
			low[a] = min(low[a],dfn[v]);
		}
	}
	if(dfn[a] == low[a])
	{
		tot++;
		while(sta[inx + 1] != a)
		{
			co[sta[inx]] = tot;
			sum[tot] += mey[sta[inx]];
			ins[sta[inx--]] = 0;
		}
	}
}
void spfa()
{
	for(int i = 1;i <= tot; ++i)
	{
		dis[i] = 0x7fffffff;
	}
	int ts = co[S];
	dis[ts] = -sum[ts];
	qu[0] = ts;
	p = q = 0;
	while(p <= q)
	{
		s = qu[p % n];
		vis[s] = 0;
		t = head[s];
		while(t)
		{
			int u = data[t].to;
			if(dis[s] + data[t].v < dis[u])
			{
				dis[u] = dis[s] + data[t].v;
				if(!vis[u])
				{
					qu[++q % n] = u;
					vis[u] = 1;
				}
			}
			t = data[t].nxt;
		}
		++p;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&mey[i]);
	}	
	for(int i = 1;i <= n; ++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	memset(data,0x00,sizeof(data));
	memset(head,0x00,sizeof(head));
	p = 0;
	for(int i = 1;i <= m; ++i)
	{
		if(co[x[i]] != co[y[i]])
		{
			Add(co[x[i]],co[y[i]],-sum[co[y[i]]]);
		}
	}
	scanf("%d",&S);
	spfa();
	scanf("%d",&P);
	for(int i = 1,now;i <= P; ++i)
	{
		scanf("%d",&now);
		if(-dis[co[now]] > ans)
		{
			ans = -dis[co[now]];
		}
	}
	printf("%d\n",ans);
	return 0;
}