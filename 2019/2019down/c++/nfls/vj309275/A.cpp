#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3500;
int dp[maxn][maxn],weight[maxn],v[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&weight[i],&v[i]);
	}
	dp[0][0] = 0;
	for(int i = 0;i <= n; ++i)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = m;j >= 0; --j)
		{
			dp[i][j] = dp[i - 1][j];
//			for(int k = 1;weight[i] * k <= j; ++k)
//			{
//				dp[i][j] = max(dp[i][j],dp[i - 1][j - weight[i] * k] + v[i] * k);
//				printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
//			}
			if(weight[i] <= j)
			{
				dp[i][j] = max(dp[i][j],dp[i - 1][j - weight[i]] + v[i]);
			}
		}
	}
	cout<<dp[n][m]<<endl; 
	return 0;
}
