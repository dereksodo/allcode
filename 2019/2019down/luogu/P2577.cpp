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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
pair<int,int> a[1005];
int b[1005];
int dp[400005];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i].second,&a[i].first);
	}
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 1;i <= n; ++i)
	{
		b[i] = a[i].second + b[i - 1];
	}
	int sum = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = sum;j >= 0; --j)
		{
			dp[j + a[i].second] = min(dp[j + a[i].second],max(dp[j],a[i].first + j + a[i].second));
			dp[j] = max(dp[j],a[i].first + b[i] - j);
		}
		sum += a[i].second;
	}
	int ans = 1e9;
	for(int i = 1;i <= sum; ++i)
	{
		ans = min(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}