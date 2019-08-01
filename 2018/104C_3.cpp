#include <iostream>
#include <vector>
using namespace std;
int indegree[105];
vector<int> G[110];
int vis[105];
int n,m;
int dfs(int v)
{
	if(vis[v])
	{
		return 0;
	}
	vis[v] = 1;
	int ret = 1;
	for(int i = 0;i < G[v].size(); ++i)
	{
		ret += dfs(G[v][i]);
	}
	return ret;
}
bool check()
{
	int ac = 0;
	for(int i = 0;i < n; ++i)
	{
		if(indegree[i] != 2 && !vis[i])
		{
			return 0;
		}
	}
	for(int i = 0;i < n; ++i)
	{
		if(!vis[i])
		{
			if(ac > 0)
			{
				return 0;
			}
			ac = dfs(i);
		}
	}
	return ac >= 3;
}
int main()
{
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
		indegree[x]++;
		indegree[y]++;
	}
	if(n != m)
	{
		printf("NO\n");
		return 0;
	}
	bool ok = 1;
	while(ok)
	{
		ok = 0;
		for(int i = 0;i < n; ++i)
		{
			if(indegree[i] == 1 && !vis[i])
			{
				vis[i] = 1;
				for(int j = 0;j < G[i].size(); ++j)
				{
					int cur = G[i][j];
					if(!vis[cur])
					{
						indegree[cur]--;
					}
				}
				ok = 1;
				break;
			}	
		}
	}
	if(check())
	{
		printf("FHTAGN!\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}