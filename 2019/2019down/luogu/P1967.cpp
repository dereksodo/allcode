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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 50005;
const int maxn2 = 21;
const int inf = 0x3f3f3f3f;
vector<int> G[maxn];
vector<int> G2[maxn];
int f[maxn];
int fa[maxn][maxn2],vis[maxn],w[maxn][maxn2];
int dep[maxn];
struct edge{
	int value,to,next;
	edge(int t = 0,int nt = 0,int v = 0)
	{
		to = t;
		next = nt;
		value = v;
	}
	bool operator <(const edge &b)const
	{
		return value < b.value;
	}
}e[maxn << 1];
priority_queue<edge> pq;
//pq,e使用edge的意义不相同
int tot,head[maxn],n,m;
void addedge(int x,int y,int v)
{
	e[++tot].to = y;
	e[tot].next = head[x];
	e[tot].value = v;
	head[x] = tot;

	e[++tot].to = x;
	e[tot].next = head[y];
	e[tot].value = v;
	head[y] = tot;
}
void dfs(int u)
{
	vis[u] = 1;
	for(int i = head[u];i; i = e[i].next)
	{
		int v = e[i].to;
		if(!vis[v])
		{
			fa[v][0] = u;
			dep[v] = dep[u] + 1;
			w[v][0] = e[i].value;
			dfs(v);
		}
	}
}
void pre()
{
	for(int j = 1;j < maxn2; ++j)
	{
		for(int i = 1;i <= n; ++i)
		{
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
			w[i][j] = min(w[i][j - 1],w[fa[i][j - 1]][j - 1]);
		}
	}
}
int ff(int x)
{
	if(f[x] != x)
	{
		f[x] = ff(f[x]);
	}
	return f[x];
}
int LCA(int x,int y)
{
	if(x == y)
	{
		return 0;
	}
	if(ff(x) != ff(y))
	{
		return -1;
	}
	int ans = inf;
	if(dep[x] > dep[y])
	{
		swap(x,y);
	}
	for(int i = 20;i >= 0; --i)
	{
		if(dep[fa[y][i]] >= dep[x])
		{
			ans = min(ans,w[y][i]);
			y = fa[y][i];
		}
	}
	if(x == y)
	{
		return ans;
	}
	for(int i = 20;i >= 0; --i)
	{
		if(fa[x][i] != fa[y][i])
		{
			ans = min(ans,min(w[x][i],w[y][i]));
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	ans = min(ans,min(w[x][0],w[y][0]));
	return ans;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		pq.push(edge(x,y,z));
	}
	for(int i = 1;i <= n; ++i)
	{
		f[i] = i;
	}
	for(int i = 1;i <= m; ++i)
	{
		edge now = pq.top();
		pq.pop();
		// printf("%d->%d,value = %d\n",now.to,now.next,now.value);
		int f1 = ff(now.to);
		int f2 = ff(now.next);
		if(f1 != f2)
		{
			f[f1] = f2;
			addedge(now.to,now.next,now.value);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!vis[i])
		{
			dep[i] = 1;
			dfs(i);
			fa[i][0] = i;
			w[i][0] = inf;
		}
	}
	pre();
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
	return 0;
}