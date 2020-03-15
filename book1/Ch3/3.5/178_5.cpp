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
#define other(x) (x & 1 ? x + 1 : x - 1)
const int maxn = 20005;
const int maxm = 42005;
int nxt[maxm],to[maxm],head[maxn],tot;
int sta[maxn],inx,cnt,co[maxn];
int dfn[maxn],low[maxn],ins[maxn],pd;
int n,m;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++pd;
	sta[++inx] = u;
	ins[u] = 1;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(ins[v])
		{
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		cnt++;
		while(sta[inx + 1] != u)
		{
			co[sta[inx]] = cnt;
			ins[sta[inx--]] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1,a,b;i <= m; ++i)
	{
		scanf("%d%d",&a,&b);
		add(a,other(b));
		add(b,other(a));
	}
	n *= 2;
	for(int i = 1;i <= n; ++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	int f = 0;
	for(int i = 1;i <= n; i += 2)
	{
		if(co[i] == co[i + 1])
		{
			f = 1;
			break;
		}
	}
	if(f)
	{
		printf("NIE\n");
	}
	else
	{
		for(int i = 1;i <= n; ++i)
		{
			if(co[i] < co[other(i)])
			{
				printf("%d\n",i);
			}
		}
	}
	return 0;
}