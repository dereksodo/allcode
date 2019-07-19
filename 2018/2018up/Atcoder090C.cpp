#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char const *argv[])
{
	int n;
	cin>>n;
	int a[2][n];
	int dp[2][n];
	for(int i = 0;i < 2; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 0;i < 2; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			cin>>a[i][j];
		}
	}
	dp[0][0] = a[0][0];
	for(int j = 1;j < n; ++j)
	{
		dp[0][j] = dp[0][j - 1] + a[0][j];
		// printf("dp[%d][%d] = %d\n",0,j,dp[0][j]);
	}
	dp[1][0] = a[0][0] + a[1][0];
	for(int j = 1;j < n; ++j)
	{
		dp[1][j] = max(dp[0][j],dp[1][j - 1]) + a[1][j];
		// printf("dp[%d][%d] = %d\n",1,j,dp[1][j]);
	}
	printf("%d\n",dp[1][n - 1]);
	return 0;
}