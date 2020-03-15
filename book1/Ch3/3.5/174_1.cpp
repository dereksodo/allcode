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
const int maxn = 105;
int head[maxn],nxt[maxn * maxn],to[maxn * maxn],tot;
int vis[maxn],pd,dfn[maxn],low[maxn],sta[maxn],f[maxn];
int in[maxn],out[maxn],inx,num,n;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int x)
{
	dfn[x] = low[x] = ++pd;
	sta[++inx] = x;
	vis[x] = 1;
	for(int i = head[x];i;i = nxt[i])
	{
		int v = to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[x] = min(low[x],low[v]);
		}
		else if(vis[v])
		{
			low[x] = min(low[x],dfn[v]);
		}
	}
	if(low[x] == dfn[x])
	{
		do{
			int t = sta[inx--];
			f[t] = num;
			vis[t] = 0;
		}while(x != sta[inx + 1]);
		++num;
	}
}
void getans()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = head[i];j;j = nxt[j])
		{
			int v = to[j];
			if(f[i] != f[v])
			{
				in[f[v]]++;
				out[f[i]]++;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		while(scanf("%d",&t) && t)
		{
			add(i,t);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	getans();
	int an1 = 0,an2 = 0;
	for(int i = 0;i < num; ++i)
	{
		if(!in[i])
		{
			++an1;
		}
		if(!out[i])
		{
			++an2;
		}
	}
	if(num == 1)
	{
		printf("1\n0\n");
	}
	else
	{
		printf("%d\n%d\n",an1,max(an1,an2));
	}
	return 0;
}