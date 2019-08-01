#include <iostream>
using namespace std;
const int maxn = 505;
int c[maxn],dp[maxn][maxn][maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= n; ++i)
	{
		cin>>c[i];
	}
	dp[0][0][0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 0;j <= k; ++j)
		{
			for(int p = j;p <= k; ++p)
			{
				if(dp[i - 1][j][p])
				{
					if(p + c[i] <= k)
					{
						dp[i][j][p + c[i]] = 1;
						dp[i][j + c[i]][p + c[i]] = 1;
					}
					dp[i][j][p] = 1;
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0;i <= k; ++i)
	{
		if(dp[n][i][k])
		{
			sum++;
		}
	}
	printf("%d\n",sum);
	for(int i = 0;i <= k; ++i)
	{
		if(dp[n][i][k])
		{
			printf("%d ",i);
		}
	}
	cout<<endl;
	return 0;
}