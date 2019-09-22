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
const int maxn = 100005;
const int maxn2 = 18;
struct edge{
	int to,next;
}e[maxn << 1];
int tot,head[maxn],depth[maxn],fa[maxn][maxn2];
int n,m;
int c[maxn],d[maxn];

void addedge(int x,int y)
{
	e[++tot].to = y;
	e[tot].next = head[x];
	head[x] = tot;

	e[++tot].to = x;
	e[tot].next = head[y];
	head[y] = tot;
}

void dfs(int u)
{
	for(int i = head[u];i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == fa[u][0])
		{
			continue;
		}
		fa[v][0] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

void pre()
{
	for(int j = 1;j < maxn2; ++j)
	{
		for(int i = 1;i <= n; ++i)
		{
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x,int y)
{
	if(depth[x] < depth[y])
	{
		swap(x,y);
	}
	int t = depth[x] - depth[y];
	for(int i = 17;i >= 0; --i)
	{
		if(t & (1 << i))
		{
			x = fa[x][i];
		}
	}
	if(x == y)
	{
		return x;
	}
	// printf("x = %d,y = %d\n",x,y);
	for(int i = 17;i >= 0; --i)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	if(x != y)
	{
		return fa[x][0];
	}
	return x;
}
// map<int,int> li[maxn];
// void creat(int index,int beg,int end)
// {
// 	if(depth[beg] > depth[end])
// 	{
// 		swap(beg,end);
// 	}
// 	// printf("%d %d,lca = %d\n",end,beg,LCA(end,beg));
// 	int ance = LCA(end,beg);
// 	if(ance != beg)
// 	{
// 		creat(index,end,ance);
// 		creat(index,ance,beg);
// 	}
// 	else
// 	{
// 		int now = end;
// 		while(now != beg)
// 		{
// 			li[index][now] = 1;
// 			now = fa[now][0];
// 		}
// 		li[index][beg] = 1;
// 	}
// }
int solve(int a,int b,int c,int d)
{
	int sa = LCA(a,b);
	int sc = LCA(c,d);
	if(depth[sa] < depth[sc])
	{
		swap(sa,sc);
		swap(a,c);
		swap(b,d);
	}
	if(LCA(sa,c) == sa || LCA(sa,d) == sa)
	{
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	memset(head,-1,sizeof(head));
	int n,m;
	cin>>n>>m;
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		// --x,--y;
		addedge(x,y);
	}
	dfs(1);
	pre();
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d",&c[i],&d[i]);
		// --c[i],--d[i];
		// creat(i,c[i],d[i]);
	}
	// for(int i = 1;i <= m; ++i)
	// {
	// 	printf("%d -> %d\n",c[i],d[i]);
	// 	for(auto iter = li[i].begin();iter != li[i].end(); ++iter)
	// 	{
	// 		printf("%d ",iter->first);
	// 	}
	// 	printf("\n");
	// }
	ll ans = 0;
	for(int i = 1;i <= m; ++i)
	{
		for(int j = i + 1;j <= m; ++j)
		{
			// if((li[j][LCA(c[i],d[i])] == 1)
			// 	|| (li[i][LCA(c[j],d[j])]) == 1)
			// {
			// 	ans++;
			// }
			ans += solve(c[i],d[i],c[j],d[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}