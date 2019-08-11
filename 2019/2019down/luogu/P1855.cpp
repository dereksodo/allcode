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
int dp[205][205];
int money[205];
int t[205];
int main(int argc, char const *argv[])
{
	int M,T,n;
	cin>>n>>M>>T;
	for(int i = 1;i <= n; ++i)
	{
		cin>>money[i]>>t[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = M;j >= money[i]; --j)
		{
			for(int k = T;k >= t[i]; --k)
			{
				dp[j][k] = max(dp[j][k],dp[j - money[i]][k - t[i]] + 1);
			}
		}
	}
	printf("%d\n",dp[M][T]);
	return 0;
}