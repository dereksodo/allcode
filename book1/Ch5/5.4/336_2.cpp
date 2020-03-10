#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
#define check(x) ((x & (x << 1)) || (x & (x << 2)))
const int maxn = 1 << 10;
int n,m,ans;
int dp[maxn][maxn][3];
int a[105],sum[maxn];
int getsum(int s)
{
	int ret = 0;
	while(s)
	{
		if(s & 1)
		{
			++ret;
		}
		s >>= 1;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	char x;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			cin>>x;
			a[i] = (a[i] << 1) + (x == 'H');
		}
	}
	for(int i = 0;i < (1 << m); ++i)
	{
		sum[i] = getsum(i);
	}
	for(int l = 0;l < (1 << m); ++l)
	{
		if(!((l & a[0]) || check(l)))
		{
			dp[0][l][0] = sum[l];
		}
	}
	for(int l = 0;l < (1 << m); ++l)
	{
		for(int r = 0;r < (1 << m); ++r)
		{
			if((l & r) || (l & a[0]) || (r & a[1]) || check(l) || check(r))
			{
				continue;
			}
			dp[l][r][1] = sum[l] + sum[r];
		}
	}
	for(int i = 2;i < n; ++i)
	{
		for(int l = 0;l < (1 << m); ++l)
		{
			if((l & a[i - 1]) || check(l))
			{
				continue;
			}
			for(int r = 0;r < (1 << m); ++r)
			{
				if((r & a[i]) || (l & r) || check(r))
				{
					continue;
				}
				for(int ll = 0;ll < (1 << m); ++ll)//second col before
				{
					if((ll & l) || (ll & r) || (ll & a[i - 2]) || check(ll))
					{
						continue;
					}
					dp[l][r][i % 3] = max(dp[l][r][i % 3],dp[ll][l][(i - 1 + 3) % 3] + sum[r]);
				}
			}
		}
	}
	for(int l = 0;l < (1 << m); ++l)
	{
		for(int r = 0;r < (1 << m); ++r)
		{
			ans = max(ans,dp[l][r][(n - 1 + 3) % 3]);
		}
	}
	printf("%d\n",ans);
	return 0;
}