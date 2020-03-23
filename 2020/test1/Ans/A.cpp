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
int T,n,m,cnt,fg;
int a[maxn],b[maxn],t[maxn],u[maxn],v[maxn];
int col[maxn],f[maxn],dep[maxn];
ll sum[maxn],s[2];
vector<int> G[maxn];
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
void dfs(int u,int fa)
{
	s[dep[u] & 1] += sum[u];
	for(int i = 0;i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(v == fa)
		{
			continue;
		}
		if(!dep[v])
		{
			dep[v] = dep[u] + 1;
			dfs(v,u);
		}
		else if(((dep[u] + dep[v]) & 1) == 0)
		{
			fg = 1;
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&T);
	while(T--)
	{
		memset(dep,0x00,sizeof(dep));
		memset(sum,0x00,sizeof(sum));
		memset(f,0x00,sizeof(f));
		cnt = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
			f[i] = i;
		}
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&b[i]);
		}
		for(int i = 1;i <= m; ++i)
		{
			scanf("%d%d%d",&t[i],&u[i],&v[i]);
			if(t[i] == 2)
			{
				if(ff(u[i]) != ff(v[i]))
				{
					f[ff(u[i])] = ff(v[i]);
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			if(ff(i) == i)
			{
				col[i] = ++cnt;
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			col[i] = col[ff(i)];
			sum[col[i]] += (a[i] - b[i]);
		}
		for(int i = 1;i <= cnt; ++i)
		{
			G[i].clear();
		}
		for(int i = 1;i <= m; ++i)
		{
			if(t[i] == 1)
			{
				G[col[u[i]]].push_back(col[v[i]]);
				G[col[v[i]]].push_back(col[u[i]]);
			}
		}
		int ans = 1;
		for(int i = 1;i <= cnt; ++i)
		{
			if(!dep[i])
			{
				dep[i] = 1;
				fg = 0;
				s[0] = s[1] = 0;
				dfs(i,0);
				if(fg)
				{
					if((s[0] + s[1]) & 1)
					{
						ans = 0;
						break;
					}
				}
				else
				{
					if(s[0] != s[1])
					{
						ans = 0;
						break;
					}
				}
			}
		}
		if(ans)
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