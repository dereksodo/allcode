#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
const int maxn = 305;
vector<int> G[maxn];
vector<int> dfss;
int leaf[maxn];
bool vis[maxn];
int n;
void dfs(int index)
{
	dfss.push_back(index);
	vis[index] = 1;
	for(int i = 0;i < G[index].size(); ++i)
	{
		int cur = G[index][i];
		if(!vis[cur])
		{
			vis[cur] = 1;
			dfs(cur);
		}
	}
}
void Print(int father,int index)
{
	vis[index] = 1;
	if(leaf[index] == 1)
	{
		printf("%d %d ",index + 1,father + 1);
		return;
	}
	for(int i = 0;i < G[index].size(); ++i)
	{
		if(!vis[G[index][i]])
		{
			vis[G[index][i]] = 1;
			printf("%d ",index + 1);
			Print(index,G[index][i]);
			printf("%d ",index + 1);
		}
	}
}
/*
6
1 2
1 3
2 4
4 5
4 6
5 6 3

Ans::
1 2 4 5 4 6 4 2 1 3 1 
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		int x,y;
		cin>>x>>y;
		--x,--y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	string ss;
	getline(cin,ss);
	stringstream s(ss);
	int curr;
	while(s>>curr)
	{
		leaf[curr - 1] = 1;
	}
	dfs(0);
	memset(vis,0x00,sizeof(vis));
	for(int i = 0;i < G[0].size(); ++i)
	{
		Print(0,i);
	}
	printf("\n");
	return 0;
}