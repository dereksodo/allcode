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
const int maxn = 1e4 + 5;
struct edge{
	int to,nxt,w;
}e[maxn];
int head[maxn],tot;
int dis[maxn],vis[maxn];
void add(int x,int y,int z)
{
	e[++tot] = (edge){y,head[x],z};
	head[x] = tot;
}
bool spfa(int u)
{
	vis[u] = 1;
	for(int k = head[u];k;k = e[k].nxt)
	{
		if(dis[e[k].to] > dis[u] + e[k].w)
		{
			dis[e[k].to] = dis[u] + e[k].w;
			if(vis[e[k].to] || spfa(e[k].to))
			{
				vis[u] = 0;
				return 1;
			}
		}
	}
	vis[u] = 0;
	return 0;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot = 0;
		memset(head,0x00,sizeof(head));
		memset(dis,0x00,sizeof(dis));
		memset(vis,0x00,sizeof(vis));
		int n,m1,m2;
		scanf("%d%d%d",&n,&m1,&m2);
		for(int i = 1,x,y,z;i <= m1; ++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i = 1,x,y,z;i <= m2; ++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,-z);
		}
		bool circle = 0;
		for(int i = 1;i <= n; ++i)
		{
			if(spfa(i))
			{
				circle = 1;
				break;
			}
		}
		if(circle)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}