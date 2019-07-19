#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e7 + 5;
int weight[maxn];
int value[maxn];
int vis[maxn];//不能重复选
int n,w;
int doit(int p,int k)
{
	int ret = 0;
	for(int i = 1;i <= k; ++i)
	{
		if(weight[i] <= p && !vis[i])
		{
			vis[i] = 1;
			ret = max(ret,doit(p - weight[i],k) + value[i]);
			vis[i] = 0;
		}
	}
	return ret;
}
int dp_solve()
{
	int dp[w + 1][n + 1];
	//dp[i][j] = k     总容量为i时,从前j个物品选,最大价值为k
	memset(dp,0x00,sizeof(dp));
	for(int i = 0;i <= w; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			//判断第j个是否可以装入当前的总容量为i
			if(i >= weight[j])
			{
				                            //此处如果为不能重复，如果能重复选则j - 1->j
				//判断是否装入第j个为最优 = max（装入，不装入）
				dp[i][j] = max(dp[i - weight[j]][j - 1] + value[j],dp[i][j - 1]);
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	// printf("dp::\n");
	// for(int i = 0;i <= w; ++i)
	// {
	// 	for(int j = 1;j <= n; ++j)
	// 	{
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	return dp[w][n];
}
int main()
{
	cin>>w>>n;
	memset(weight,0x00,sizeof(weight));
	memset(value,0x00,sizeof(value));
	memset(vis,0x00,sizeof(vis));
	for(int i = 1;i <= n; ++i)
	{
		cin>>weight[i]>>value[i];
	}
	printf("doit(%d) = %d\n",w,doit(w,n));
	printf("dp(%d) = %d\n",w,dp_solve());
	// printf("\ndoit::\n\n");
	// for(int i = 0;i <= w; ++i)
	// {
	// 	for(int j = 1;j <= n; ++j)
	// 	{
	// 		printf("%d ",doit(i,j));
	// 	}
	// 	printf("\n");
	// }
	return 0;
}