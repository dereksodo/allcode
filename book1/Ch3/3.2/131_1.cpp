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
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int n,m;
int dis[maxn][maxn],vis[maxn];
vector< pair<int,int> > G[maxn];
struct node{
	int ind,dist;
	node(int a = 0,int b = 0):ind(a),dist(b){};
	bool operator <(const node &b)const
	{
		return dist > b.dist;
	}
};
void dijkstra_fast(int x)
{
	priority_queue<node> q;
	for(int i = 0;i < maxn; ++i)
	{
		dis[x][i] = inf;
		vis[i] = 0;
	}
	dis[x][x] = 0;
	q.push(node(x,0));
	while(!q.empty())
	{
		node u = q.top();
		q.pop();

		int id = u.ind;
		if(vis[id])
		{
			continue;
		}
		vis[id] = 1;

		for(int i = 0;i < G[id].size(); ++i)
		{
			int v = G[id][i].first;
			int value = G[id][i].second;
			if(!vis[v] && dis[x][v] > dis[x][id] + value)
			{
				dis[x][v] = dis[x][id] + value;
				q.push(node(v,dis[x][v]));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(make_pair(v,w));
	}
	for(int i = 1;i <= n; ++i)
	{
		dijkstra_fast(i);
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans = max(ans,dis[i][k] + dis[k][i]);
	}
	printf("%d\n",ans);
	return 0;
}