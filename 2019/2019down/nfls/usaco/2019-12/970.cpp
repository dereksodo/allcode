#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,num;
vector<int> G[maxn];
int vis[maxn];
int t[maxn];
void dfs(int x)
{
	if(vis[x] != 0)
	{
		return;
	}
	vis[x] = num;
	for(int i = 0;i < G[x].size(); ++i)
	{
		int now = G[x][i];
		if(t[now - 1] == t[x - 1])
		{
			dfs(now);
		}
	}
}
int main()
{
	// freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
	cin>>n>>m;
	memset(vis,0x00,sizeof(vis));
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&t[i]);
	}
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i = 0;i < m; ++i)
	{
		scanf()
	}
	string ans;
	cout<<ans<<endl;
	return 0;
}