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
	#define debug prllf
#else
	#define debug(...)
#endif
ll a[105];
int main(int argc, char const *argv[])
{
	ll q;
	cin>>q;
	while(q--)
	{
		memset(a,0x00,sizeof(a));
		ll n,k;
		cin>>n>>k;
		ll minvalue = 1e9;
		ll maxvalue = 0;
		for(ll i = 0;i < n; ++i)
		{
			scanf("%lld",&a[i]);
			minvalue = min(minvalue,a[i]);
			maxvalue = max(maxvalue,a[i]);
		}
		if(maxvalue - minvalue > 2 * k)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",minvalue + k);
		}
	}
	return 0;
}