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
const int maxn = 1005;
int dp[2][(maxn << 4)];
int mp[maxn];
void add(int index,int val)
{
	for(int i = val;i < (maxn << 4); ++i)
	{
		dp[index][i] = min(dp[index][i],dp[index][i - val] + 1);
	}
}
int main(int argc, char const *argv[])
{
	int k,n,m;
	cin>>k>>n>>m;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = dp[1][0] = 0;
	for(int i = 1;i <= k; ++i)
	{
		int x;
		scanf("%d",&x);
		mp[x] = 1;
	}
	for(int i = 0;i <= m; ++i)
	{
		if(mp[i])
		{
			if(i < n)
			{
				add(0,n - i);
			}
			else if(i > n)
			{
				add(1,i - n);
			}
			else
			{
				printf("1\n");
				return 0;
			}
		}
	}
	int ans = INT_MAX;
	for(int i = 1;i < (maxn << 4); ++i)
	{
		ans = min(ans,dp[0][i] + dp[1][i]);
	}
	if(ans >= maxn)
	{
		ans = -1;
	}
	printf("%d\n",ans);
	return 0;
}