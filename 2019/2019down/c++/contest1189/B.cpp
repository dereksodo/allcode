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
vector<ll> v;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	v.clear();
	for(ll i = 0;i < n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	if(v[n - 1] >= v[n - 3] + v[n - 2])
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		printf("%lld %lld",v[n - 2],v[n - 1]);
		for(int i = n - 3;i >= 0; --i)
		{
			printf(" %lld",v[i]);
		}
		printf("\n");
	}
	return 0;
}