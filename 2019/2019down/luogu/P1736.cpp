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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 2600;
int a[2600][2600];
int dp[2600][2600],s1[2600][2600],s2[2600][2600];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j])
			{
				s1[i][j] = s1[i][j - 1] + 1;
				s2[i][j] = s2[i - 1][j] + 1;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1],min(s1[i][j - 1],s2[i - 1][j])) + 1;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	memset(dp,0x00,sizeof(dp));
	memset(s1,0x00,sizeof(s1));
	memset(s2,0x00,sizeof(s2));
	for(int i = 1;i <= n; ++i)
	{
		for(int j = m;j >= 1; --j)
		{
			if(!a[i][j])
			{
				s1[i][j] = s1[i][j + 1] + 1;
				s2[i][j] = s2[i - 1][j] + 1;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j + 1],min(s1[i][j + 1],s2[i - 1][j])) + 1;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}