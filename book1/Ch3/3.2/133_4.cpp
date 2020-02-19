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
const int inf = 0x3f3f3f3f;
int n,m,tot,ans;
int dis[10][maxn],vis[maxn];
int cnt[maxn],head[maxn << 1],nxt[maxn << 1];
int to[maxn << 1],w[maxn << 1];
int home[10];
void add(int x,int y,int val)
{
	to[++tot] = y;
	w[tot] = val;
	nxt[tot] = head[x];
	head[x] = tot;
}
void df(int x,int fg)
{
	priority_queue< pair<int,int> > q;
	memset(dis[fg],63,sizeof(dis[fg]));
	memset(vis,0x00,sizeof(vis));
	dis[fg][x] = 0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			int val = w[i];
			if(dis[fg][v] > dis[fg][u] + val)
			{
				dis[fg][v] = dis[fg][u] + val;
				q.push(make_pair(-dis[fg][v],v));
			}
		}
	}
}
void dfs(int sum,int s,int last)
{
	if(sum >= ans)
	{
		return;
	}
	if(s == 5)
	{
		ans = sum;
		return;
	}
	for(int i = 1;i <= 5; ++i)
	{
		int u = home[i];
		if(!vis[u])
		{
			vis[u] = 1;
			dfs(sum + dis[i][last],s + 1,u);
			vis[u] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= 5; ++i)
	{
		scanf("%d",&home[i]);
	}
	for(int i = 1;i <= m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i = 1;i <= 5; ++i)
	{
		df(home[i],i);
	}
	memset(vis,0x00,sizeof(vis));
	// memset(dis[0],0x00,sizeof(dis[0]));
	// for(int i = 1;i <= 5; ++i)
	// {
	// 	for(int j = 1;j <= n; ++j)
	// 	{
	// 		printf("%d ",dis[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n\n");
	ans = 0x3f3f3f3f;
	dfs(0,0,1);
	printf("%d\n",ans);
	return 0;
}