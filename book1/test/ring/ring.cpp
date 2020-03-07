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
const int maxn = 100;
ll ind[maxn],a[maxn];
ll sum[maxn];
int main(int argc, char const *argv[])
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll mx = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		mx = max(mx,a[i]);
		a[i + n] = a[i];
	}
	while(m--)
	{
		ll x;
		scanf("%lld",&x);
		--x;
		if(sum[x] != 0)
		{
			printf("%lld\n",sum[x]);
			continue;
		}
		for(int i = 1;i <= n; ++i)
		{
			ind[i] = i;
		}
		do{
			ll ret = 0;
			for(int i = 1;i <= n; ++i)
			{
				ret += a[ind[i]] * a[ind[(i + x) % n + 1]];
			}
			if(sum[x] < ret)
			{
				sum[x] = ret;
			}
		}while(next_permutation(ind + 1,ind + n + 1));
		printf("%lld\n",sum[x]);
	}
	return 0;
}