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
const int maxn = 105;
ll a[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",a + i);
	}
	ll ans = 1e18;
	for(int i = 1;i <= n; ++i)
	{
		ll now = 0;
		for(int j = 1;j <= n; ++j)
		{
			now += abs(a[i] - a[j]) & 1;
		}
		ans = min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}