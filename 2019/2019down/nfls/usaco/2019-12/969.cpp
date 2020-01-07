#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int maxe = 2e3 + 5;
const int inf = 0x3f3f3f3f;
struct Edge{
	int u,v,f,w;
}e[maxe];
int n,m;
int dis[maxn];
bool vis[maxn];
int head[maxn],nxt[maxe],adj[maxe],wg[maxe],tot;
void addedge(int u,int v,int w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	adj[tot] = v;
	wg[tot] = w;

	nxt[++tot] = head[v];
	head[v] = tot;
	adj[tot] = u;
	wg[tot] = w;
}
priority_queue< pair<int,int> > q;
int dij(int lim)
{
	memset(vis,0x00,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	memset(head,0x00,sizeof(head));
	memset(nxt,0x00,sizeof(nxt));
	memset(adj,0x00,sizeof(adj));
	memset(wg,0x00,sizeof(wg));
	tot = 0;
	q.push(make_pair(0,1));
	dis[1] = 0;
	for(int i = 1;i <= m; ++i)
	{
		if(e[i].f >= lim)
		{
			addedge(e[i].u,e[i].v,e[i].w);
		}
	}
	while(!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if(vis[x])
		{
			continue;
		}
		vis[x] = 1;
		for(int e = head[x];e;e = nxt[e])
		{
			if(dis[x] + wg[e] < dis[adj[e]])
			{
				dis[adj[e]] = dis[x] + wg[e];
				q.push(make_pair(-dis[adj[e]],adj[e]));
			}
		}
	}
	return dis[n];
}
int main()
{
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].w,&e[i].f);
	}
	double ans = 0;
	for(int i = 1;i <= 1000; ++i)
	{
		ans = max(ans,(double)i / (double)dij(i));
	}
	printf("%lld\n",(ll)(ans * 1000000));
	return 0;
}