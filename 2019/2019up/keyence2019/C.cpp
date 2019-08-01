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
ll a[maxn],b[maxn],sum1,sum2;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
		sum1 += a[i];
	}
	for(ll i = 0;i < n; ++i)
	{
		scanf("%lld",&b[i]);
		sum2 += b[i];
	}
	if(sum1 < sum2)
	{
		printf("-1\n");
		return 0;
	}
	ll sum = sum1 - sum2;
	priority_queue< ll,vector<int>,greater<int> > v; 
	ll ans = 0;
	ll ret = 0;
	for(ll i = 0;i < n; ++i)
	{
		if(a[i] < b[i])
		{
			ret++;
		}
		else
		{
			v.push(a[i] - b[i]);
		}
	}
	ll p = n - ret;
	while(!v.empty() && sum >= 0)
	{
		ll x = v.top();
		v.pop();
		// printf("x = %lld\n",x);
		if(sum >= x)
		{
			sum -= x;
			ans++;
		}
		else
		{
			break;
		}
	}//p - ans
	printf("%lld\n",ret + p - ans);
	return 0;
}