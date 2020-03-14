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
#define clear(x) (memset(x,0x00,sizeof(x)))
const int maxn = 50;
const int maxm = 2000;
int deg[maxn],n,m,vis[maxm];
int G[maxn][maxm];
stack<int> ans;
void dfs(int x)
{
	for(int i = 1;i <= m; ++i)
	{
		if(G[x][i] && !vis[i])
		{
			vis[i] = 1;
			dfs(G[x][i]);
			ans.push(i);
		}
	}
}
int main(int argc, char const *argv[])
{
	int u,v;
	while(scanf("%d%d",&u,&v) && (u + v))
	{
		clear(vis),clear(G),clear(deg);
		int w;
		int st = 0;
		m = n = 0;
		while(u || v)
		{
			scanf("%d",&w);
			m = max(m,w);
			n = max(n,max(u,v));
			G[u][w] = v;
			G[v][w] = u;
			++deg[u],++deg[v];
			if(!st)
			{
				st = min(u,v);
			}
			scanf("%d%d",&u,&v);
		}
		int fg = 1;
		for(int i = 1;i <= n; ++i)
		{
			if(deg[i] & 1)
			{
				fg = 0;
				break;
			}
		}
		if(!fg)
		{
			printf("Round trip does not exist.\n");
		}
		else
		{
			dfs(st);
			while(!ans.empty())
			{
				printf("%d%c",ans.top(),((int)ans.size() == 1 ? '\n' : ' '));
				ans.pop();
			}
		}
	}
	return 0;
}