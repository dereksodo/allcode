#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int vis[maxn],ans[maxn];
vector<int> v;
int maxp;
void dfs(int u)
{
	v.push_back(u);
	vis[u] = 1;
	maxp = max(maxp,u);
	for(int i = 0;i < G[u].size(); ++i)
	{
		if(!vis[G[u][i]])
		{
			dfs(G[u][i]);
		}
	}
}
int main(int argc,char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[y].push_back(x);
		ans[i + 1] = i + 1;
	}
	for(int i = n;i >= 1; --i)
	{
		if(!vis[i])
		{
			maxp = i;
			v.clear();
			dfs(i);
			for(int j = 0;j < v.size(); ++j)
			{
//				printf("%d ",v[j]);
				ans[v[j]] = max(ans[v[j]],maxp);
			}
//			printf("\n");
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
