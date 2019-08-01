#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 2005;
const ll mod = (1ll << 31) - 1;
ll a[maxn];
ll dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	ll n;
	while(cin>>n)
	{
		memset(a,0x00,sizeof(a));
		memset(dp,0x00,sizeof(dp));
		for(ll i = 1;i <= n + 1; ++i)
		{
			scanf("%lld",&a[i]);
		}
		dp[2][1] = 1;
		for(ll i = 3;i <= n + 1; ++i)
		{
			for(ll j = 1;j <= i - 2; ++j)
			{
				if((a[i - 1] - a[j]) * (a[i] - a[j]) > 0)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			for(ll j = 1;j <= i - 2; ++j)
			{
				if((a[i] - a[i - 1]) * (a[j] - a[i - 1]) > 0)
				{
					dp[i][i - 1] = (dp[i][i - 1] + dp[i - 1][j]) % mod;
				}
			}
		}
		ll ans = 0;
		for(int i = 1;i <= n; ++i)
		{
			ans = (ans + dp[n + 1][i]) % mod;
		}
		printf("%lld\n",ans);
	}

	return 0;
}