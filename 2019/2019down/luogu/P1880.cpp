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
const int maxn = 305;
int n;
int a[maxn];
int dp1[maxn][maxn],dp2[maxn][maxn],s[maxn];
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		a[i + n] = a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		s[i + n] = s[i + n - 1] + a[i];
	}
	for(int p = 1;p < n; ++p)
	{
		for(int i = 1,j = i + p;(j < n * 2) && (i < n * 2); ++i,++j)
		{
			dp2[i][j] = 0x3f3f3f3f;
			for(int k = i;k < j; ++k)
			{
				dp1[i][j] = max(dp1[i][j],dp1[i][k] + dp1[k + 1][j] + s[j] - s[i - 1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}
	int ans1 = 0,ans2 = 0x3f3f3f3f;
	for(int i = 1;i <= n; ++i)
	{
		ans1 = max(ans1,dp1[i][i + n - 1]);
		ans2 = min(ans2,dp2[i][i + n - 1]);
	}
	printf("%d\n%d\n",ans2,ans1);
	return 0;
}