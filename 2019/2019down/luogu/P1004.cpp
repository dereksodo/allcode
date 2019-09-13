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
const int maxn = 15;
int dp[maxn][maxn][maxn][maxn];
int a[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int x,y,z;
	while(cin>>x>>y>>z && (x + y + z))
	{
		a[x][y] = z;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			for(int k = 1;k <= n; ++k)
			{
				for(int l = 1;l <= n; ++l)
				{
					dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l],dp[i - 1][j][k][l - 1]),max(dp[i][j - 1][k][l - 1],dp[i][j - 1][k - 1][l])) + a[i][j] + a[k][l];
					if(i == k && j == l)
					{
						dp[i][j][k][l] -= a[i][j];
					}
				}
			}
		}
	}
	printf("%d\n",dp[n][n][n][n]);
	return 0;
}