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
const int maxbit = 35;
const int maxn = 1e5 + 5;
ll a[maxn],c[maxbit];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 1;i <= n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		for(ll j = 0;j < 30; ++j)
		{
			if(x & (1 << j))
			{
				a[++c[j]] += (1 << j);
			}
		}
	}
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		ans += a[i] * a[i];
	}
	cout<<ans<<endl;
	return 0;
}