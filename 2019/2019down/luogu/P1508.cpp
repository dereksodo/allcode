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
int a[250][250],dp[250][250];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	memset(a,-0x3f3f3f3f,sizeof(a));
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			dp[i][j] = max(dp[i - 1][j],max(dp[i - 1][j + 1],dp[i - 1][j - 1])) + a[i][j];
		}
	}
	printf("%d\n",max(max(dp[n][(m + 1) / 2],dp[n][(m - 1) / 2]),dp[n][(m + 3) / 2]));
	return 0;
}