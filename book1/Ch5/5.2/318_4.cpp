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
int head[maxn],nxt[maxn],to[maxn],tot;
int c[maxn],f[maxn][2],vis[maxn];
int n,m;
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dp(int u,int fa)
{
	f[u][0] = f[u][1] = 1;
	if(u <= m)
	{
		f[u][1 - c[u]] = 0x3f3f3f3f;
	}
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			dp(v,u);
			f[u][0] += min(f[v][0] - 1,f[v][1]);
			f[u][1] += min(f[v][0],f[v][1] - 1);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&c[i]);
	}
	for(int i = 1,u,v;i < n; ++i)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dp(m + 1,0);
	printf("%d\n",min(f[m + 1][0],f[m + 1][1]));
	return 0;
}