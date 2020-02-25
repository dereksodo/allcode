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
const int maxn = 35;
int n;
ll dp[maxn][maxn];
int root[maxn][maxn];
void print(int l,int r)
{
	if(l > r)
	{
		return;
	}
	printf("%d ",root[l][r]);
	if(l == r)
	{
		return;
	}
	print(l,root[l][r] - 1);
	print(root[l][r] + 1,r);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&dp[i][i]);
		dp[i][i - 1] = 1;
		root[i][i] = i;
	}
	for(int len = 1;len < n; ++len)
	{
		for(int i = 1;i + len <= n; ++i)
		{
			int j = i + len;
			dp[i][j] = -1;
			root[i][j] = i;
			for(int k = i;k <= j; ++k)
			{
				if(dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k])
				{
					dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
					root[i][j] = k;
				}
			}
		}
	}
	printf("%lld\n",dp[1][n]);
	print(1,n);
	printf("\n");
	return 0;
}