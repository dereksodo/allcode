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
string s1,s2;
int a[maxn],b[maxn];
const int tab[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>s1>>m>>s2;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			dp[i][j] = -0x3f3f3f3f;
		}
	}
	for(int i = 0;i < n; ++i)
	{
		if(s1[i] == 'A')
		{
			a[i + 1] = 0;
		}
		if(s1[i] == 'C')
		{
			a[i + 1] = 1;
		}
		if(s1[i] == 'G')
		{
			a[i + 1] = 2;
		}
		if(s1[i] == 'T')
		{
			a[i + 1] = 3;
		}
	}
	for(int i = 0;i < m; ++i)
	{
		if(s2[i] == 'A')
		{
			b[i + 1] = 0;
		}
		if(s2[i] == 'C')
		{
			b[i + 1] = 1;
		}
		if(s2[i] == 'G')
		{
			b[i + 1] = 2;
		}
		if(s2[i] == 'T')
		{
			b[i + 1] = 3;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		dp[i][0] = dp[i - 1][0] + tab[a[i]][4];
	}
	for(int j = 1;j <= m; ++j)
	{
		dp[0][j] = dp[0][j - 1] + tab[b[j]][4];
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			dp[i][j] = max(dp[i][j],dp[i][j - 1] + tab[b[j]][4]);
			dp[i][j] = max(dp[i][j],dp[i - 1][j] + tab[a[i]][4]);
			dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + tab[a[i]][b[j]]);
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}