#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> G[105];
bool vis[105];
int cnt = 0;
void dfs(int index)
{
	vis[index] = 1;
	for(int i = 0;i < G[index].size(); ++i)
	{
		if(!vis[G[index][i]])
		{
			dfs(G[index][i]);
			cnt++;
		}
	}
}
int main(int argc,char const *Argv[])
{
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n != m)
	{
		printf("NO\n");
		return 0;
	}
	dfs(1);
	if(cnt == n - 1)
	{
		printf("FHTAGN!\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}