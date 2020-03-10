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
const int maxn = 60;
int dp[maxn][maxn * 1000];
int t,n;
int dfs(int a,int b)
{
	if(a == 0)
	{
		return b & 1;
	}
	if(b == 1)
	{
		return dfs(a + 1,0);
	}
	if(~dp[a][b])
	{
		return dp[a][b];
	}
	if(a && !dfs(a - 1,b))
	{
		return dp[a][b] = 1;
	}
	if(a && b && !dfs(a - 1,b + 1))
	{
		return dp[a][b] = 1;
	}
	if(a >= 2 && !dfs(a - 2,b + 2 + (b ? 1 : 0)))
	{
		return dp[a][b] = 1;
	}
	if(b && !dfs(a,b - 1))
	{
		return dp[a][b] = 1;
	}
	return dp[a][b] = 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%d",&n);
		int x,a = 0,b = -1;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&x);
			if(x == 1)
			{
				++a;
			}
			else
			{
				b += x + 1;
			}
		}
		b = max(b,0);
		printf("%s\n",dfs(a,b) ? "YES" : "NO");
	}
	return 0;
}