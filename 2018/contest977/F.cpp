#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int dp[maxn];
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i = 1;i < n; ++i)
	{
		dp[i] = 1;
		if(dp[i - 1] + 1 > dp[i])
		{
			dp[i] = max(dp[i - 1] + 1,dp[i]);
		}
	}
	int ans = 0,ans_pos = 0;
	for(int i = 0;i < n; ++i)
	{
		if(dp[i] > ans)
		{
			ans = dp[i];
			ans_pos = i;
		}
	}
	printf("%d\n",dp[n - 1]);
	int cnt = ans_pos - ans + 1;
	for(int i = 0;i < n; ++i)
	{
		if(a[i] == cnt)
		{
			printf("%d ",i + 1);
			cnt++;
		}
		if(cnt > ans_pos)
		{
			break;
		}
	}
	return 0;
}