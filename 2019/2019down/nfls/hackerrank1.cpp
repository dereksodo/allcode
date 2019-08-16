//https://www.hackerrank.com/challenges/sherlock-and-probability
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
const ll maxn = 1e5 + 5;
ll a[maxn],s[maxn];
ll gcd(ll c,ll d)
{
	return d == 0 ? c : gcd(d,c % d);
}
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i = 1;i <= n; ++i)
		{
			scanf("%01lld",&a[i]);
			s[i] = s[i - 1] + a[i];
		}
		++k;
		ll ans = 0ll;
		for(int i = 1;i <= n; ++i)
		{
			if(a[i])
			{
				ans += s[min(i + k - 1,n)] - s[max(1ll,i - k + 1) - 1];
			}
		}
		ll res = gcd(ans,n * n);
		ans /= res;
		ll p = n * n / res;
		printf("%lld/%lld\n",ans,p);
	}
	return 0;
}