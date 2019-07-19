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
typedef unsigned long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 1e5 + 5;
ll minx[maxn],maxx[maxn],a[maxn];
int main(int argc, char const *argv[])
{
	ll n,q;
	cin>>n>>q;
	for(ll i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	maxx[0] = a[0];
	for(ll i = 0;i < n; ++i)
	{
		maxx[i] = max(maxx[i - 1],a[i]);
		if(maxx[i] == a[i])
		{
			minx[i - 1] = maxx[i - 1];
		}
		else
		{
			minx[i - 1] = a[i];
		}
	}
	while(q--)
	{
		ll b;
		cin>>b;
		if(b < n)
		{
			printf("%lld %lld\n",maxx[b - 1],a[b]);
		}
		else
		{
			printf("%lld %lld\n",maxx[n - 1],minx[(b - 1) % (n - 1)]);
		}
	}
	return 0;
}