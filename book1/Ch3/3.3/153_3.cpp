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
const int maxn = 5005;
const int maxm = 3e5 + 5;
const int inf = 0x3f3f3f3f;
struct edge{
	int to,nxt,w;
}e[maxm];
int head[maxn],tot;
int dis[maxn],vis[maxn];
void add(int x,int y,int z)
{
	e[++tot] = (edge){y,head[x],z};
	head[x] = tot;
}
bool spfa_c(int u)
{
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(dis[v] > dis[u] + e[i].w)
		{
			dis[v] = dis[u] + e[i].w;
			if(vis[v] || spfa_c(v))
			{
				vis[u] = 0;//prevent next memset
				return 1;
			}
		}
	}
	vis[u] = 0;
	return 0;
}
void spfa(int u)
{
	memset(vis,0x00,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	queue<int> q;
	q.push(u);
	dis[u] = 0;
	vis[u] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[u] + e[i].w < dis[v])
			{
				dis[v] = dis[u] + e[i].w;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1,x,y,z;i <= m; ++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	bool fg = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(spfa_c(i))
		{
			fg = 1;
			break;
		}
	}
	if(fg)
	{
		printf("-1\n");
		return 0;
	}
	spfa(s);
	for(int i = 1;i <= n; ++i)
	{
		if(dis[i] != inf)
		{
			printf("%d\n",dis[i]);
		}
		else
		{
			printf("NoPath\n");
		}
	}
	return 0;
}