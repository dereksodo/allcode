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
ll n,b;
ll calc(ll v)
{
	ll n2 = n;
	ll res = 0;
	while(n2 >= v)
	{
		res += n2 / v;
		n2 /= v;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	cin>>n>>b;
	ll ans = 1e18;
	for(ll i = 2;i * i <= b; ++i)
	{
		if(b % i == 0)
		{
			int cnt = 0;
			while(b % i == 0)
			{
				b /= i;
				cnt++;
			}
			debug("i = %d,clac = %d\n",i,calc(i));
			ans = min(ans,calc(i) / cnt);
		}
	}
	if(b != 1)
	{
		ans = min(ans,calc(b));
	}
	cout<<ans<<endl;
	return 0;
}