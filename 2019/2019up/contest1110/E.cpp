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
ll a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
	priority_queue<ll> d1,d2;
	ll n;
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
		if(i)
		{
			d1.push(a[i] - a[i - 1]);
		}
	}
	for(ll j = 0;j < n; ++j)
	{
		scanf("%d",b + j);
		if(j)
		{
			d2.push(b[j] - b[j - 1]);
		}
	}
	if(a[0] != b[0])
	{
		printf("No\n");
		return 0;
	}
	while(!d1.empty())
	{
		ll p1 = d1.top(),p2 = d2.top();
		if(p1 != p2)
		{
			printf("No\n");
			return 0;
		}
		d1.pop();
		d2.pop();
	}
	printf("Yes\n");
	return 0;
}