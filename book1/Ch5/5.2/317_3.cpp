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
const int maxn = 6005;
int head[maxn],nxt[maxn],to[maxn],tot;
int happy[maxn],f[maxn][2],vis[maxn];
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dp(int u,int fa)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			dp(v,u);
		}
		f[u][0] += max(f[v][0],f[v][1]);
		f[u][1] += f[v][0];
	}
	f[u][1] += happy[u];
}
int main(int argc, char const *argv[])
{
	int n,u,v;
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&happy[i]);
	}
	int rt = 1;
	while(scanf("%d%d",&u,&v) && u && v)
	{
		add(v,u);
		vis[u] = 1;
	}
	while(vis[rt])
	{
		++rt;
	}
	dp(rt,0);
	printf("%d\n",max(f[rt][0],f[rt][1]));
	return 0;
}