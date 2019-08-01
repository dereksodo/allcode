//题目大意：给你n个整数，必须要在两个数之间填上'+'或'-',要使结果mod 7余m,有多少种填法
#include <iostream>
using namespace std;
const int maxn = 1005;
int a[maxn];
int dp[maxn][10];
int main()
{
	int n,m;
	cin>>n>>m;
	m %= 7;
	if(m == 0)
	{
		m = 7;
	}
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	memset(dp,0x00,sizeof(dp));
	dp[1][0] = 1;
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= m; ++j)
		{
			dp[i][j] += dp[i - 1][(j + a[i]) % m];
			dp[i][j] += dp[i - 1][max(0,((j - a[i]) % m))];
		}
	}
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= m; ++j)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",dp[n][m]);
	return 0;
}