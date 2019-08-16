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
map<ll,int> mp;
int main(int argc, char const *argv[])
{
	ll n,a,b,x;
	while(scanf("%lld%lld%lld",&n,&a,&b) && n)
	{
		mp.clear();
		x = 0;
		ll ans = n;
		while(mp[x] != 3)
		{
			ll res = x * x;
			res %= n;
			res *= a;
			res %= n;
			res += b;
			res %= n;
			mp[res]++;
			x = res;
			if(mp[x] == 2)
			{
				ans--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}