#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int value[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	int f,v;
	cin>>f>>v;
	for(int i = 0;i < f; ++i)
	{
		for(int j = 0;j < v; ++j)
		{
			cin>>value[i][j];
		}
	}
	for(int i = 1;i < v; ++i)
	{
		if(dp[0][i - 1] > value[0][i])
		{
			dp[0][i] = dp[0][i - 1];
		}
		else
		{
			dp[0][i] = value[0][i];
		}
	}
	for(int i = 1;i < f; ++i)
	{
		dp[i][i] = dp[i - 1][i - 1] + value[i][i];
	}
	for(int i = 1;i < f; ++i)
	{
		for(int j = i + 1;j <= v; ++j)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + value[i][j],dp[i][j - 1]);
		}
	}
	printf("%d\n",dp[f - 1][v - 1]);
	return 0;
}