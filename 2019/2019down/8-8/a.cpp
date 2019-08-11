//timus1221
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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int dp[505][505][10];
int a[505][505];
int get(int i,int i2,int minx)//need to be done
{
	if(i2 > i)
	{
		return (i + minx - i2) + 1;
	}
	else
	{
		return (i2 - i + minx) + 1;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n)
	{
		memset(dp,0x00,sizeof(dp));
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				scanf("%d",&a[i][j]);
				a[i][j] = 1 - a[i][j];
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				if(a[i][j])
				{
					dp[i][j][1] = dp[i - 1][j][1] + 1;
				}
			}
		}
		for(int i = n;i >= 1; --i)
		{
			for(int j = 1;j <= n; ++j)
			{
				if(a[i][j])
				{
					dp[i][j][2] = dp[i + 1][j][2] + 1;
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				if(a[i][j])
				{
					dp[i][j][3] = dp[i][j - 1][3] + 1;
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			for(int j = n;j >= 1; --j)
			{
				if(a[i][j])
				{
					dp[i][j][4] = dp[i][j + 1][4] + 1;
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				for(int k = 1;k <= 4; ++k)
				{
					debug("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
				}
			}
		}
		int ans = 0;
		for(int i = 2;i <= n - 1; ++i)
		{
			for(int j = 2;j <= n - 1; ++j)
			{
				if(!a[i][j])
				{
					continue;
				}
				int minx = min(min(dp[i][j][1],dp[i][j][2]),min(dp[i][j][3],dp[i][j][4])) - 1;
				debug("i = %d,j = %d,minx = %d\n",i,j,minx);
				if(minx * 2 + 1 <= ans)
				{
					continue;
				}
				int flag = 0;
				for(int i2 = i - minx;i2 <= i + minx; ++i2)
				{
					if(i2 == i)
					{
						if((dp[i2][j][3] < get(i,i2,minx))
						    || (dp[i2][j][4] < get(i,i2,minx)))
						{
							debug("no\n");
							flag = 1;
							break;
						}
						continue;
					}
					debug("i2 = %d,j = %d\n",i2,j);
					debug("%d\n",get(i,i2,minx));
					debug("dp[3] = %d,dp[4] = %d\n",dp[i2][j][3],dp[i2][j][4]);
					if((dp[i2][j][3] != get(i,i2,minx))
						|| (dp[i2][j][4] != get(i,i2,minx)))
					{
						debug("no\n");
						flag = 1;
						break;
					}
				}
				if(flag)
				{
					continue;
				}
				for(int j2 = j - minx;j2 <= j + minx; ++j2)
				{
					if(j2 == j)
					{
						if((dp[i][j2][1] < get(j,j2,minx))
							|| (dp[i][j2][2] < get(j,j2,minx)))
						{
							flag = 1;
							break;
						}
						continue;
					}
					debug("i = %d,j2 = %d\n",i,j2);
					debug("%d\n",get(j,j2,minx));
					if((dp[i][j2][1] != get(j,j2,minx))
						 || (dp[i][j2][2] != get(j,j2,minx)))
					{
						flag = 1;
						break;
					}
				}
				if(!flag)
				{
					ans = max(ans,minx * 2 + 1);
				}
			}
		}
		if(ans < 3)
		{
			printf("No solution\n");
		}
		else
		{
			printf("%d\n",ans);
		}
		// fflush(stdout);
	}
	return 0;
}
/*
6
1 1 0 1 1 0
1 0 0 0 1 1
0 0 0 0 0 0 
1 0 0 0 1 1
1 1 0 1 1 1
0 1 1 1 1 1
ans:5
4
1 0 0 1
0 0 0 0
0 0 0 0
1 0 0 1
ans:No solution
10
1 1 1 1 0 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 0 0 0 1 1 1 1
1 1 0 0 0 0 0 1 1 1
1 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
1 1 0 0 0 0 0 1 1 1
1 1 1 0 0 0 1 1 1 1
1 1 1 1 0 1 1 1 1 1
ans:9
*/