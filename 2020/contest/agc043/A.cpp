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
const int maxn = 105;
char mp[maxn][maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",mp[i] + 1);
	}
	for(int i = 0;i < maxn; ++i)
	{
		dp[i][0] = dp[0][i] = 0x3f3f3f3f;
	}
	dp[1][0] = dp[0][1] = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(mp[i][j] == '#')
			{
				dp[i][j] = min(dp[i - 1][j] + (mp[i][j] != mp[i - 1][j]),dp[i][j - 1] + (mp[i][j] != mp[i][j - 1]));
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]);
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}