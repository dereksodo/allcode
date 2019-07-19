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
const ll maxn = 105;
ll h[maxn];
ll n;
ll check()
{
	for(ll i = 0;i < n; ++i)
	{
		if(h[i])
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%lld",&h[i]);
	}
	ll ans = 0;
	while(check())
	{
		for(ll i = 0;i < n; ++i)
		{
			if(h[i])
			{
				for(ll j = i;j < n; ++j)
				{
					if(h[j])
					{
						h[j]--;
					}
					else
					{
						break;
					}
				}
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}