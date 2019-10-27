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
const int inf = 0x3f3f3f3f;
char c[maxn];
int a[maxn];
int dp[maxn][maxn];
int dfs(int l,int r)
{
	if(dp[l][r] != -inf)
	{
		// printf("dp[%d][%d] = %d\n",l,r,dp[l][r]);
		// printf("%d\n",-inf);
		return dp[l][r];
	}
	if(l == r)
	{
		return dp[l][l] = a[l];
	}
	int ret = -inf;
	for(int i = l;i < r; ++i)
	{
		int pre = dfs(l,i);
		int last = dfs(i + 1,r);
		if(c[i] == '*')
		{
			ret = max(ret,pre * last);
		}
		else
		{
			ret = max(ret,pre + last);
		}
	}
	// printf("the max from %d to %d is %d\n",l,r,ret);
	return dp[l][r] = ret;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	getchar();
	for(int i = 1;i <= 2 * n - 1; ++i)
	{
		if(i & 1)
		{
			scanf("%d",&a[i / 2 + 1]);
			if(i != 2 * n - 1)
			{
				getchar();
			}
		}
		else
		{
			scanf("%c",&c[i / 2]);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			dp[i][j] = -inf;
		}
	}
	printf("%d\n",dfs(1,n));
	return 0;
}