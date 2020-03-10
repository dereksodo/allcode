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
const int maxn = 100005;
const int mod = 5000011;
int sum[maxn],dp[maxn];
int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d%d",&n,&k);
	sum[0] = dp[0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		if(i > k)
		{
			dp[i] = sum[i - k - 1];
		}
		else
		{
			dp[i] = 1;
		}
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
	printf("%d\n",sum[n]);
	return 0;
}