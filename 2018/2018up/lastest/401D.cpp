#include <iostream>
#include <cstring>
using namespace std;
long long dp[(1 << 18)][100];
int cnt[11],a[11];
string s;
int m;
int main()
{
	cin>>s;
	cin>>m;
	memset(cnt,0x00,sizeof(cnt));
	memset(a,0x00,sizeof(a));
	memset(dp,0x00,sizeof(dp));
	for(int i = 0;i < s.size(); ++i)
	{
		cnt[s[i] - '0']++;
	}
	for (int i = 1; i < 11; ++i)
	{
		a[i] = a[i - 1] + cnt[i - 1];
	}
	for(int i = 1;i < 10; ++i)
	{
		if(cnt[i])
		{
			dp[(1 << a[i])][i % m] = 1;
		}
	}
	for(int i = 1;i < (1 << (int)s.size()); ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(dp[i][j])
			{
				for(int k = 0;k <= 9; ++k)
				{
					for(int p = a[k];p < a[k + 1]; ++p)
					{
						if(i & (1 << p))
						{
							continue;
						}
						dp[i + (1 << p)][(j * 10 + k) % m] += dp[i][j];
						break;
					}
				}
			}
		}
	}
	printf("%lld\n",dp[(1 << (int)s.size()) - 1][0]);
	return 0;
}