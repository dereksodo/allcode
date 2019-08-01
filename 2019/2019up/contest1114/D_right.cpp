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
const int inf = 0x3f3f3f3f;
const int maxn = 5005;
int dp[maxn][maxn];//dp[l][r]:从i到j改编成一种颜色的最小花费
int c[maxn],l[maxn],r[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&c[i]);
	}
	l[1] = 1;
	r[n] = n;
	for(int i = 2;i <= n; ++i)//如果左边有一样颜色的，那么这两条在合并时可以到一条
	{
		if(c[i] == c[i - 1])
		{
			l[i] = l[i - 1];
		}
		else
		{
			l[i] = i;
		}
	}
	for(int i = n - 1;i >= 1; --i)//右边一样
	{
		if(c[i] == c[i + 1])
		{
			r[i] = r[i + 1];
		}
		else
		{
			r[i] = i;
		}
	}
	memset(dp,inf,sizeof(dp));
	for(int i = 1;i <= n; ++i)
	{
		dp[l[i]][r[i]] = 0;//从一个左边到右边不需要代价
	}
	for(int len = 1;len < n; ++len)
	{
		for(int i = 1,j = len;j <= n; ++i,++j)//枚举左边到右边(i->j),长度为len的
		{
			if(i > 1 && j < n && c[i - 1] == c[j + 1])
			{
				dp[l[i - 1]][r[j + 1]] = min(dp[l[i - 1]][r[j + 1]],dp[i][j] + 1);
			}
			if(i > 1)
			{
				dp[l[i - 1]][j] = min(dp[l[i - 1]][j],dp[i][j] + 1);
			}
			if(j < n)
			{
				dp[i][r[j + 1]] = min(dp[i][r[j + 1]],dp[i][j] + 1);
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}