#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,num;
vector<int> G[maxn];
int vis[maxn];
string s;
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
		if(s[now - 1] == s[x - 1])
		{
			dfs(now);
		}
	}
}
int main()
{
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	memset(vis,0x00,sizeof(vis));
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	num = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(!vis[i])
		{
			num++;
			dfs(i);
		}
	}
	string ans;
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		char c;
		cin>>x>>y>>c;
		// printf("%d %d %c\n",x,y,c);
		// printf("s[%d] = %c, vis[%d] = %d,vis[%d] = %d\n",x - 1,s[x - 1],x,vis[x],y,vis[y]);
		if(s[x - 1] == c || vis[x] != vis[y])
		{
			ans += '1';
		}
		else
		{
			ans += '0';
		}
	}
	cout<<ans<<endl;
	return 0;
}