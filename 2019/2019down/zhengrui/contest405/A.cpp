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
int main(int argc, char const *argv[])
{
	ll n,l,w,x,y,a;
	cin>>n>>l>>w>>x>>y>>a;
	ll maxp = w / a;
	ll ans = -1;
	for(ll i = 1;i <= maxp; ++i)
	{
		ll now = ((w - a * i) / y) * (l / x);
		if(now >= n)
		{
			ll maxi = (w - i * a) / y;
			maxi = min(maxi,2 * i);
			ans = max(ans,maxi * (l / x));
		}
		else
		{
			break;
		}
	}
	printf("%lld\n",min(n,ans));
	return 0;
}