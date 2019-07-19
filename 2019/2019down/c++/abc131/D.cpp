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
const ll maxn = 2e5 + 5;
pair<ll,ll> p[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%lld%lld",&p[i].second,&p[i].first);
	}
	sort(p,p + n);
	ll now = 0;
	for(ll i = 0;i < n; ++i)
	{
		now += p[i].second;
		if(now > p[i].first)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}