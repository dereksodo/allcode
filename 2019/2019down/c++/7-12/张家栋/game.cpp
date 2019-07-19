#include <bits/stdc++.h>
using namespace std;
//#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
const int n = 4;
int a[n << 2][n << 2],a1[n << 2][n << 2];
int ans;
int vis[n << 2];
int sum1[n << 2][n << 2];
int sum2[n << 2][n << 2];
int Pre;
void getans()
{
	for(int i = 1;i <= 4; ++i)
	{
		for(int j = 1;j <= 4; ++j)
		{
			a1[i][j] = a[i][j];
		}
	}
	for(int i = 1;i <= 4; ++i)
	{
		int y = vis[i] % 2;
		if(y)
		{
			for(int j = 1;j <= 4; ++j)
			{
				a1[j][i] = -a1[j][i]; 
			}
		}
	}
	for(int i = 5;i <= 8; ++i)
	{
		int y = vis[i] % 2;
		if(y)
		{
			for(int j = 1;j <= 4; ++j)
			{
				a1[i - 4][j] = -a1[i - 4][j]; 
			}
		}
	}
	int ret = 0;
	for(int i = 1;i <= 4; ++i)
	{
		for(int j = 1;j <= 4; ++j)
		{
			ret += a1[i][j];
		}
	}
	ans = max(ans,ret);
}
void dfs(int p)
{
	if(p == 0)
	{
		getans();
		return;
	}
	for(int i = 1;i <= 8; ++i)
	{
		vis[i]++;
		dfs(p - 1);
		vis[i]--;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	for(int i = 1;i <= n; ++i)
	{
		sum1[i][0] = 0;
		for(int j = 1;j <= n; ++j)
		{
			scanf("%d",&a[i][j]);
			sum1[i][j] = sum1[i][j - 1] + a[i][j];
			ans += a[i][j];
		}
	}
	
	debug("Sum1:\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
//			sum2[i][j] = sum2[i - 1][j] + a[i][j];
			debug("%d ",sum1[i][j]);
		}
		debug("\n");
	}
	
	for(int j = 1;j <= n; ++j)
	{
		for(int i = 1;i <= n; ++i)
		{
			sum2[i][j] = sum2[i - 1][j] + a[i][j];
//			debug("%d ",sum2[i][j]);
		}
//		debug("\n");
	}
	
	debug("sum2:\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
//			sum2[i][j] = sum2[i - 1][j] + a[i][j];
			debug("%d ",sum2[i][j]);
		}
		debug("\n");
	}
	for(int i = 1;i <= 7; ++i)
	{
		memset(vis,0x00,sizeof(vis));
		dfs(i);
	}
	
	int now = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			now += -a[i][j];
		}
	}
	ans = max(ans,now);
	cout<<ans<<endl;
//	cout<<clock()<<endl;
	return 0;
}
