#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const int maxn = 10005;
ll jiecheng(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return n * jiecheng(n - 1);
}
int main()
{	
	int n,k;
	cin>>n>>k;
	if(n < k || n > 50 || k > 50)
	{
		printf("0\n");
		return 0;
	}
	k = min(k,n - k);
	printf("jiecheng::%llu\n",jiecheng(n) / jiecheng(k) / jiecheng(n - k));
	ll dp[n + 1][k + 1];
	memset(dp,0x00,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 0;j <= k; ++j)
		{
			if(!j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	printf("dp::%llu\n",dp[n][k]);
	return 0;
}