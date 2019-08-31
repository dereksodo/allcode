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
const int maxn = 15005;
const int maxm = 105;
int dp[maxn];
pair<int,int> a[maxm];
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d%d",&m,&n))
	{
		memset(dp,0x00,sizeof(dp));
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d%d",&a[i].first,&a[i].second);
		}
		if(m > 1800)
		{
			m += 200;
		}
		// printf("m = %d\n",m);
		for(int i = 1;i <= n; ++i)
		{
			for(int j = m;j >= a[i].first; --j)
			{
				dp[j] = max(dp[j],dp[j - a[i].first] + a[i].second);
			}
		}
		int k = m;
		while(k >= 1 && dp[k] == dp[k - 1])
		{
			// printf("dp[%d] = %d,dp[%d] = %d\n",k,dp[k],k - 1,dp[k - 1]);
			--k;
		}
		if(k < 2000 && m > 2000)
		{
			m -= 200;
		}
		// printf("m = %d\n",m);
		cout<<dp[m]<<endl;
	}
	return 0;
}