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
int dp1[maxn],dp2[maxn],a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 0;j < i; ++j)
		{
			if(a[i] > a[j])
			{
				dp1[i] = max(dp1[i],dp1[j] + 1);
			}
		}
	}
	for(int i = n;i > 0; --i)
	{
		for(int j = n + 1;j > i; --j)
		{
			if(a[i] > a[j])
			{
				dp2[i] = max(dp2[i],dp2[j] + 1);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans = max(ans,dp1[i] + dp2[i] - 1);
	}
	printf("%d\n",n - ans);
	return 0;
}