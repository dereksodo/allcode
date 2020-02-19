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
const int inf = 0x3f3f3f3f;
const int maxn = 25005;
int t,r,p,s;
int tot = 1;
ll dis[maxn];
int vis[maxn],head[maxn],deg[maxn];
vector<int> G[maxn];
struct node{
	int to,nxt,v;
}e[maxn << 4];
void add(int x,int y,int z)
{
	e[++tot] = (node){y,head[x],z};
	head[x] = tot;
}
struct tnode{
	ll dis;
	int ind;
	bool operator <(const tnode &b)const
	{
		return dis > b.dis;
	}
};
queue<int> q;
void dij(int now)
{
	priority_queue<tnode> pq;
	for(int i = 0;i < G[now].size(); ++i)
	{
		int u = G[now][i];
		pq.push((tnode){dis[u],u});
	}
	while(!pq.empty())
	{
		tnode u = pq.top();
		pq.pop();
		int x = u.ind;
		if(dis[x] < u.dis)
		{
			continue;
		}
		for(int i = head[x];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(vis[x] != vis[v] && !(--deg[vis[v]]))
			{
				q.push(vis[v]);
			}
			if(dis[x] == inf)
			{
				continue;
			}
			if(dis[v] > dis[x] + e[i].v)
			{
				dis[v] = dis[x] + e[i].v;
				if(vis[v] == vis[x])
				{
					pq.push((tnode){dis[v],v});
				}
			}
		}
	}
}
void dfs(int x,int col)
{
	vis[x] = col;
	G[col].push_back(x);
	for(int i = head[x];i;i = e[i].nxt)
	{
		int u = e[i].to;
		if(!vis[u])
		{
			dfs(u,col);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&t,&r,&p,&s);
	for(int i = 1;i <= t; ++i)
	{
		dis[i] = inf;
	}
	dis[s] = 0;
	for(int i = 1,x,y,z;i <= r; ++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	int col = 0;
	for(int i = 1;i <= t; ++i)
	{
		if(!vis[i])
		{
			dfs(i,++col);
		}
	}
	for(int i = 1,x,y,z;i <= p; ++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		++deg[vis[y]];
	}
	for(int i = 1;i <= col; ++i)
	{
		if(!deg[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		dij(u);
	}
	for(int i = 1;i <= t; ++i)
	{
		if(dis[i] == inf)
		{
			printf("NO PATH\n");
		}
		else
		{
			printf("%lld\n",dis[i]);
		}
	}
	return 0;
}