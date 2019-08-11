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
int dp[45][45][45][45];
int cnt[5];
int a[400];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= m; ++i)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	dp[0][0][0][0] = a[1];
	for(int i = 0;i <= cnt[1]; ++i)
	{
		for(int j = 0;j <= cnt[2]; ++j)
		{
			for(int k = 0;k <= cnt[3]; ++k)
			{
				for(int l = 0;l <= cnt[4]; ++l)
				{
					if(i + j + k + l == 0)
					{
						continue;
					}
					int pos = i + j * 2 + k * 3 + l * 4;
					if(i)
					{
						dp[i][j][k][l] = max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[pos + 1]);
					}
					if(j)
					{
						dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[pos + 1]);
					}
					if(k)
					{
						dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[pos + 1]);
					}
					if(l)
					{
						dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[pos + 1]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
	return 0;
}