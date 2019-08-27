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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll cnt1,cnt2,cnt0;
	cnt1 = cnt2 = cnt0 = 0;
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		if(x == 0ll)
		{
			cnt0++;
			continue;
		}
		ll min1 = abs(x - 1);
		ll min2 = abs(x + 1);
		if(min1 < min2)
		{
			cnt1++;
			ans += min1;
		}
		else
		{
			cnt2++;
			ans += min2;
		}
	}
	if(cnt0)
	{
		printf("%lld\n",ans + cnt0);
	}
	else
	{
		if(cnt2 & 1)
		{
			ans++;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}