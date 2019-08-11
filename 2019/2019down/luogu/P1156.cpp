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
const int maxn = 105;
int dp[maxn][maxn];
struct rubbish{
	int t,w,h;
	bool operator <(const rubbish &b)const
	{
		return t < b.t;
	}
}litter[maxn];
int main(int argc, char const *argv[])
{
	int D,n;
	cin>>D>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d%d",&litter[i].t,&litter[i].w,&litter[i].h);
	}
	sort(litter + 1,litter + n + 1);
	litter[0].t = litter[0].w = litter[0].h = 0;
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	dp[0][0] = 10;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 0;j <= D; ++j)
		{
			if(dp[i - 1][j] - litter[i].t + litter[i - 1].t >= 0)
			{
				dp[i][j] = max(dp[i][j],dp[i - 1][j] - litter[i].t + litter[i - 1].t + litter[i].w);
			}
			if(j >= litter[i].h && dp[i - 1][j - litter[i].h] - litter[i].t + litter[i - 1].t >= 0)
			{
				dp[i][j] = max(dp[i][j],dp[i - 1][j - litter[i].h] - litter[i].t + litter[i - 1].t);
				if(j == D)
				{
					printf("%d\n",litter[i].t);
					return 0;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= D; ++j)
		{
			ans = max(ans,dp[i][j] + litter[i].t);
		}
	}
	cout<<ans<<endl;
	return 0;
}