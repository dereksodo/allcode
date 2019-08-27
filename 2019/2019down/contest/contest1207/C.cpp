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
const ll inf = 1e18;
const ll maxn = 2e5 + 5;
ll dp[2][2];
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,a,b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		s = s + "0";
		ll e = 0;
		dp[e][0] = b;
		dp[e][1] = inf;
		// printf("%lld %lld\n",dp[e][0],dp[e][1]);
		for(int i = 1;i < s.size(); ++i)
		{
			e = 1 - e;
			if(s[i] == '1' || s[i - 1] == '1')
			{
				dp[e][0] = inf;
			}
			else
			{
				dp[e][0] = min(dp[1 - e][0],dp[1 - e][1] + a) + b + a;
			}
			dp[e][1] = min(dp[1 - e][1],dp[1 - e][0] + a) + a + 2 * b;
			// printf("%lld %lld\n",dp[e][0],dp[e][1]);
		}
		printf("%lld\n",dp[e][0]);
	}
	return 0;
}