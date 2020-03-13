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
const int maxn = 110000;
const int maxm = 500010;
int head[maxm << 1],to[maxm << 1],nxt[maxm << 1];
int n,a,b;
int tot,cut[maxn];
int dfn[maxn],low[maxn],pd;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int v)
{
	dfn[v] = low[v] = ++pd;
	for(int i = head[v];i;i = nxt[i])
	{
		int u = to[i];
		if(!dfn[u])
		{
			tarjan(u);
			low[v] = min(low[v],low[u]);
			if(low[u] >= dfn[v] && v != a && dfn[b] >= dfn[u])
			{
				++cut[v];
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
	scanf("%d",&n);
	int u,v;
	scanf("%d%d",&u,&v);
	while(!(u == 0 && v == 0))
	{
		add(u,v);
		add(v,u);
		scanf("%d%d",&u,&v);
	}
	scanf("%d%d",&a,&b);
	tarjan(a);
	for(int i = 1;i <= n; ++i)
	{
		if(cut[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("No solution\n");
	return 0;
}