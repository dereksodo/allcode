#include <iostream>
using namespace std;
int dp[505][505],n,w[505],K,cnt;
int main()
{
	cin>>n>>K;
	for(int i = 1;i <= n; ++i)
	{
		cin>>w[i];
	}
	dp[0][0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = K - w[i];j >= 0; --j)
		{
			for(int k = 0;k <= j; ++k)
			{
				dp[j + w[i]][k + w[i]] |= dp[j][k];
				dp[j + w[i]][k] |= dp[j][k];
			}
		}
	}
	for(int i = 0;i <= K; ++i)
	{
		if(dp[K][i])
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for(int i = 0;i <= K; ++i)
	{
		if(dp[K][i])
		{
			printf("%d ",i);
		}
	}
	cout<<endl;
	return 0;
}