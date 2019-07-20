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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 5005;
const int inf = 0x3f3f3f3f;
struct edge{
	int to,next,flow,cost;
}e[maxn << 1];
int head[maxn],arcs[maxn];
int dep[maxn],gap[maxn];
int a[maxn],dp[maxn];
int cnt,n;
void addedge(int x,int y,int flow,int cost = 0)
{
	e[cnt].to = y;
	e[cnt].next = head[x];
	e[cnt].flow = flow;
	e[cnt].cost = cost;
	head[x] = cnt++;

	e[cnt].to = x;
	e[cnt].next = head[y];
	e[cnt].flow = 0;
	e[cnt].cost = -cost;
	head[y] = cnt++;
}
namespace sap{
	void bfs(int s)
	{
		memset(dep,0x00,sizeof(dep));
		memset(gap,0x00,sizeof(gap));
		queue<int> q;
		dep[s] = 1;
		gap[1] = 1;
		q.push(s);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			for(int i = head[v];i != -1; i = e[i].next)
			{
				int u = e[i].to;
				if(!dep[u])
				{
					q.push(u);
					dep[u] = dep[v] + 1;
					gap[dep[u]]++;
				}
			}
		}
	}
	int dfs(int s,int u,int t,int dis)
	{
		if(u == t)
		{
			return dis;
		}
		int sum = 0;
		for(int i = arcs[u];i != -1; i = e[i].next)
		{
			int v = e[i].to;
			if(dep[u] == dep[v] + 1)
			{
				int nowflow = dfs(s,v,t,min(dis,e[i].flow));
				sum += nowflow;
				dis -= nowflow;
				e[i].flow -= nowflow;
				e[i ^ 1].flow += nowflow;
				if(!dis)
				{
					return sum;
				}
			}
		}
		if(!(--gap[dep[u]]))
		{
			dep[s] = n + 1;
		}
		dep[u]++;
		gap[dep[u]]++;
		arcs[u] = head[u];
		return sum;
	}
	int sap(int s,int t)
	{
		int maxflow = 0;
		bfs(t);
		memcpy(arcs,head,sizeof(head));
		maxflow = dfs(s,s,t,inf);
		while(dep[s] <= n)
		{
			int cur = dfs(s,s,t,inf);
			maxflow += cur;
		}
		return maxflow;
	}
	int main(int s,int t)
	{
		return sap(s,t);
	}
};
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		dp[i] = 1;
		for(int j = 1;j < i; ++j)
		{
			if(a[i] >= a[j])
			{
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		ans = max(ans,dp[i]);
	}
	if(n == 1)
	{
		printf("1\n1\n1\n");
		return 0;
	}
	if(ans == 1)
	{
		printf("%d\n%d\n%d\n",1,n,n);
		return 0;
	}
	cnt = 0;
	memset(head,-1,sizeof(head));
	int s = 0,t = 2 * n + 1;
	addedge(1,1 + n,1);
	addedge(n,n + n,1);
	for(int i = 1;i <= n; ++i)
	{
		if(i != 1 && i != n)
		{
			addedge(i,i + n,1);
		}
		if(dp[i] == 1)
		{
			addedge(s,i,inf);
		}
		if(dp[i] == ans)
		{
			addedge(i + n,t,inf);
		}
		for(int j = i + 1;j <= n; ++j)
		{
			if((dp[j] == dp[i] + 1) && a[i] <= a[j])
			{
				addedge(i + n,j,1);
			}
		}
	}
	n = 2 * n + 2;
	int res = sap::main(s,t);
	printf("%d\n%d\n",ans,res);
	e[0].flow = inf;
	e[2].flow = inf;
	printf("%d\n",res + sap::main(s,t));
	return 0;
}