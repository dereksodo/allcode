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
const ll maxn = 1e5 + 5;
ll n,k,m,sum[maxn],a[maxn];
ll up,down;
int main(int argc, char const *argv[])
{
	up = 0;
	down = 1;
	cin>>n>>k>>m;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	for(ll i = 1;i < n; ++i)
	{
		ll now = sum[n] - sum[i];
		//(now + min(m - i,(n - i) * k))
		//------------------------------
		//			n - i
		// printf("i = %d\n",i);
		if((now + min(m - i,(n - i) * k)) * down > (n - i) * up)
		{
			up = (now + min(m - i,(n - i) * k));
			down = n - i;
		}
		// printf("up = %lld,down = %lld\n",up,down);
		// printf("%.20lf\n",(up + 0.0) / down);
	}
	printf("%.20lf\n",(up + 0.0) / down);
	return 0;
}