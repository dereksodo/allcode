#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[10005];
int ans = 0;
void dfs(int i,vector<int> check,int dis)
{
	check[i] = 1;
	if(dis == 2)
	{
		ans++;
		return;
	}
	for(int j = 0;j < graph[i].size(); ++j)
	{
		if(!check[graph[i][j]])
		{
			dfs(graph[i][j],check,dis + 1);
		}
	}
}
int main(int argc,char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n - 1; ++i)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i = 1;i <= n; ++i)
	{
		vector<int> check(n + 1);
		check.resize(n + 1,0);
		dfs(i,check,0);
	}
	cout<<ans/2<<endl;
	return 0;
}