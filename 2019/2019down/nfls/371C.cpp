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
struct ham{
	ll x,y,z;
	void input()
	{
		scanf("%lld%lld%lld",&x,&y,&z);
	}
}h,has,shop,cur;
ll res;
int check(ll mid)
{
	cur.x = max(0ll,h.x * mid - has.x);
	cur.y = max(0ll,h.y * mid - has.y);
	cur.z = max(0ll,h.z * mid - has.z);
	return (shop.x * cur.x + shop.y * cur.y + shop.z * cur.z) <= res;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	h.x = h.y = h.z = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'B')
		{
			h.x++;
		}
		else if(s[i] == 'S')
		{
			h.y++;
		}
		else
		{
			h.z++;
		}
	}
	has.input();
	shop.input();
	cin>>res;
	ll l = 0,r = 1e15,ans = 0;
	while(l <= r)
	{
		ll mid = l + r >> 1;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}