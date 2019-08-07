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
int v[35];
int dp[20005];
int main(int argc, char const *argv[])
{
	int maxv,n;
	cin>>maxv>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&v[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = maxv;j >= v[i]; --j)
		{
			dp[j] = max(dp[j],dp[j - v[i]] + v[i]);
		}
	}
	printf("%d\n",maxv - dp[maxv]);
	return 0;
}