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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 2e5 + 5;
ll odd[maxn],even[maxn],n,a[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		if(i % 2)
		{
			odd[i] = a[i] + odd[i - 1];
			even[i] = even[i - 1];
		}
		else
		{
			even[i] = a[i] + even[i - 1];
			odd[i] = odd[i - 1];
		}
	}
	for(ll i = 1;i <= n; ++i)
	{
		debug("even[%d] = %d,odd[%d] = %d\n",i,even[i],i,odd[i]);
	}
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		ll ODD = odd[i - 1];
		ll EVEN = even[i - 1];
		ODD += even[n] - even[i];
		EVEN += odd[n] - odd[i];
		debug("delete %d,odd = %d,even = %d\n",i,ODD,EVEN);
		if(ODD == EVEN)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}