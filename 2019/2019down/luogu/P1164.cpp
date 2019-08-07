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
int a[105],dp[10005];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	dp[0] = 1;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
		for(int j = m;j >= a[i]; --j)
		{
			dp[j] += dp[j - a[i]];
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}