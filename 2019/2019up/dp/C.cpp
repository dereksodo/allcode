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
const ll maxn = 1e5 + 500;
ll a[maxn][3],dp[maxn][3];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	dp[1][0] = a[1][0];
	dp[1][1] = a[1][1];
	dp[1][2] = a[1][2];
	for(int i = 2;i <= n; ++i)
	{
		dp[i][0] = max(dp[i - 1][1],dp[i - 1][2]) + a[i][0];
		dp[i][1] = max(dp[i - 1][0],dp[i - 1][2]) + a[i][1];
		dp[i][2] = max(dp[i - 1][0],dp[i - 1][1]) + a[i][2];
	}
	printf("%d\n",max(max(dp[n][0],dp[n][1]),dp[n][2]));
	return 0;
}