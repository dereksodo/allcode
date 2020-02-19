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
const int maxn = 200005;
const int mod = 100003;
const int inf = 0x3f3f3f3f;
int n,m,tot;
int dis[maxn],vis[maxn];
int cnt[maxn],head[maxn << 1],nxt[maxn << 1],to[maxn << 1];
void add(int x,int y)
{
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dijkstra_fast(int x)
{
	priority_queue< pair<int,int> > q;
	memset(dis,63,sizeof(dis));
	dis[x] = 0;
	q.push(make_pair(0,1));
	cnt[x] = 1;
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
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(make_pair(-dis[v],v));
			}
			else if(dis[v] == dis[u] + 1)
			{
				cnt[v] += cnt[u];
				cnt[v] %= mod;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dijkstra_fast(1);
	for(int i = 1;i <= n; ++i)
	{
		printf("%d\n",cnt[i]);
	}
	return 0;
}