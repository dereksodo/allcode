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
const int maxn = 205;
struct Edge{
	int from,to,v;
	Edge(){};
	Edge(int a,int b,int c):from(a),to(b),v(c){};
	bool operator <(const Edge b)const
	{
		return v < b.v;
	}
}edge[maxn << 2];
vector<int> G[maxn];
int vis[maxn];
int mx[maxn][maxn];
int fa[maxn];
int cnt;
void dfs(int u)
{
	vis[u] = 1;
	cnt++;
	for(int i = 0;i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
int ff(int x)
{
	return fa[x] == x ? x : fa[x] = ff(fa[x]);
}
int n,m;
int kruskal()
{
	int MST = 0;
	int cnt = 0;
	for(int i = 1;i <= m; ++i)
	{
		if(cnt == n - 1)
		{
			break;
		}
		int u = ff(edge[i].from);
		int v = ff(edge[i].to);
		if(u != v)
		{
			vis[i] = 1;
			cnt++;
			MST += edge[i].v;
			for(int j = 0;j < G[u].size(); ++j)
			{
				for(int k = 0;k < G[v].size(); ++k)
				{
					mx[G[u][j]][G[v][k]] = mx[G[v][k]][G[u][j]] = edge[i].v;
				}
			}
			fa[u] = v;
			for(int j = 0;j < G[u].size(); ++j)
			{
				G[v].push_back(G[u][j]);
			}
		}
	}
	return MST;
}
int second_MST(int MST)
{
	int ret = 0x3f3f3f3f;
	for(int i = 1;i <= m; ++i)
	{
		if(!vis[i])
		{
			ret = min(ret,MST + edge[i].v - mx[edge[i].from][edge[i].to]);
		}
	}
	return ret;
}
map<int,int> mp;
int Kcnt;
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int cas = 1;cas <= T; ++cas)
	{
		memset(vis,0x00,sizeof(vis));
		for(int i = 1;i <= n; ++i)
		{
			G[i].clear();
		}
		mp.clear();
		Kcnt = 0;
		cin>>n>>m;
		for(int i = 1;i <= m; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(!mp[x])
			{
				mp[x] = ++Kcnt;
			}
			if(!mp[y])
			{
				mp[y] = ++Kcnt;
			}
			G[mp[x]].push_back(mp[y]);
			G[mp[y]].push_back(mp[x]);
			edge[i] = Edge(mp[x],mp[y],z);
		}
		// printf("Kcnt = %d\n",Kcnt);
		cnt = 0;
		dfs(1);
		printf("Case #%d : ",cas);
		if(cnt != n)
		{
			printf("No way\n");
			continue;
		}
		if(m == n - 1)
		{
			printf("No second way\n");
			continue;
		}
		for(int i = 1;i <= n; ++i)
		{
			G[i].clear();
			G[i].push_back(i);
			fa[i] = i;
		}
		memset(vis,0x00,sizeof(vis));
		sort(edge + 1,edge + m + 1);
		printf("%d\n",second_MST(kruskal()));
	}
	return 0;
}