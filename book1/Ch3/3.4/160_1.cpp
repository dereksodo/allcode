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
int head[maxn],tot,n,m;
int dis[maxn],vis[maxn];
void add(int x,int y,int z)
{
	e[++tot] = (edge){y,head[x],z};
	head[x] = tot;
}
bool spfa(int u)
{
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(dis[v] < dis[u] + e[i].w)//<:pos,>:neg
		{
			dis[v] = dis[u] + e[i].w;
			if(vis[v] || spfa(v))
			{
				// vis[u] = 0;
				return 1;
			}
		}
	}
	vis[u] = 0;
	return 0;
}
void check()
{
	for(int i = 1;i <= n; ++i)
	{
		dis[i] = 1;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(head[i])
		{
			if(spfa(i))
			{
				printf("-1\n");
				return;
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans += dis[i];
	}
	printf("%lld\n",ans);
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		int fg,x,y;
		scanf("%d%d%d",&fg,&x,&y);
		if(fg == 1)
		{
			add(x,y,0);
			add(y,x,0);
		}
		if(fg == 2)
		{
			add(x,y,1);
		}
		if(fg == 3)
		{
			add(y,x,0);
		}
		if(fg == 4)
		{
			add(y,x,1);
		}
		if(fg == 5)
		{
			add(x,y,0);
		}
	}
	check();
	return 0;
}