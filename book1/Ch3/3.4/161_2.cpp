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
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;
struct edge{
	int to,nxt,w;
}e[maxm];
int head[maxn],tot,n;
int dis[maxn],vis[maxn],cnt[maxn];
void add(int x,int y,int z)
{
	e[++tot] = (edge){y,head[x],z};
	head[x] = tot;
}
bool spfa(int src)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0x00,sizeof(vis));
	memset(cnt,0x00,sizeof(cnt));
	queue<int> q;
	q.push(src);
	dis[src] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		++cnt[u];
		if(cnt[u] == n)
		{
			return 1;
		}
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
	return 0;
}
int main(int argc, char const *argv[])
{
	int m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= n; ++i)
	{
		add(0,i,0);
	}
	for(int i = 1;i <= m1; ++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
	}
	for(int i = 1;i <= m2; ++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(y,x,-w);
	}
	int fg = spfa(0);
	if(fg)
	{
		printf("-1\n");
	}
	else
	{
		spfa(1);
		if(dis[n] == 0x3f3f3f3f)
		{
			printf("-2\n");
		}
		else
		{
			printf("%d\n",dis[n]);
		}
	}
	return 0;
}