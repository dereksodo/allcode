#include <iostream>
#include <cmath>
using namespace std;
long long dp[110][65];
void solve()
{
	for(int i = 1;i <= 63; ++i)
	{
		for(int j = 1;j <= 63; ++j)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
		}
	}
}
int main()
{
	solve();
	long long n,k;
	while(~scanf("%lld%lld",&k,&n) && n && k)
	{
		cin.ignore();
		k = min(63ll,k);
		bool flag = 1;
		for(int i = 0;i <= 63; ++i)
		{
			if(dp[k][i] >= n)
			{
				printf("%d\n",i);
				flag = 0;
				break;
			}
		}
		if(!flag)
		{
			continue;
		}
		printf("More than 63 trials needed.\n");
	}
	return 0;
}