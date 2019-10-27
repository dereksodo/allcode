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
using namespace std;
const int mod = 987654321;
const int maxn = 1000005;
int vis[maxn],prime[maxn],plen;
int dp[1010];
void init()
{
	vis[1] = 1;
	for(int i = 2;i < maxn; ++i)
	{
		if(!vis[i])
		{
			prime[++plen] = i;
		}
		for(int j = 1;j <= plen && i * prime[j] < maxn; ++j)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int a[1010],s[1010];
int main(int argc, char const *argv[])
{
	init();
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		s[i] = s[i - 1] + a[i];
	}
	dp[n + 1] = 1;
	dp[n] = !vis[a[n]];
	for(int i = n - 1;i >= 1; --i)
	{
		for(int j = i;j <= n; ++j)
		{
			if(!vis[s[j] - s[i - 1]])
			{
				dp[i] += dp[j + 1];
				dp[i] %= mod;
			}
		}
//		printf("dp[%d] = %d\n",i,dp[i]);
	}
	cout<<dp[1]<<endl;
	return 0;
}