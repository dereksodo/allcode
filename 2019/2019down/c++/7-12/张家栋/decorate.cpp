#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
const int maxn = 50005;
vector<int> G[maxn];
int color[maxn];
int cnt,cnt0;
void dfs(int u,int fa)
{
	cnt++;
	if(color[u] == 0)
	{
		cnt0++;
	}
	for(int i = 0;i < G[u].size(); ++i)
	{
		if(G[u][i] != fa)
		{
			if(color[G[u][i]] != -1)
			{
				if(color[G[u][i]] == color[u])
				{
					printf("-1\n");
					exit(0);
				}
			}
			else
			{
				color[G[u][i]] = 1 - color[u];
				dfs(G[u][i],u);
			}
		}
	}
}

int main()
{
	freopen("decorate.in","r",stdin);
	freopen("decorate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		color[i] = -1;
	}
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(color[i] == -1)
		{
			color[i] = 0;
			cnt = cnt0 = 0;
			dfs(i,-1);
			ans += max(cnt0,cnt - cnt0);
		}
	}
	cout<<ans<<endl;
	return 0;
}
