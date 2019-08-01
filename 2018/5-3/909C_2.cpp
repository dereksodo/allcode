#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	int cnt = 0;
	for(int cur = 0;cur < n; ++cur)
	{
		string s;
		cin>>s;
		if(s == "s")
		{
			vector<int> sum(n + 2);
			for(int x = n;x >= 0; --x)
			{
				sum[x] = (sum[x + 1] + dp[x]) % mod;
			}
			for(int x = 0;x <= n; ++x)
			{
				printf("sum[%d] = %d\n",x,sum[x]);
			}
			for(int x = 0;x <= n; ++x)
			{
				dp[x] = 0;
			}
			for(int x = 0;x <= n; ++x)
			{
				if(x + cnt <= n)
				{
					dp[x + cnt] = sum[x];
				}
			}
			for(int x = 0;x <= n; ++x)
			{
				printf("dp[%d] = %d\n",x,dp[x]);
			}
			cnt = 0;
		}
		else
		{
			cnt++;
		}
	}
	int ans = 0;
	for(int x = 0;x <= n; ++x)
	{
		ans = (ans + dp[x]) % mod;
	}
	printf("%d\n",ans);
	return 0;
}